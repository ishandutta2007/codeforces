#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
int n, a[1000001], b[10000001][2];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (!b[a[i]][0])
			b[a[i]][0] = i;
		else
			b[a[i]][1] = i;
	}
	ll res = 1e18;
	int x, y;
	for (int g = 1; g <= 10000000; g++) {
		int p = -1, q = -1;
		for (int c = g; q == -1 && c <= 10000000; c += g) {
			for (int i = 0; i < 2; i++)
				if (b[c][i]) {
					if (p == -1)
						p = b[c][i];
					else if (q == -1)
						q = b[c][i];
				}
		}
		if (q != -1) {
			ll cur = 1ll * a[p] * a[q] / g;
			if (cur < res) {
				res = cur;
				x = p;
				y = q;
			}
		}
	}
	if (x > y) swap(x, y);
	cout << x << " " << y << endl;
	return 0;
}