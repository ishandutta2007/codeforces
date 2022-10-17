#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
//#define F first
#define S second

const int N = 2010;
int a[N][N], xx[N], yy[N];

signed main() {
	int n;
	cin >> n;
	int ptr = 0;
	for (int i = 1; i <= n; i += 2) {
		for (int j = 1; j <= n; j += 2) {
			a[i][j] = ptr;
			a[i + 1][j + 1] = ptr + 2; 
			a[i + 1][j] = ptr + 3;
			a[i][j + 1] = ptr + 1;
			ptr += 4;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	//cerr << "TME :: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
}