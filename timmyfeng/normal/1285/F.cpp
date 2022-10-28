#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 1e5 + 1;

vector<int> divisors[MX];
int mu[MX], cnt[MX];
bool in_arr[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i < MX; ++i) {
		for (int j = i; j < MX; j += i) {
			divisors[j].push_back(i);
		}
		if (i == 1) {
			mu[i] = 1;
		} else if (i / divisors[i][1] % divisors[i][1]) {
			mu[i] = -mu[i / divisors[i][1]];
		} else {
			mu[i] = 0;
		}
	}

	int n;
	cin >> n;
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		for (auto i : divisors[a]) {
			if (in_arr[i]) {
				ans = max(ans, (ll)i);
			}
			in_arr[i] = true;
		}
	}

	vector<int> stk;
	for (int i = MX - 1; i; --i) {
		if (in_arr[i]) {
			int coprime = 0;
			for (auto j : divisors[i]) {
				coprime += cnt[j] * mu[j];
			}

			while (coprime) {
				int j = stk.back();
				for (auto k : divisors[j]) {
					--cnt[k];
				}
				stk.pop_back();

				if (__gcd(i, j) == 1) {
					ans = max(ans, (ll)i * j);
					--coprime;
				}
			}

			for (auto j : divisors[i]) {
				++cnt[j];
			}
			stk.push_back(i);
		}
	}
	cout << ans << '\n';
}