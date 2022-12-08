#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int maxn = 400000; 

int n, m; 
int d[maxn]; 
vector<pair<int,int>> e[maxn]; 
bool v[maxn]; 
vi ans; 

int dfs(int x) {
	v[x] = true;  
	int s = d[x]; 
	for (auto i : e[x]) 
		if (!v[i.fir]) 
			if (dfs(i.fir) == 1) {
				s^=1; 
				ans.pb(i.sec); 
			}
	//cout<<s<<' '<<d[x]<<' '<<x<<endl; 
	return s; 
}

int main() {
	scanf( "%d%d", &n, &m ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &d[i] ); 
	for (int i = 1; i <= m; ++i) {
		int u, v; 
		scanf("%d%d", &u, &v); 
		e[u].pb({v,i}); 
		e[v].pb({u,i}); 
	}
	int s = 0; 
	for (int i = 1; i <= n; ++i) 
		if (d[i] == 1) s ^= 1; 
	if (s == 1) {
		bool flag = false; 
		for (int i = 1; i <= n; ++i) 
			if (d[i] == -1) {
				flag = true; 
				d[i] = 1; 
				break; 
			}
		if (!flag) {
			puts("-1"); 
			return 0; 
		}
	}
	for (int i = 1; i <= n; ++i) 
		if (d[i] == -1) d[i] = 0;
	dfs(1); 
	printf( "%d\n", (int)ans.size()); 
	for (auto i : ans) printf( "%d\n", i ); 
}