#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
		cin >> a[i];
  }
	if (k == 1) {
		cout << *min_element(a.begin(), a.end()) << '\n';
		return 0;
	}
	if (k == 2) {
		cout << max(a[0], a[n - 1]) << '\n';
		return 0;
	}
	cout << *max_element(a.begin(), a.end()) << '\n';
  return 0;
}