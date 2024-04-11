#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int maxn = 300000; 

int n, m; 
int p[maxn], a[maxn], b[maxn]; 
set<pair<int,int>> g[4]; 
bool v[maxn]; 

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &p[i] ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &a[i] ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &b[i] ); 
	for (int i = 1; i <= n; ++i) {
		g[a[i]].insert({p[i],i}); 
		g[b[i]].insert({p[i],i}); 
	}
	scanf( "%d", &m ); 
	for (int i = 1; i <= m; ++i) {
		int c; 
		scanf( "%d", &c ); 
		bool flag = false; 
		while (!g[c].empty()) {
			auto u = *(g[c].begin()); 
			g[c].erase(g[c].begin()); 
			if (!v[u.sec]) {
				flag = true; 
				v[u.sec] = true; 
				printf( "%d ", u.fir ); 
				break; 
			}
		}
		if (!flag) printf( "-1 " ); 
	}
	puts( "" ); 
}