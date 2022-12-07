#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;	

int n, p[20];
ll k;
vector<ll> num[2];

void rec(int a, int b, ll x, int id) {
	if (a == b + 1) {
		num[id].push_back(x);
		return;
	}
	while (1) {
		rec(a + 1, b, x, id);
		if (x > 1e18 / p[a])
			break;
		x *= p[a];
	}
}

int main() {
	cin >> n;
	rep(i, 0, n)
		cin >> p[i];
	cin >> k;
	int mid = min(6, n / 2);
	rec(0, mid, 1, 0);
	rec(mid + 1, n - 1, 1, 1);
	rep(i, 0, 2)
		sort(num[i].begin(), num[i].end());
	ll l = 1, r = 1e18;
	while (l < r) {
		ll m = (l + r) / 2;
		ll cnt = 0;
		int j = sz(num[1]) - 1;
		for (auto x : num[0]) {
			while (j >= 0 && num[1][j] > m / x)
				j--;
			cnt += j + 1;
		}	
		if (cnt >= k)
			r = m;
		else
			l = m + 1;
	}
	cout << l << endl;	
	return 0;
}