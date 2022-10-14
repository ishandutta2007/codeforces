#include <bits/stdc++.h>

using namespace std;

int main() {                                 
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
	 	cin >> a[i];
	}
	int l = a[0], h = a[0];
	int cnt = 0;
	for (int i = 1; i < n; i++) {
	 	if (a[i] < l || a[i] > h) {
	 	 	cnt++;
	 	}
	 	l = min(l, a[i]);
	 	h = max(h, a[i]);
	}
	cout << cnt;
}