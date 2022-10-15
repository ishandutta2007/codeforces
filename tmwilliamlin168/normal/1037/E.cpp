#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define fi first
#define se second

const int mxN=2e5;
int n, m, k, eu[mxN], ev[mxN], ans[mxN];
set<int> adj[mxN];
bool a[mxN];
vector<int> tp;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	for(int i=0; i<m; ++i) {
		cin >> eu[i] >> ev[i], --eu[i], --ev[i];
		adj[eu[i]].insert(i);
		adj[ev[i]].insert(i);
		a[i]=1;
	}
	for(int i=0; i<n; ++i)
		if(adj[i].size()<k)
			tp.push_back(i);
	for(int i=m-1; i>=0; --i) {
		ans[i]=i<m-1?ans[i+1]:n;
		for(int j=0; j<tp.size(); ++j) {
			for(int e : adj[tp[j]]) {
				adj[eu[e]^ev[e]^tp[j]].erase(e);
				if(adj[eu[e]^ev[e]^tp[j]].size()==k-1)
					tp.push_back(eu[e]^ev[e]^tp[j]);
				a[e]=0;
			}
			adj[tp[j]].clear();
			--ans[i];
		}
		tp.clear();
		if(a[i]) {
			adj[eu[i]].erase(i);
			if(adj[eu[i]].size()<k)
				tp.push_back(eu[i]);
			adj[ev[i]].erase(i);
			if(adj[ev[i]].size()<k)
				tp.push_back(ev[i]);
			a[i]=0;
		}
	}
	for(int i=0; i<m; ++i)
		cout << ans[i] << "\n";
}