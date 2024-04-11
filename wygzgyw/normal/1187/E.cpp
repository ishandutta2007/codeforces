#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e5)+10;
int n,head[maxn],tot,sz[maxn];
int nxt[maxn*2],to[maxn*2];
ll ans,s[maxn];
void add(int x,int y) {
	tot++; nxt[tot]=head[x];
	head[x]=tot; to[tot]=y;
}
void dfs(int u,int p) {
	sz[u]=1;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i]; if (v!=p) dfs(v,u),sz[u]+=sz[v];
	}
}
void DFS(int u,int p) {
	ans=max(ans,s[u]);
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		if (v==p) continue;
		s[v]=s[u]-(n+sz[v])+(n+n-sz[v]);
		DFS(v,u);
	}
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); int x,y;
	for (int i=1;i<n;i++) {
		read(x); read(y);
		add(x,y); add(y,x);
	}
	dfs(1,0);
	for (int i=1;i<=n;i++) s[1]+=sz[i];
	DFS(1,0);
	printf("%lld\n",ans);
	return 0;
}