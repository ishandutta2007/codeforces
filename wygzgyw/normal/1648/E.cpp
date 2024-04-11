// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
typedef long long ll;
const int maxn=(2e5)+10;
int TT,n,m;
struct node { int x,y,z,id; } E[maxn];
bool cmp(node A,node B) { return A.z<B.z; }
bool cmp2(node A,node B) { return A.id<B.id; }
vector<int> G[maxn],G2[maxn];
vector<int> V[maxn];
vector<pair<int,int> > T[maxn];
int fa[maxn],fa2[maxn],sz[maxn],fa3[maxn];
int cnt;
void link(int x,int y,int z) {
	T[x].push_back(MP(y,z));
	T[y].push_back(MP(x,z));
	cnt++;
	assert(cnt<n);
	//printf("link %d %d %d\n",x,y,z);
}
int find(int x) { return fa[x]==x?x:fa[x]=find(fa[x]); }
int find2(int x) { return fa2[x]==x?x:fa2[x]=find2(fa2[x]); }
int find3(int x) { return fa3[x]==x?x:fa3[x]=find3(fa3[x]); }
void merge2(int x,int y) {
	x=find2(x),y=find2(y); if (x==y) return;
	if ((int)G2[x].size()>(int)G2[y].size()) swap(x,y);
	for (int &a : G2[x]) G2[y].push_back(a); fa2[x]=y; //sz[y]+=sz[x];
	//assert(sz[y]==(int)G2[y].size());
}
int sum[maxn],tim,vis[maxn];
int SZ[maxn],mk[maxn],TIM;
void merge(int x,int y,int z) {
	x=find(x),y=find(y);
	if (x==y) return;
	if (SZ[x]>SZ[y]) swap(x,y);
	//printf("merge %d %d\n",x,y);
	//for (int &a : G[x]) printf("%d is in x\n",a);
	//for (int &a : G[y]) printf("%d is in y\n",a);
	vector<pair<int,int> > R; TIM++;
	for (int &a : G[x]) {
		for (int &b : G[y]) sum[find3(b)]=0; tim++;
		for (int &i : G2[a]) {
			for (int j : V[i]) {
				if (find(j)==y||mk[j]==TIM) {
					int k=find3(j);
					sum[k]++;
					//printf("?%d %d %d\n",a,k,j);
				}
//				cnt++;
			}
		}
		for (int &i : G2[a]) mk[i]=TIM;
		vector<int> nxt_Gy;
		/*if (a==7) {
			for (int &b : G[y]) printf("%d ",b); puts("");
		}*/
		//printf("a=%d\n",a);
		for (int &b : G[y]) {
			//printf("b=%d,sz=%d,sum=%d %d\n",b,sz[find3(b)],sum[find3(b)],(int)G2[a].size());
			if (sum[find3(b)]!=(ll)sz[find3(b)]*(int)G2[a].size()) {
				R.push_back(MP(a,b));
				int A=find3(a),B=find3(b);
				fa3[A]=B,sz[B]+=sz[A];
				//printf("LINK %d %d\n",a,b);
			}
		}
		tim++;
		for (int &b : G[y]) {
			int c=find3(b);
			if (vis[c]!=tim) nxt_Gy.push_back(b),vis[c]=tim;
		}
		G[y].swap(nxt_Gy);
		//for (int &b : G[y]) printf("%d ",b); puts("");
	}
	for (pair<int,int> &A : R) merge2(A.first,A.second),link(A.first,A.second,z);
	fa[x]=y; SZ[y]+=SZ[x];
	tim++;
	vector<int> V;
	for (int i=0;i<G[y].size();i++) {
		G[y][i]=find2(G[y][i]);
		assert(vis[G[y][i]]!=tim);
		vis[G[y][i]]=tim;
	}
	for (int &a : G[x]) {
		int b=find2(a);
		if (vis[b]!=tim) vis[b]=tim,G[y].push_back(b);
	}
}
int f[maxn][20],g[maxn][20],dep[maxn];
void dfs(int u,int p) {
	dep[u]=dep[p]+1;
	for (auto [v,w] : T[u]) if (v!=p) {
		f[v][0]=u,g[v][0]=w;
		dfs(v,u);
	}
}
int main() {
//	freopen("1.txt","r",stdin);
	read(TT);
	while (TT--) {
		cnt=0;
		read(n),read(m);
		for (int i=1;i<=n;i++) {
			fa[i]=fa2[i]=i; sz[i]=1; fa3[i]=i;
			G[i].clear(); V[i].clear(); G2[i].clear();
			G[i].push_back(i);
			G2[i].push_back(i); T[i].clear();
		}
		for (int i=1;i<=m;i++) {
			read(E[i].x),read(E[i].y),read(E[i].z),E[i].id=i;
			V[E[i].x].push_back(E[i].y);
			V[E[i].y].push_back(E[i].x);
		}
		for (int i=1;i<=n;i++) SZ[i]=(int)V[i].size();
		sort(E+1,E+m+1,cmp);
		for (int i=1;i<=m;i++) {
			//if (i%1000==0) printf("%d\n",i);
			merge(E[i].x,E[i].y,E[i].z);
		}
		dfs(1,0);
		for (int i=1;i<=19;i++) for (int j=1;j<=n;j++)
			f[j][i]=f[f[j][i-1]][i-1],
			g[j][i]=max(g[j][i-1],g[f[j][i-1]][i-1]);
		sort(E+1,E+m+1,cmp2);
		for (int i=1;i<=m;i++) {
			int x=E[i].x,y=E[i].y,ans=0;
			if (dep[x]<dep[y]) swap(x,y);
			for (int j=19;j>=0;j--) if (dep[f[x][j]]>=dep[y]) ans=max(ans,g[x][j]),x=f[x][j];
			if (x!=y) {
				for (int j=19;j>=0;j--) if (f[x][j]!=f[y][j]) ans=max(ans,max(g[x][j],g[y][j])),x=f[x][j],y=f[y][j];
				ans=max(ans,max(g[x][0],g[y][0]));
			}
			printf("%d ",ans);
		}
		puts("");
		assert(cnt==n-1);
		//printf("cnt=%d\n",cnt);
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/