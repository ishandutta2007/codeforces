#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5e4;
int n, m, sr[mxN], sc[mxN];
string g[mxN];

void solve() {
	cin >> n >> m;
	memset(sr, 0, 4*n);
	memset(sc, 0, 4*m);
	for(int i=0; i<n; ++i) {
		cin >> g[i];
		for(char c : g[i])
			sr[i]+=c=='.';
	}
	for(int j=0; j<m; ++j)
		for(int i=0; i<n; ++i)
			sc[j]+=g[i][j]=='.';
	int ans=1e9;
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			ans=min(sr[i]+sc[j]-(g[i][j]=='.'), ans);
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;
	while(q--)
		solve();
}