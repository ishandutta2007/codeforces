#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int n, m;
const int mxN=2e5;
vector<int> adj[mxN];
int a[mxN], b[mxN];
bitset<mxN> vis;
// each component must be a connected graph

vector<int> dfs(int c) {
	vis[c]=1;
	vector<int> ans={c};
	for(int e:adj[c]) {
		if(!vis[e]) {
			vector<int> r=dfs(e);
			if(r.size()>ans.size())
				swap(ans,r);
			for(int j:r)
				ans.push_back(j);
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0;i<m;i++)
		cin >> a[i] >> b[i], --a[i], --b[i], adj[a[i]].pb(b[i]), adj[b[i]].pb(a[i]);
	bool works=true;
	for(int i=0;i<n;i++) {
		if(!vis[i]) {
			vector<int> result=dfs(i);
			int lol=result.size()-1;
			for(int j:result) {
				works&=adj[j].size()==result.size()-1;
			}
		}	
	}
	cout << (works?"YES":"NO");
}