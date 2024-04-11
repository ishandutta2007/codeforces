
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxN=5e5;
int n, vis[mxN];
ar<int, 2> a[mxN];
vector<int> adj[mxN];
 
int dfs(int u=0, int p=-1) {
	if(vis[u])
		return 0;
	int s=1;
	vis[u]=1;
	for(int v : adj[u])
		if(v^p)
			s+=dfs(v, u);
	return s;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> a[i][0] >> a[i][1];
	}
	sort(a, a+n);
	map<int, int> mp;
	int e=0;
	for(int i=0; i<n; ++i) {
		auto it=mp.lower_bound(a[i][0]);
		while(it!=mp.end()&&it->first<a[i][1]) {
			adj[it->second].push_back(i);
			adj[i].push_back(it->second);
			++it;
			++e;
			if(e>=n) {
				cout << "NO";
				return 0;
			}
		}
		mp[a[i][1]]=i;
	}
	cout << (dfs()<n?"NO":"YES");
}