#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int maxn = 200006; 

int a[maxn]; 
int n, m; 
vi e[maxn]; 
bool v[maxn]; 
int tot; 
int no[maxn]; 

void dfs(int x) {
	a[x] = ++tot; 
	v[x] = true; 
	for (auto i : e[x]) 
		if (!v[i]) dfs(i); 
}

bool cmp(int x, int y) {
	return a[x] < a[y]; 
}

int d[maxn]; 
struct data {
	int a, b, c; 
}; 
vector<data> ans; 

int main() {
	scanf( "%d%d", &n, &m ); 
	for (int i = 1; i <= m; ++i) {
		int a, b; 
		scanf( "%d%d", &a, &b ); 
		e[a].pb(b); e[b].pb(a); 
	}
	tot = 0; memset(v, false, sizeof(v)); 
	for (int i = 1; i <= n; ++i) 
		if (!v[i]) dfs(i); 
	for (int i = 1; i <= n; ++i) no[i] = i; 
	sort(no+1,no+n+1,cmp); 
	memset(d, 0, sizeof(d)); 
	for (int i = n; i >= 1; --i) {
		int x = no[i]; 
		for (auto j : e[x]) 
			if (a[j] > a[x]) {
				if (d[j] != 0) {
					ans.pb({x, j, d[j]}); 
					d[j] = 0; 
				}
				else if (d[x] != 0) {
					ans.pb({d[x], x, j}); 
					d[x] = 0; 
				}
				else d[x] = j; 
			}
	}
	printf( "%d\n", (int)ans.size() ); 
	for (auto p : ans) 
		printf( "%d %d %d\n", p.a, p.b, p.c ); 
}