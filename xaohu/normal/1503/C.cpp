#include <bits/stdc++.h>

using namespace std;

int n;
pair<int, int> a[111000];
long long ans;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a[i] = {x, x + y};
		ans += y;
	}
	sort(a, a + n);
	int border = a[0].first;
	for (int i = 0; i < n; i++) {
		ans += max(0, a[i].first - border);
		border = max(border, a[i].second);
	}
	cout << ans << "\n";	
	return 0;
}