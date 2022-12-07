#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
typedef long long ll;
using namespace std;

ll n, m;
vector<int> ans;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> m;
	ll x = 0;
	while (m > 0 && x / 2 <= m) {
		m -= x / 2;
		ans.push_back(++x);
	}

	if (x > n || (x == n && m > 0)) {
		cout << "-1\n";
		return 0;
	}

	if (x < n) {
		ans.push_back(x + (x - 2 * m + 1));

		rep(i, 0, n - x - 1)
			ans.push_back(100'000'000 + 3 * i * n);
	}

	for (auto x : ans)
		cout << x << " ";

	return 0;
}