#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second
 
bool f(int a, int b) {
	return (a == b ? 1 : 0);
}
 
signed main() {
	int n;
	cin >> n;
	vector<vector<int>> a(n + 1, vector<int>(n + 1));
	a[1][1] = 1;
	a[2][1] = 1;
	cout << "? 2 1 2 3" << endl;
	int can;
	cin >> can;
	if (can) {
		a[2][3] = a[2][1];
	}
	else {
		a[2][3] = a[2][1] ^ 1;
	}
	cout << "? 1 2 2 3" << endl;
	cin >> can;
	if (can) {
		a[1][2] = a[2][3];
	}
	else {
		a[1][2] = a[2][3] ^ 1;
	}
	cout << "? 1 1 2 2" << endl;
	cin >> can;
	if (can) {
		a[2][2] = a[1][1];
	}
	else {
		a[2][2] = a[1][1] ^ 1;
	}
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= 2; j++) {
			cout << "? " << i - 2 << ' ' << j << ' ' << i << ' ' << j << endl;
			int can;
			cin >> can;
			if (can) {
				a[i][j] = a[i - 2][j];
			}
			else {
				a[i][j] = a[i - 2][j] ^ 1;
			}
		}
	}
	vector<int> to(2);
	for (int i = 1; i <= n; i++) {
		for (int j = 3; j <= n; j++) {
			if (i == n && j == n) {
				continue;
			}
			if (i == 2 && j == 3) {
				continue;
			}
			cout << "? " << i << ' ' << j - 2 << ' ' << i << ' ' << j << endl;
			int can;
			cin >> can;
			if (can) {
				a[i][j] = a[i][j - 2];
			}
			else {
				a[i][j] = a[i][j - 2] ^ 1;
			}
		}
	}
	bool ok = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i + 3 <= n) {
				if (f(a[i][j], a[i + 3][j]) == f(a[i + 1][j], a[i + 2][j])) {
					ok = true;
					cout << "? " << i << ' ' << j << ' ' << i + 3 << ' ' << j << endl;
					int can;
					cin >> can;
					if (i % 2 == j % 2) {
						if (can) {
							to[a[i + 3][j]] = a[i][j];
							to[a[i + 3][j] ^ 1] = a[i][j] ^ 1;
						}
						else {
							to[a[i + 3][j]] = a[i][j] ^ 1;
							to[a[i + 3][j] ^ 1] = a[i][j];
						}
					}
					else {
						if (can) {
							to[a[i][j]] = a[i + 3][j];
							to[a[i][j] ^ 1] = a[i + 3][j] ^ 1;
						}
						else {
							to[a[i][j]] = a[i + 3][j] ^ 1;
							to[a[i][j] ^ 1] = a[i + 3][j];
						}
					}
					break;
				}
			}
			if (j + 3 <= n) {
				if (f(a[i][j + 3], a[i][j]) == f(a[i][j + 1], a[i][j + 2])) {
					ok = true;
					cout << "? " << i << ' ' << j << ' ' << i << ' ' << j + 3 << endl;
					int can;
					cin >> can;
					if (i % 2 == j % 2) {
						if (can) {
							to[a[i][j + 3]] = a[i][j];
							to[a[i][j + 3] ^ 1] = a[i][j] ^ 1;
						}
						else {
							to[a[i][j + 3]] = a[i][j] ^ 1;
							to[a[i][j + 3] ^ 1] = a[i][j];
						}
					}
					else {
						if (can) {
							to[a[i][j]] = a[i][j + 3];
							to[a[i][j] ^ 1] = a[i][j + 3] ^ 1;
						}
						else {
							to[a[i][j]] = a[i][j + 3] ^ 1;
							to[a[i][j] ^ 1] = a[i][j + 3];
						}	
					}
					break;
				}
			}
			if (i + 1 <= n && j + 2 <= n) {
				int vl = f(a[i][j], a[i + 1][j + 2]);
				bool fuck = false;
				if (f(a[i + 1][j], a[i + 1][j + 1]) == vl) fuck = true;
				if (f(a[i][j + 1], a[i][j + 2]) == vl) fuck = true;
				if (f(a[i][j + 1], a[i + 1][j + 1]) == vl) fuck = true;
				if (fuck) {
					ok = true;
					cout << "? " << i << ' ' << j << ' ' << i + 1 << ' ' << j + 2 << endl;
					int can;
					cin >> can;
					if (i % 2 == j % 2) {
						if (can) {
							to[a[i + 1][j + 2]] = a[i][j];
							to[a[i + 1][j + 2] ^ 1] = a[i][j] ^ 1;
						}
						else {
							to[a[i + 1][j + 2]] = a[i][j] ^ 1;
							to[a[i + 1][j + 2] ^ 1] = a[i][j];
						}
					}
					else {
						if (can) {
							to[a[i][j]] = a[i + 1][j + 2];
							to[a[i][j] ^ 1] = a[i + 1][j + 2] ^ 1;
						}
						else {
							to[a[i][j]] = a[i + 1][j + 2] ^ 1;
							to[a[i][j] ^ 1] = a[i + 1][j + 2];
						}	
					}
					break;
				}
			}
			if (i + 2 <= n && j + 1 <= n) {
				int vl = f(a[i][j], a[i + 2][j + 1]);
				bool fuck = false;
				if (f(a[i + 1][j], a[i + 1][j + 1]) == vl) fuck = true;
				if (f(a[i + 1][j], a[i + 2][j]) == vl) fuck = true;
				if (f(a[i][j + 1], a[i + 1][j + 1]) == vl) fuck = true;
				if (fuck) {
					ok = true;
					cout << "? " << i << ' ' << j << ' ' << i + 2 << ' ' << j + 1 << endl;
					int can;
					cin >> can;
					if (i % 2 == j % 2) {
						if (can) {
							to[a[i + 2][j + 1]] = a[i][j];
							to[a[i + 2][j + 1] ^ 1] = a[i][j] ^ 1;
						}
						else {
							to[a[i + 2][j + 1]] = a[i][j] ^ 1;
							to[a[i + 2][j + 1] ^ 1] = a[i][j];
						}
					}
					else {
						if (can) {
							to[a[i][j]] = a[i + 2][j + 1];
							to[a[i][j] ^ 1] = a[i + 2][j + 1] ^ 1;
						}
						else {
							to[a[i][j]] = a[i + 2][j + 1] ^ 1;
							to[a[i][j] ^ 1] = a[i + 2][j + 1];
						}	
					}
					break;
				}
			}
		}
		if (ok) {
			break;
		}
	}
	assert(ok);
	cout << "!" << '\n';
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i % 2 == j % 2) {
				cout << a[i][j];
			}
			else {
				cout << to[a[i][j]];
			}
		}
		if (i != n) cout << '\n';
		else cout << endl;
	}
	//cerr << "TIME :: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
}