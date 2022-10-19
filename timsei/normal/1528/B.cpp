#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int mod = 998244353;

namespace {
	int add(int x) {return (x >= mod) ? x - mod : x;}
	int sub(int x) {return (x < 0) ? x + mod : x;}
	void Add(int &x, int y) { x = add(x + y);} 
	void Sub(int &x, int y) {x = sub(x - y);}
	
	int Pow(int x, int y) {
		int res = 1;
		for(; y; y >>= 1, x = 1LL * x * x % mod)  
		if(y & 1)
		res = 1LL * res * x % mod;
		return res;
	}
}

int n, ans, dp[N], S[N];

int main() {
	cin >> n;
	dp[0] = 1; S[0] = 1;
	for(int i = 1; i <= n; ++ i) {
		for(int j = i * 2; j <= n;j += i) {
			dp[j] ++;
		}
	}
	for(int i = 1; i <= n; ++ i) {
		S[i] = S[i - 1];
		Add(dp[i], S[i - 1]);
		Add(S[i], dp[i]);
	}
	cout << dp[n] << endl;
}