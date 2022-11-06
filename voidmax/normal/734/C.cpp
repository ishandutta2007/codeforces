#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
using namespace std;

const int MAXN = 1e5;

long long n, m, k;
long long X, S, ans;
vector <long long> arr[2];
vector <long long> cost[2];

int main() {
	ios::sync_with_stdio(0);
	//freopen("input.in", "r", stdin);
	cin >> n >> m >> k >> X >> S;
	ans = X * n;
	arr[0].resize(m, 0);
	cost[0].resize(m, 0);
	arr[1].resize(k, 0);
	cost[1].resize(k, 0);
	for (int i = 0; i < m; ++i) cin >> arr[0][i];
	for (int i = 0; i < m; ++i) cin >> cost[0][i];
	for (int i = 0; i < k; ++i) cin >> arr[1][i];
	for (int i = 0; i < k; ++i) cin >> cost[1][i];
	for (int i = 0; i < m; ++i) {
		if (S - cost[0][i] < 0)
			continue;
		long long s = S - cost[0][i];
		auto it = upper_bound(cost[1].begin(), cost[1].end(), s);
		if (it == cost[1].begin()) {	
			ans = min(ans, arr[0][i] * n);
		} else {
			--it;
			ans = min(ans, arr[0][i] * (n - arr[1][it - cost[1].begin()]));
		}
	}
	long long s = S - 0;
	auto it = upper_bound(cost[1].begin(), cost[1].end(), s);
	if (it != cost[1].begin()) {
		--it;
		ans = min(ans, X * (n - arr[1][it - cost[1].begin()	]));
	}
	cout << ans << endl;
}