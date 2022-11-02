#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <chrono>
#include <random>
#include <bitset>
#include <functional>
#include <numeric>
#include <array>
#include <limits>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q, mod;
	cin >> n >> q >> mod;

	auto norm = [mod](int &x) {
		if (x < 0) x += mod;
		if (x >= mod) x -= mod;
	};
	
	vector<int> fib(n + 3);
	fib[0] = 1 % mod;
	fib[1] = 1 % mod;
	for (int i = 2; i < fib.size(); i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		if (fib[i] >= mod) fib[i] -= mod;
	}

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[i] -= x;
		if (a[i] < 0) a[i] += mod;
	}

	vector<int> b(a.size());
	b[0] = a[0];
	b[1] = a[1] - a[0];
	if (b[1] < 0) b[1] += mod;
	for (int i = 2; i < a.size(); i++) {
		b[i] = a[i] - a[i - 1];
		if (b[i] < 0) b[i] += mod;
		b[i] -= a[i - 2];
		if (b[i] < 0) b[i] += mod;
	}

	int cnt = 0;
	for (int i = 0; i < b.size(); i++) {
		if (b[i] == 0) ++cnt;
	}

	for (int i = 0; i < q; i++) {
		char c;
		int l, r;
		cin >> c >> l >> r;
		--l; --r;

		int sign = (c == 'A') ? +1 : -1;

		if (b[l] == 0) --cnt;
		b[l] += sign;
		norm(b[l]);
		if (b[l] == 0) ++cnt;

		if (r + 1 < n) {
			if (b[r + 1] == 0) --cnt;
			b[r + 1] -= sign * fib[r - l + 1];
			norm(b[r + 1]);
			if (b[r + 1] == 0) ++cnt;
		}
		if (r + 2 < n) {
			if (b[r + 2] == 0) --cnt;
			b[r + 2] -= sign * fib[r - l];
			norm(b[r + 2]);
			if (b[r + 2] == 0) ++cnt;
		}
		if (cnt == b.size()) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
	return 0;
}