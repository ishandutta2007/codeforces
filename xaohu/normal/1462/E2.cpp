#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int>
typedef long long ll;	
using namespace std;

const int N = 200200;
const int M = 105;
const int P = 1e9 + 7;
int T, n, m, k;
int a[N], C[N][M];

int main() { 
	rep(i, 0, N) {
		C[i][0] = 1;
		rep(j, 1, min(i + 1, M))
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
	}

	cin >> T;
	while (T--) {
		cin >> n >> m >> k;
		rep(i, 0, n)
			cin >> a[i];
		sort(a, a + n);
		int res = 0;
		rep(i, 0, n) 
			res = (res + C[i - (lower_bound(a, a + n, a[i] - k) - a)][m - 1]) % P;
		cout << res << "\n";
	}
	return 0;
}