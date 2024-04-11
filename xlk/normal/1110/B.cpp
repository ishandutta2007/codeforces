#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[100020];
vector<int> b;
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = a[n - 1] - a[0] + 1;
	for (int i = 1; i < n; i++) {
		b.push_back(a[i] - a[i - 1] - 1);
	}
	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());
	for (int i = 0; i < k - 1; i++) {
		ans -= b[i];
	}
	printf("%d\n", ans);
	return 0;
}