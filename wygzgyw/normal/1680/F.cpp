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
const int maxn=(1e6)+10;
int T,n,m;
vector<int> g[maxn];
int col[maxn];
int flag,X,Y,dep[maxn];
void dfs(int u) {
	for (int &v : g[u]) {
		if (u==X&&v==Y) continue;
		if (v==X&&u==Y) continue;
		if (col[v]==-1) col[v]=(col[u]^1),dfs(v);
		else if (col[v]==col[u]) flag=0;
	}
}
int fa[maxn],vis[maxn],bg[maxn],ed[maxn],tot;
void dfs2(int u) {
	vis[u]=1; bg[u]=++tot;
	for (int &v : g[u]) if (!vis[v]) {
	//	printf("%d %d\n",u,v);
		fa[v]=u,dep[v]=dep[u]+1,dfs2(v);
	}
	ed[u]=tot;
}
bool in(int x,int y) { return bg[y]<=bg[x]&&bg[x]<=ed[y]; }
int sum[maxn],w[maxn];
void dfs3(int u) {
	for (int &v : g[u]) if (fa[v]==u) dfs3(v),sum[u]+=sum[v],w[u]+=w[v];
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); X=Y=0; tot=0;
		for (int i=1;i<=n;i++) g[i].clear(),col[i]=-1,vis[i]=sum[i]=w[i]=0;
		read(m); int x,y;
		for (int i=1;i<=m;i++) {
			read(x),read(y); g[x].push_back(y),g[y].push_back(x);
		}
		flag=1;
		col[1]=0;
		dfs(1);
		if (flag) { puts("YES"); for (int i=1;i<=n;i++) printf("%d",col[i]); puts(""); continue; }
		dep[1]=0,dfs2(1);
		int cnt=0,fd=0;
		for (int i=1;i<=n;i++) for (int &j : g[i]) if (dep[i]>dep[j]&&fa[i]!=j&&fa[j]!=i&&(dep[i]%2==dep[j]%2)) {
			sum[i]++,sum[j]--,cnt++;
			X=i,Y=j;
			if (!fd||dep[j]<dep[fd]) fd=j;
		//	printf(" %d %d\n",X,Y);
		}
		for (int i=1;i<=n;i++) col[i]=-1;
		flag=1;
		col[1]=0;
		dfs(1);

		if (flag) { puts("YES"); for (int i=1;i<=n;i++) printf("%d",col[i]^(col[X]==0)); puts(""); continue; }
		
		for (int i=1;i<=n;i++) for (int &j : g[i]) if (dep[i]>dep[j]&&fa[i]!=j&&fa[j]!=i&&(dep[i]%2!=dep[j]%2)) {
			w[i]++,w[j]--;
		}
		
		dfs3(1);
		X=0;
		for (int i=2;i<=n;i++) if (sum[i]==cnt&&!w[i]&&(!X||dep[i]<dep[X])) { X=i,Y=fa[i]; }
	//	printf("? %d %d\n",X,Y);
		for (int i=1;i<=n;i++) col[i]=-1;
		flag=1;
		col[1]=0;
		dfs(1);
		if (flag) { puts("YES"); for (int i=1;i<=n;i++) printf("%d",col[i]^(col[X]==0)); puts(""); continue; }
		puts("NO");
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