#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, eu[mxN], ev[mxN], ans[mxN];
vector<int> adj[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=1; i<n; ++i) {
		cin >> eu[i] >> ev[i], --eu[i], --ev[i];
		adj[eu[i]].push_back(i);
		adj[ev[i]].push_back(i);
	}
	for(int i=0; i<n; ++i) {
		if(adj[i].size()<=2)
			continue;
		memset(ans, -1, 4*n);
		for(int j=0; j<3; ++j)
			ans[adj[i][j]]=j;
		for(int i=1, j=3; i<n; ++i) {
			if(ans[i]<0)
				ans[i]=j++;
			cout << ans[i] << "\n";
		}
		return 0;
	}
	for(int i=1; i<n; ++i)
		cout << i-1 << "\n";
}