#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=1e10;
const int maxn=(2e5)+10;
int n,m;
ll ans;
struct node { int x,y; ll z; } edge[maxn],e1[maxn],e2[maxn],e3[maxn];
int fa[maxn],cnt,m1,m2,m3;
int find(int x) {
	if (fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
vector<pair<int,int> > g[maxn];
queue<int> q;
bool cmp(node A,node B) { return A.z<B.z; }
int v1[maxn],v2[maxn],pre[maxn],nxt[maxn],bel[maxn];
void del(int x) {
	pre[nxt[x]]=pre[x],nxt[pre[x]]=nxt[x];
}
int V[maxn],E[maxn];
void init() {
	while (nxt[0]) {
		int now=nxt[0]; cnt++;
		del(now); bel[now]=cnt;
		q.push(now); v2[now]=1;
		while (!q.empty()) {
			int u=q.front(); q.pop();
			for (int i=0;i<g[u].size();i++) v1[g[u][i].first]=1;
			for (int i=nxt[0];i;i=nxt[i])
				if (!v1[i]&&!v2[i]) {
					v2[i]=1;
					q.push(i);
					bel[i]=cnt;
					del(i);
				}
			for (int i=0;i<g[u].size();i++) v1[g[u][i].first]=0;
		}
	}
}
int tot,bg[maxn],ed[maxn],fst[maxn];
vector<int> G[maxn];
int vis[maxn];
int M[3010][3010]; ll now;
void dfs(int u,int p) {
	bg[u]=++tot; vis[u]=1;
	for (int v : G[u]) if (v!=p) dfs(v,u);
	ed[u]=tot;
}
void merge(int x,int y,int z) {
	x=find(x),y=find(y);
	if (x==y) return;
	fa[x]=y; now+=z;
	//printf("%d %d %d\n",x,y,z);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m);
	int x,y,at=0; ll z;
	for (int i=1;i<=m;i++) {
		read(x),read(y),read(z);
		edge[i]=(node){x,y,z};
		g[x].push_back(make_pair(y,z));
		g[y].push_back(make_pair(x,z));
		at^=z;
		if (n<=3000) M[x][y]=M[y][x]=1;
	}
	for (int i=1;i<=n;i++) pre[i]=i-1,nxt[i-1]=i;
	nxt[n]=0;
	init();
	for (int i=1;i<=n;i++) V[bel[i]]++;
	//for (int i=1;i<=n;i++) printf("%d ",bel[i]); puts("");
	for (int i=1;i<=m;i++) {
		x=edge[i].x,y=edge[i].y;
		x=bel[x],y=bel[y]; z=edge[i].z;
		if (x==y) {
			E[x]++;
		} else {
			if (x>y) swap(x,y);
			e2[++m2]=(node){x,y,z};
		}
	}
	int flag=0;
	for (int i=1;i<=cnt;i++) {
		if ((ll)V[i]*(V[i]-1)/2-E[i]!=V[i]-1) { flag=1; break; }
	}
	for (int i=1;i<=cnt;i++) fa[i]=i;
	sort(e2+1,e2+m2+1,cmp);
	for (int i=1;i<=m2;i++) {
		x=find(e2[i].x),y=find(e2[i].y);
		if (x==y) continue;
		ans+=e2[i].z;
		fa[x]=y;
	}
	int a,b;
	if (!flag) {
		ans+=at;
		for (int i=1;i<=n;i++) {
			for (int j=1;j<i;j++) if (!M[i][j]) {
				G[i].push_back(j),G[j].push_back(i);
				e1[++m1]=(node){i,j,at};
			//	printf("%d %d %d\n",i,j,at);
			}
		}
		tot=0;
		for (int i=1;i<=n;i++) if (!vis[i]) dfs(i,0);
		sort(edge+1,edge+m+1,cmp);
		for (int D=1;D<=m1;D++) {
			for (int i=1;i<=cnt;i++) fst[i]=-1;
			x=e1[D].x,y=e1[D].y;
			if (bg[x]>bg[y]) swap(x,y);
			for (int i=1;i<=n;i++) fa[i]=i;
			for (int i=1;i<=n;i++) {
				if (bel[i]==bel[x]) {
					if (bg[y]<=bg[i]&&bg[i]<=ed[y]) fa[i]=y;
					else fa[i]=x;
				} else {
					if (fst[bel[i]]!=-1) fa[i]=fst[bel[i]];
					else fst[bel[i]]=i;
				}
			}
			/*if (D==3) {
				for (int i=1;i<=n;i++) printf("%d ",fa[i]); puts("");
			}*/
			flag=0; edge[m+1].z=INF; now=0;
			for (int i=1;i<=m+1;i++) {
			//	printf("%d %d\n",edge[i].x,edge[i].y);
				if (!flag&&at<=edge[i].z) {
					flag=1;
					merge(x,y,at);
				}
				if (i>m) break;
				merge(edge[i].x,edge[i].y,edge[i].z);
			}
			ans=min(ans,now);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/