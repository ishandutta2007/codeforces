#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=(1e9);
const int maxn=(3e5)+10;
int T,n,head[maxn],to[maxn*2];
int nxt[maxn*2],tot;
void add(int x,int y) {
	tot++; nxt[tot]=head[x];
	head[x]=tot; to[tot]=y;
}
int dp[maxn],in[maxn],ans;
void dfs(int u,int p) {
	int mx=0,mx2=0;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		if (v==p) continue;
		dfs(v,u);
		if (mx<dp[v]) mx2=mx,mx=dp[v];
		else mx2=max(mx2,dp[v]);
	}
	ans=max(ans,in[u]+mx+mx2);
	dp[u]=mx+in[u];
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); int x,y; tot=0;
		for (int i=1;i<=n;i++) head[i]=in[i]=0;
		for (int i=1;i<n;i++) {
			read(x); read(y);
			add(x,y); add(y,x);
			in[x]++; in[y]++;
		}
		for (int i=1;i<=n;i++) in[i]--;
		ans=-INF;
		dfs(1,0);
		printf("%d\n",ans+2);
	}
	return 0;
}