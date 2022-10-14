#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
const int mxN=2e5;

int a[mxN], b[mxN], n, m, k;
ar<int, 3> q[mxN];
int f[mxN+1];
ll o[mxN];
// we build a prefix sum array with q
// we update these prefix sums
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	// eventually we'll have a list of frequencies how many times to apply op
	for(int i = 0; i < m; i++)
		for(int j = 0; j < 3; j++)
			cin >> q[i][j];

	for(int i=0;i<k;i++) {
		int x, y;
		cin >> x >> y;
		--x;
		f[x]++;
		f[y]--;
	}
	ll c=0;
	for(int i=0;i<m;i++) {
		c+=f[i];
		o[q[i][0]-1] += c*q[i][2];
		o[q[i][1]] -= c*q[i][2];
	}
	c=0;
	for(int i=0;i<n;i++) {
		c+=o[i];
		cout << a[i] + c << " ";
	}
	cout << "\n";
}