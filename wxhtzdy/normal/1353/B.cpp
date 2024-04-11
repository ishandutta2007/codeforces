#include <bits/stdc++.h>

using namespace std;

const int N = 35;
int a[N], b[N];

int main () {
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			ans += a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		sort(a, a + n);
		sort(b, b + n);
		
		vector<int> v;
		for (int i = 0; i < n; i++) {
			v.push_back(b[n - i - 1] - a[i]);
		}
		
		for (int i = 0; i < n; i++) {
			if (k > 0 && v[i] > 0) {
				k--;
				ans += v[i];
			}
		}
		cout << ans << endl;
	}
}