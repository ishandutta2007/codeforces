#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define int ll

int ans[510][510];

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	if (n == 1 && m == 1) {
		cout << 0 << '\n';
		exit(0);
	}
	if (m == 1) {
		for (int i = 1; i <= n; i++) {
			cout << i + 1 << '\n';
		}
		exit(0);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << (n + j) * i << ' '; 
		}
		cout << '\n';
	}
	/*for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			if (i == 1 && j == 1) {
				continue;
			}
			for (int ii = 1; ii <= i; ii++) {
				for (int jj = 1; jj <= j; jj++) {
					ans[ii][jj] = (i + jj) * ii;
				}
			}
			set<int> st;
			for (int ii = 1; ii <= i; ii++) {
				int cg = 0;
				for (int jj = 1; jj <= j; jj++) {
					cg = __gcd(cg, ans[ii][jj]);
				}
				st.insert(cg);
			}
			for (int jj = 1; jj <= j; jj++) {
				int cg = 0;
				for (int ii = 1; ii <= i; ii++) {
					cg = __gcd(cg, ans[ii][jj]);
				}
				st.insert(cg);
			}
			if (SZ(st) != i + j) {
				cout << i << ' ' << j << '\n';
			}
		}
	}*/	
}