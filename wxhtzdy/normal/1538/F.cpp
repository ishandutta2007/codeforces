#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int calc(int n) {
	int ans = 0;
	for (int i = 1; i <= 1e9; i *= 10) {
		ans += n / i;
	}
	return ans;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

	int tt;
	cin >> tt;
	while (tt--) {
		int l, r;
		cin >> l >> r;
		cout << calc(r) - calc(l) << '\n';
	}
}