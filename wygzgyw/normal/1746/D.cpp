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
int T,n,k;
vector<int> vec[maxn],g[maxn];
ll dp[maxn][2],s[maxn];
void dfs(int u,int p) {
	sort(vec[u].begin(),vec[u].end());
	vec[u].resize(unique(vec[u].begin(),vec[u].end())-vec[u].begin());
	int m=(int)g[u].size();
	for (int &v : g[u]) {
		vec[v].clear();
		for (int &x : vec[u]) {
			if (x%m==0) vec[v].push_back(x/m);
			else vec[v].push_back(x/m),vec[v].push_back(x/m+1);
		}
		dfs(v,u);
	}
}
ll F(int x,int y) {
	if (vec[x][0]==y) return dp[x][0]; return dp[x][1];
}
void DFS(int u,int p) {
	for (int &v : g[u]) DFS(v,u);
	int m=(int)g[u].size();
	for (int i=0;i<vec[u].size();i++) {
		int x=vec[u][i];
		dp[u][i]=(ll)s[u]*x;
		if (m==0) continue;
		if (x%m==0) {
			for (int &v : g[u]) dp[u][i]+=F(v,x/m);
			continue;
		}
		vector<ll> V;
		for (int &v : g[u]) V.push_back(F(v,x/m+1)-F(v,x/m)),dp[u][i]+=F(v,x/m);
		sort(V.begin(),V.end()),reverse(V.begin(),V.end());
		for (int j=0;j<x%m;j++) dp[u][i]+=V[j];
	}
}
int main() {
	read(T);
	while (T--) {
		read(n),read(k);
		for (int i=1;i<=n;i++) g[i].clear();
		for (int i=2;i<=n;i++) {
			int x; read(x);
			g[x].push_back(i);
		}
		for (int i=1;i<=n;i++) read(s[i]);
		vec[1]={k};
		dfs(1,0);
		DFS(1,0);
		printf("%lld\n",dp[1][0]);
	}
	return 0;
}