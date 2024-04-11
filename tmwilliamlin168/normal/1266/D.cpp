#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, m;
ar<ll, 2> a[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int u, v, d; m--; ) {
		cin >> u >> v >> d, --u, --v;
		a[u][0]+=d;
		a[v][0]-=d;
	}
	for(int i=0; i<n; ++i)
		a[i][1]=i;
	sort(a, a+n);
	vector<ar<ll, 3>> ans;
	for(int l=0, r=n-1; l<r; ) {
		if(!a[l][0]) {
			++l;
			continue;
		}
		if(!a[r][0]) {
			--r;
			continue;
		}
		ll x=min(-a[l][0], a[r][0]);
		a[l][0]+=x;
		a[r][0]-=x;
		ans.push_back({a[r][1], a[l][1], x});
	}
	cout << ans.size() << "\n";
	for(ar<ll, 3> a : ans)
		cout << a[0]+1 << " " << a[1]+1 << " " << a[2] << "\n";
}