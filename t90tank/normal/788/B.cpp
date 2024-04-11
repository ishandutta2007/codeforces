#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back

const int maxn = 1000006; 

vector<int> e[maxn]; 
int n, m;
bool v[maxn]; 
int sum; 
int s[maxn]; 

int main() {
	scanf( "%d%d", &n, &m ); 
	ll ans = 0; 
	for (int i = 1; i <= m; ++i) {
		int u, v; 
		scanf( "%d%d", &u, &v ); 
		e[u].pb(v); e[v].pb(u); 
		if (u != v) {
			ans += s[u]+s[v]; 
			s[u]++; s[v]++;
		}
		else sum++; 
	}
	//cout<<sum<<endl; 
	ans += sum*ll(m-sum)+ll(sum)*(sum-1)/2; 
	deque<int> q; 
	for (int i = 1; i <= n; ++i) 
		if (!e[i].empty()) {
			q = {i}; v[i] = true; 
			break; 
		}
	while (!q.empty()) {
		auto u = q.front(); q.pop_front(); 
		for (auto i : e[u]) 
			if (!v[i]) { v[i] = true; q.pb(i); }
	}
	for (int i = 1; i <= n; ++i) 
		if (!v[i] && !e[i].empty()) {puts("0"); return 0;}
	cout<<ans<<endl; 
}