#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int mod;
namespace {
	int add(int x) {return (x >= mod) ? x - mod : x;}
	void Add(int &x, int y) {x = add(x + y);}
	int sub(int x) {return (x < 0) ? x + mod : x;}
	void Sub(int &x, int y) {x = sub(x - y);}
	int Pow(int x, int y = mod - 2) {
		int res = 1;
		for(; y; y >>= 1, x = 1LL * x * x % mod) 
		if(y & 1)
		res = 1LL * res * x % mod;
		return res;
	}
}

int dp[N][N][N], n, m, k, C[N][N], fac[N];
bool vis[N][N][N];

int solve(int n, int m, int k) {
	if(k < 0) return 0;
	if(vis[n][m][k]) return dp[n][m][k];
	if(n == 0) {
		if(!k) return 1;
		else return 0;
	}
	
	if(n == 1) {
		if(m == 1 && k == 1) return 1;
		else if(m != 1 && !k) return fac[n];
		else return 0;
	}
	
	if(!m) {
		if(k) return 0;
		else return fac[n];
	}
	
	if(m == 1) {
		if(k != 1) return 0;
		else return fac[n];
	}
	
	int &res = dp[n][m][k];
	
	vis[n][m][k] = 1;
	
	if(m == 1) {
		if(k == 1) {
			return 1LL * solve(n - 1, 1, 1) * n % mod;
		}
	}
	
	vis[n][m][k] = 1;
	
	long long rude = 1LL * mod * mod;
	
	for(int i = 1; i <= (n + 1) / 2; ++ i) {
		long long ans = 0;
		for(int l = 0; l < min(i, k + 1); ++ l) {
			ans += 1LL  * solve(i - 1, m - 1, l) * solve(n - i, m - 1, k - l);
			(ans >= rude) ? ans -= rude : 0;
		}
		ans = ans % mod;
		if(i + i - 1 != n) {
			ans = add((int)(ans + ans));
		}
		Add(res, 1LL * C[n - 1][i - 1] * ans % mod);
	}
	
	return res;
}

int main() {
	cin >> n >> m >> k >> mod;
	C[0][0] = 1; fac[0] = 1;
	for(int i = 1; i <= n; ++ i) fac[i] = 1LL * i * fac[i - 1] % mod;
	for(int i = 1; i <= 100; ++ i) {
		C[i][0] = 1;
		for(int j = 1; j <= 100; ++ j) {
			C[i][j] = add(C[i - 1][j - 1] + C[i - 1][j]);
		}
	}
	cout << solve(n, m, k) << endl;
}