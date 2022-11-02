#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

int a[MAXN];

int main() {
	int n, k, s = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}
	if (s % k == 0) {
		vector < int > ans;
		int c = 0, l = 0;
		for (int i = 0; i < n; i++) {
			c += a[i];
			l++;
			if (c == s / k) {
				ans.push_back(l);
				l = 0;
				c = 0;
			} else if (c > s / k) {
				cout << "No" << endl;
				return 0;
			}
		}
		cout << "Yes" << endl;
		for (int x : ans)
			cout << x << ' ';
		cout << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}