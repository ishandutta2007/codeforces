#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		int a[n], b[n];
		bool was[2];
		was[0] = was[1] = false;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			was[b[i]] = true;
		}
		if (was[0] == false || was[1] == false) {
			bool ok = true; 
			for (int i = 1; i < n; i++) {
				if (a[i] < a[i - 1]) {
					ok = false;
					break;
				}
			}
			if(ok) {
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
		} else {
			cout << "Yes" << endl;
		}
	}
	return 0;
}