#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i == 0 || a[i] != a[i - 1]) {
		 	cnt++;
		}
	}
	cout << cnt;
}