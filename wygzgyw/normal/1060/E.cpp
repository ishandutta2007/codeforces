#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
typedef long long ll;
int n,sz[maxn],dis[maxn];
ll sum,dp[maxn][2],s1,s2;
int cnt[maxn][2],c[maxn][2];
vector<int> g[maxn];
void dfs(int u,int p) {
	dis[u]=dis[p]+1; sz[u]=1;
	cnt[u][dis[u]&1]++;
	for (int i=0;i<g[u].size();i++) {
		int v=g[u][i];
		if (v==p) continue;
		dfs(v,u);
		sz[u]+=sz[v];
		cnt[u][0]+=cnt[v][0];
		cnt[u][1]+=cnt[v][1];
	}
	sum+=(ll)sz[u]*(n-sz[u]);
}
void dfs2(int u,int p) {
	ll a=0,b=0,cc=0;
	for (int i=0;i<g[u].size();i++) {
		int v=g[u][i];
		if (v==p) continue;
		dfs2(v,u);
		a+=c[v][0]; b+=c[v][1];
		cc+=(ll)c[v][0]*c[v][1];
		//if (u==1) printf("! %d %d %d\n",v,c[v][0],c[v][1]);
	}
	cc=a*b-cc;
	//printf("%d %lld %d\n",u,cc,c[u][1]);
	s1+=cc+c[u][1];
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<n;i++) {
		int x,y; read(x); read(y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	for (int i=1;i<=n;i++)
		c[i][0]=cnt[i][dis[i]&1],c[i][1]=cnt[i][1-dis[i]&1];
	dfs2(1,0);
	//printf("%lld %lld\n",sum,s1);
	printf("%lld\n",(sum+s1)/2);
	return 0;
}