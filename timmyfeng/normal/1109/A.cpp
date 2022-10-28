#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 1;
const int A = (1 << 20) + 1;

int a[N];
int cnt[A][2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int cur = 0;
	++cnt[0][1];
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		cur ^= a[i];
		ans += cnt[cur][i % 2];
		++cnt[cur][i % 2];
	}
	cout << ans << "\n";
}