#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
typedef long long ll;
using namespace std;

const int N = 1000000;

int pt[6] = {
	1,
	10,
	100,
	1000,
	10000,
	100000
};
int k, q; 
ll f[N], c[6];

void add(ll x, ll d) {
	x *= 3;
	int s = 3 * (k - 1);
	rep(b, 0, 20) {
		ll cur = min((1 << b), s);
		s -= cur;
		ll v = x * cur;
		ll p = d * cur;
		per(i, v, N)
			f[i] = max(f[i], f[i - v] + p);
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> k;
	rep(i, 0, 6)
		cin >> c[i];

	rep(i, 0, 6)
		rep(j, 0, N)
			if (j / pt[i] % 10 % 3 == 0)
				f[j] += j / pt[i] % 10 / 3 * c[i];
	
	rep(i, 0, 6)
		add(pt[i], c[i]);

	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		cout << f[x] << endl;
	}
	
	return 0;
}