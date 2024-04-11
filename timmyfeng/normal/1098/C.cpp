#include <bits/stdc++.h>
using namespace std;

long long calc(long long n, long long k, long long cnt, int dep) {
	if (k == 1) {
		return n * (2 * dep + n - 1) / 2;
	}

	long long res = 0;
	while (n > 0) {
		res += dep * min(n, cnt);
		n -= cnt;
		cnt *= k;
		++dep;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	long long s;
	cin >> n >> s;

	if (s < calc(n, n - 1, 1, 1) || s > calc(n, 1, 1, 1)) {
		cout << "No\n";
		exit(0);
	}

	int k = 1;
	while (calc(n, k, 1, 1) > s) {
		++k;
	}

	--s;
	int par = 0;
	int cur = 1;
	int dep = 2;
	int chd_cnt = 0;
	int layer_cnt = 0;

	cout << "Yes\n";
	while (s > 0) {
		cout << par + 1 << " ";
		++layer_cnt;
		++chd_cnt;

		if (calc(n - cur, k, layer_cnt, dep) <= s) {
			par = cur;
			chd_cnt = 0;
			cur += layer_cnt;
			s -= 1LL * layer_cnt * dep;
			layer_cnt = 0;
			++dep;
		} else if (chd_cnt == k) {
			chd_cnt = 0;
			++par;
		}
	}
	cout << "\n";
}