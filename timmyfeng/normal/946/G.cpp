#include <bits/stdc++.h> 
using namespace std;

const int INF = 2e9;
const int MX = 2e5 + 5;

int a[MX], lis[MX], len[MX], lds[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	a[0] = -INF + 10;

	fill(lis, lis + n + 1, INF);
	lis[0] = -INF;
	for (int i = 1; i < n; ++i) {
		len[i] = upper_bound(lis, lis + n + 1, a[i] - i) - lis;
		lis[len[i]] = a[i] - i;
	}
	int ans = len[n - 1];

	fill(lds, lds + n + 1, -INF);
	lds[0] = INF;
	for (int i = n; i > 1; --i) {
		int ndx = upper_bound(lds, lds + n + 1, a[i] - i, greater<int>()) - lds;
		lds[ndx] = a[i] - i;
		
		int res = upper_bound(lds, lds + n + 1, a[i - 2] - (i - 2) - 1, greater<int>()) - lds - 1;
		ans = max(ans, len[i - 2] + res);
	}

	cout << n - 1 - ans << '\n';
}