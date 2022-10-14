#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > x) {
			cnt += 2;
		}	else {
		 	cnt++;
		}
	}	
	cout << cnt;
}