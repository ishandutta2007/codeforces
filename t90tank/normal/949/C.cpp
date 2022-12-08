#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
using pii = pair<int,int>;
#define pb push_back
#define fir first
#define sec second

const int maxn = 100006; 

int en[maxn]; 
int u[maxn]; 
vi g[maxn]; 
vi g2[maxn]; 
int n, m, h; 
int tot; 
bool v[maxn];
int c[maxn];  
int sum[maxn]; 

void dfs(int x) {
	v[x] = true; 
	for (auto i : g[x]) 
		if (!v[i]) dfs(i); 
	en[++tot] = x; 
}

void dfs2(int x, int f) {
	v[x] = true; 
	c[x] = f; 
	sum[f]++; 
	for (auto i : g2[x]) 
		if (!v[i]) dfs2(i, f); 
}

int main() {
	scanf( "%d%d%d", &n, &m, &h ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &u[i] ); 
	for (int i = 1; i <= m; ++i) {
		int a, b; 
		scanf( "%d%d", &a, &b ); 
		if ((u[a]+1) % h == u[b]) g[a].pb(b); 
		if ((u[b]+1) % h == u[a]) g[b].pb(a); 
	}
	for (int i = 1; i <= n; ++i) 
		for (auto j : g[i]) {
			//cout<<i<<' '<<j<<endl; 
			g2[j].pb(i); 
		}
	memset(v, false, sizeof(v)); 
	tot = 0; 
	for (int i = 1; i <= n; ++i) 
		if (!v[i]) dfs(i); 
	memset(v, false, sizeof(v)); 
	tot = 0; 
	memset(sum, 0, sizeof(sum)); 
	for (int i = n; i >= 1; --i) 
		if (!v[en[i]]) dfs2(en[i], ++tot); 
	memset(v, false, sizeof(v)); 
	for (int i = 1; i <= n; ++i) 
		for (auto j : g[i]) 
			if (c[i] != c[j]) 
				v[c[i]] = true; 
	int k = -1; 
	for (int i = 1; i <= tot; ++i) 
		if (!v[i] && (k == -1 || sum[i] < sum[k])) 
			k = i; 
	printf( "%d\n", sum[k]); 
	for (int i = 1; i <= n; ++i) 
		if (c[i] == k) printf( "%d ", i ); 
	puts( "" ); 
}