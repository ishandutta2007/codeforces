#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int mod = 998244353;

int T, n, m, x, y, A[N], S[N], l, C[N][N], k;
char s[N];

void rmain() {
	scanf("%d", &n);
	cin >> k;
	scanf("%s", s + 1);
	int ans = 0;
	for(int i = 1; i <= n; ++ i) s[i] -= '0', S[i] = S[i - 1] + s[i];
	for(int i = 1; i <= n; ++ i) {
		if(S[n] - S[i - 1] < k) break;
		if(S[n] - S[i - 1] == k) {
			l = n;
		} else {
			for(l = n; l >= 1; -- l) {
				if(S[l] - S[i - 1] == k) break;
			}
		}
		// [i, l]
		if(i > l) continue;
		if(k >= (s[i] == 0))
		ans = (ans + C[l - i][k - (s[i] == 0)]) % mod;
		if(S[n] - S[i] < k)  {
			int one = k, zero = (i - l + 1) - one;
			for(int j = i; j < n; ++ j) {
				if(s[j] == 1) -- one; else -- zero;
				ans = ans + (C[n - j - 1][one - (s[j + 1] == 0)]);
				ans %= mod;
			}
		}
	}
	cout << (ans + 1) % mod << endl;
} 

int main() {
	C[0][0] = 1;
	for(int i = 1; i < N; ++ i) {
		C[i][0] = 1;
		for(int j = 1; j < N; ++ j)
		C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	}
	for(T = 1; T --;) rmain();
}