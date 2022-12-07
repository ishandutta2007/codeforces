#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
int n, a[200000];
map<int, int> r;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		r[a[i]] = i;
	}

	int res = 1;
	for (int i = 0; i < n;) {
		int j = r[a[i]];
		while (i <= j) {
			j = max(j, r[a[i]]);
			i++;
		}
		if (i != n)
			res = 2 * res % 998244353;
	}

	cout << res << endl;
	return 0;
}