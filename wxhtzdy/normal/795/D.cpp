#include <bits/stdc++.h>

using namespace std;

int main() {
 	int n, l, r;
 	cin >> n >> l >> r;
 	vector<int> a(n); 
 	vector<int> b(n);               
 	vector<int> cnt(n + 1, 0);
 	for (int i = 0; i < n; i++) {
 	 	cin >> a[i];
 	 	if (i + 1 >= l && i + 1 <= r) {
 	 	 	cnt[a[i]]++;
 	 	}
 	}
 	for (int i = 0; i < n; i++) {
 	 	cin >> b[i];
 	}
 	bool ok = true;
 	for (int i = 0; i < n; i++) {
 	 	if (a[i] != b[i] && (i + 1 < l || i + 1 > r)) {
 	 	 	ok = false;
 	 	}
 	 	if (i + 1 >= l && i + 1 <= r) {
 	 	 	if (cnt[b[i]] > 0) {
 	 	 	 	cnt[b[i]]--;
 	 	 	} else {
 	 	 	 	ok = false;
 	 	 	}
 	 	}
 	}
 	if (ok == true) {
 	  cout << "TRUTH";
 	} else {
 	 	cout << "LIE";
	}
}