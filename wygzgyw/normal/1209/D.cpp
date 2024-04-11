#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int n,m,head[maxn];
int tot,to[maxn],nxt[maxn];
void add(int x,int y) {
	tot++; nxt[tot]=head[x];
	head[x]=tot; to[tot]=y;
}
int vis[maxn],ans;
void dfs(int u) {
	vis[u]=1;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i]; if (!vis[v]) dfs(v);
	}
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m); int x,y;
	for (int i=1;i<=m;i++) {
		read(x); read(y);
		add(x,y); add(y,x);
	}
	for (int i=1;i<=n;i++)
		if (!vis[i]) dfs(i),ans++;
	printf("%d\n",m-(n-ans));
	return 0;
}