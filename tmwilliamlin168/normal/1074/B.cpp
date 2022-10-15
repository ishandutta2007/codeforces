#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define a array

const int mxN=1e3;
int t, n, ai, bi, k1, k2, x[mxN], y[mxN], qa, ans;
vector<int> adj[mxN];
bool c[mxN];

int dfs(int u, int p=-1) {
	if(c[u])
		return u;
	for(int v : adj[u]) {
		if(v==p)
			continue;
		int a=dfs(v, u);
		if(a!=-1)
			return a;
	}
	return -1;
}

void solve() {
	cin >> n;
	for(int i=0; i<n; ++i)	
		adj[i].clear();
	for(int i=0; i<n-1; ++i) {
		cin >> ai >> bi, --ai, --bi;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	memset(c, 0, n);
	cin >> k1;
	for(int i=0; i<k1; ++i) {
		cin >> x[i], --x[i];
		c[x[i]]=1;
	}
	cin >> k2;
	for(int i=0; i<k2; ++i)
		cin >> y[i], --y[i];
	cout << "B " << y[0]+1 << endl;
	cin >> qa, --qa;
	ans=dfs(qa);
	cout << "A " << ans+1 << endl;
	cin >> qa, --qa;
	bool ok=0;
	for(int i=0; i<k2&&!ok; ++i)
		ok=y[i]==qa;
	cout << "C " << (ok?ans+1:-1) << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	while(t--)
		solve();
}