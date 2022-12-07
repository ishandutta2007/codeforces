#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
int t, n, a[100001], b[100001];
int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++)
			cin >> b[i];
		sort(a + 1, a + n + 1, greater<int>());
		sort(b + 1, b + n + 1, greater<int>());
		for (int i = 1; i <= n; i++) {
			a[i] += a[i - 1];
			b[i] += b[i - 1];
		}
		for (int i = n; true; i++) {
			int k = i - i / 4;
			int cnt = min(k, i - n);
			if (100 * cnt + a[k - cnt] - b[min(k, n)] >= 0) {
				cout << i - n << endl;
				break;
			}
		}
	}
	return 0;
}