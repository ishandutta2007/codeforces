#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int n,sz[maxn],head[maxn];
int to[maxn*2],nxt[maxn*2];
int tot,dep[maxn],b[maxn];
int son[maxn];
int dfn[maxn],dy[maxn];
void add(int x,int y) {
	tot++; nxt[tot]=head[x];
	head[x]=tot; to[tot]=y;
}
void dfs(int u,int p) {
	sz[u]=1; dep[u]=dep[p]+1;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i]; if (v!=p) {
			dfs(v,u),sz[u]+=sz[v];
			if (sz[v]>sz[son[u]]) son[u]=v;
		}
	}
}
int DFS(int u,int p) {
	dfn[++tot]=u; dy[u]=tot;
	if (son[u]) b[u]=DFS(son[u],u);
	else b[u]=u;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i]; if (v!=p&&v!=son[u]) DFS(v,u);
	}
	return b[u];
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); int x,y;
	for (int i=1;i<n;i++) {
		read(x); read(y);
		add(x,y); add(y,x);
	}
	tot=0;
	dfs(1,0);
	DFS(1,0);
	int u=1,v,d,dx;
	printf("d 1\n"); fflush(stdout);
	read(dx); dx++;
	while (1) {
		v=b[u];
		printf("d %d\n",v); fflush(stdout);
		read(d); d=(dx+dep[v]-d)/2;
		y=dfn[dy[u]+d-dep[u]];
		if (dx==d) { printf("! %d\n",y); break; }
		printf("s %d\n",y); fflush(stdout);
		read(u);
	}
	return 0;
}