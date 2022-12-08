#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

int a, b, h, w, n; 
int p[200000]; 
map<int,int> s; 
vector<pair<int,int>> v; 

bool dfs(int dep, ll c1, ll c2) {
	if (dep >= (int)v.size()) {
		if ((h*c1 >= a && w*c2 >= b) || (h*c1 >= b && w*c2 >= a))
			return true; 
		return false; 
	}
	int s = 0; 
	for (int i = 1; i <= v[dep].sec && c1 <= 100000; ++i) {
		c1 *= v[dep].fir; 
		s++; 
	}
	for (int i = s+1; i <= v[dep].sec; ++i) c2 *= v[dep].fir; 
	if (dfs(dep+1,c1,c2)) return true; 
	for (int i = 1; i <= s && c2 <= 100000; ++i) {
		c1 /= v[dep].fir;
		c2 *= v[dep].fir; 
		if (dfs(dep+1,c1,c2)) return true; 
	}
	return false; 
}

int main() {
	scanf( "%d%d%d%d%d", &a, &b, &h, &w, &n ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &p[i] );
	sort(p+1,p+n+1); 
	reverse(p+1,p+n+1); 
	if (dfs(0,1,1)) puts( "0" ); 	
	else {
		for (int i = 1; i <= n; ++i) {
			s[p[i]]++; 
			v.clear(); 
			for (auto p : s) v.pb(p); 
			if (dfs(0,1,1)) {
				printf( "%d\n", i ); 
				return 0; 
			}
		}	
		puts( "-1" ); 
	}
}