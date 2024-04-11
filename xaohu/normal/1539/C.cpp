#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
using namespace std;

int n, sz;
long long k, x, a[222000], b[222000];
 
int main() {
	cin >> n >> k >> x;
	rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	int res = n;
	rep(i, 2, n) {
		if (a[i] - a[i - 1] <= x)
			res--;
		else
			b[++sz] = (a[i] - a[i - 1] + x - 1) / x - 1;
	}
	sort(b + 1, b + sz + 1);
	rep(i, 1, sz) 
		if (b[i] <= k) {
			k -= b[i];
			res--;
		}
	cout << res << endl;
	return 0;
}