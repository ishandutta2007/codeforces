#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;	

const int N = 2020;
const int P = 1e9 + 7;

int n, m, ds[N][N], du[N][N], d[N][N], r[N][N]; 
char s[N][N];

void add(int &a, int b) {
	a = (1ll * a + b + P) % P;
}

int main() {
	cin >> n >> m;
	rep(i, 1, n + 1)
		cin >> s[i] + 1;
		
	rep(i, 1, n + 1) 
		per(j, 1, m)
			r[i][j] = r[i][j + 1] + (s[i][j + 1] == 'R');
			
	per(i, 1, n)
		rep(j, 1, m + 1)
			d[i][j] = d[i + 1][j] + (s[i + 1][j] == 'R');
		
	ds[1][1] = 1;
	ds[1][2] = -1;
	du[1][1] = 1;
	du[2][1] = -1;
	
	rep(i, 1, n + 1)
		rep(j, 1, m + 1) {
			add(ds[i][j + 1], du[i][j]);
			add(ds[i][m - r[i][j] + 1], -du[i][j]);
			
			add(du[i + 1][j], ds[i][j]);
			add(du[n - d[i][j] + 1][j], -ds[i][j]);
			
			add(ds[i][j + 1], ds[i][j]);
			add(du[i + 1][j], du[i][j]);
		}
	cout << (ds[n][m] + du[n][m] - (n == 1 && m == 1)) % P;
	return 0;
}