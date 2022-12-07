#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)

using namespace std;

int n, t, k;

int main() {
	cin >> n >> t >> k;
	int l = 1, r = n;
	while (l < r) {
		int m = (l + r) / 2;
		cout << "? " << 1 << " " << m << endl;
		int zeros;
		cin >> zeros;
		zeros = m - zeros;
		if (k <= zeros)
			r = m;
		else
			l = m + 1;
	}
	cout << "! " << l << endl;
	return 0;
}