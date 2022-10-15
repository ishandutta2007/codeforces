#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define a array

const int mxN=1e5;
int n, m, dp[mxN];
map<ll, int> mp;
vector<int> adj[mxN];
ll ans;

int cdp(int u) {
	if(!dp[u]) {
		for(int v : adj[u])
			dp[u]+=cdp(v);
		++dp[u];
		ans+=dp[u];
	}
	return dp[u];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<m; ++i) {
		for(int j=0, l=-1, a; j<n; ++j) {
			cin >> a, --a;
			if(l!=-1)
				++mp[(ll)l*n+a];
			l=a;
		}
	}
	for(auto it=mp.begin(); it!=mp.end(); ++it)
		if(it->second>=m)
			adj[it->first/n].push_back(it->first%n);
	for(int i=0; i<n; ++i)
		cdp(i);
	cout << ans;
}