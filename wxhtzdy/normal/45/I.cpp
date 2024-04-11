#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int  i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			cnt++;
		}
	}
	vector<int> v;
	for (int  i = 0; i < n; i++) {
		if (a[i] == 0 || (cnt % 2 == 1 && i == cnt - 1)) {
			continue;
		} else {
			v.push_back(a[i]);
		}
	}
	if ((int) v.size() == 0) {
		v.push_back(a[n - 1]);
	} 
	for (int i = 0; i < (int) v.size(); i++) {
		cout << v[i] << " ";
	}
	return 0;
}