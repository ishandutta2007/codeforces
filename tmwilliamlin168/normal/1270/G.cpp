#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6;
int t, n, a[mxN];
bool vis[mxN];

void solve() {
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		a[i]=i-a[i];
	}
	memset(vis, 0, n);
	int u=0;
	for(; !vis[u]; vis[u]=1, u=a[u]);
	vector<int> ans;
	for(; vis[u]; vis[u]=0, u=a[u])
		ans.push_back(u);
	cout << ans.size() << "\n";
	for(int ai : ans)
		cout << ai+1 << " ";
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	while(t--)
		solve();
}