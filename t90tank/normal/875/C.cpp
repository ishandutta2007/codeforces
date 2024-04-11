#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int maxn = 100006; 

int n, m, l;
vi e[maxn]; 
vi g[maxn]; 
int d[maxn]; 
vi s[maxn]; 
bool v[maxn]; 

bool dfs(int x) {
	v[x] = true; 
	if (d[x] == 0) {
		for (auto i : g[x]) {
			if (d[i] == 1) return false; 
			d[i] = 0; 
			if (!v[i]) 
				if (!dfs(i)) return false; 
		}
	}
	else {
		for (auto i : e[x]) {
			if (d[i] == 0) return false; 
			d[i] = 1; 
			if (!v[i]) 
				if (!dfs(i)) return false; 
		}
	}
	return true; 
}

int main() {
	scanf( "%d%d", &n, &m ); 
	for (int i = 1; i <= n; ++i) {
		s[i].clear(); 
		int l; 
		scanf( "%d", &l ); 
		for (int j = 1; j <= l; ++j) {
			int x; 
			scanf( "%d", &x ); 
			s[i].pb(x); 
		}
	}
	for (int i = 1; i <= m; ++i) {
		d[i] = -1; 
		e[i].clear(); 
		g[i].clear(); 
	}
	for (int i = 1; i < n; ++i) {
		bool flag = false; 
		for (int j = 0; j < (int)min(s[i].size(),s[i+1].size()); ++j) { 
			if (s[i][j] < s[i+1][j]) {
				e[s[i][j]].pb(s[i+1][j]); 
				g[s[i+1][j]].pb(s[i][j]); 
				flag = true; 
				break; 
			}
			if (s[i][j] > s[i+1][j]) {
				if (d[s[i][j]] == 1 || d[s[i+1][j]] == 0) {
					puts( "No" ); 
					return 0; 
				}
				d[s[i][j]] = 0; 
				d[s[i+1][j]] = 1; 
				flag = true; 
				break; 
			}
		}
		if (!flag) {
			if (s[i].size() > s[i+1].size()) {
				puts( "No" ); 
				return 0; 
			}
		}
	}
	memset(v, false, sizeof(v)); 
	for (int i = 1; i <= m; ++i) 
		if (!v[i] && d[i] != -1) 
			if (!dfs(i)) {
				puts( "No" ); 
				return 0; 
			}
	puts( "Yes" ); 
	vi ans; ans.clear(); 
	for (int i = 1; i <= m; ++i) 
		if (d[i] == 0) ans.pb(i); 
	printf( "%d\n", (int)ans.size()); 
	for (auto i : ans) printf( "%d ", i ); 
	puts( "" ); 
}