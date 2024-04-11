#include <bits/stdc++.h>

using namespace std;

int main() {
	string a, b, c;
	cin >> a >> b >> c;
	map<int, int> m;
	for (int i = 0; i < (int) c.length(); i++) {
	 	int x = (int) (c[i] - 'A');
	 	m[x]++;
	}
	bool ok = true;
	for (int i = 0; i < (int) a.length(); i++) {
		int x = (int) (a[i] - 'A');
		if (m[x] > 0) {
		 	m[x]--;
		} else {
		 	ok = false;
		}
	}
	for (int i = 0; i < (int) b.length(); i++) {
		int x = (int) (b[i] - 'A');
		if (m[x] > 0) {
		 	m[x]--;
		} else {
		 	ok = false;
		}
	}
	for (int i = 0; i < 26; i++) {
	 	if (m[i] > 0) {
	 	 	ok = false;
	 	}
	}
	cout << (ok ? "YES" : "NO");
}