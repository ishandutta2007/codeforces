#include <cstdio>
#include <cstring>
using namespace std;

using cat = long long;
constexpr cat mod = 998244353;
constexpr cat MX = 1'000'000;
cat fac[MX+10];
cat fac_inv[MX+10];

cat pw(cat a, cat e) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2);
	return (e%2) ? x * x % mod * a % mod : (x * x % mod);
}

int main() {
	fac[0] = fac_inv[0] = 1;
	for(int i = 1; i <= MX; i++) {
		fac[i] = fac[i-1] * i % mod;
		fac_inv[i] = (i > 2 && i%2 == 0) ? fac_inv[2] * fac_inv[i/2] % mod : pw(i, mod-2);
	}
	for(int i = 1; i <= MX; i++) fac_inv[i] = fac_inv[i] * fac_inv[i-1] % mod;
	char S[MX+10];
	scanf("%s", S);
	int N = strlen(S), N_q = 0;
	for(int i = 0; i < N; i++) if(S[i] == '?') N_q++;
	cat C[2][MX+10];
	for(int k = 0; k < 2; k++) if(N_q-k >= 0) {
		for(int i = 0; i <= N_q-k; i++)
			C[k][i] = fac[N_q-k] * fac_inv[i] % mod * fac_inv[N_q-k-i] % mod;
		for(int i = N_q-k+1; i <= N+1; i++) C[k][i] = 0;
		for(int i = 1; i <= N+1; i++) C[k][i] = (C[k][i] + C[k][i-1]) % mod;
	}
	int ans = 0, n_op = 0, n_cl = 0, n_right_q = N_q;
	for(int i = 0; i < N; i++) if(S[i] == ')') n_cl++;
	for(int i = 0; i < N; i++) {
		if(S[i] == '(') n_op++;
		if(S[i] == ')') n_cl--;
		if(S[i] == '?') n_right_q--;
		if(S[i] == '?' || S[i] == '(') if(n_right_q+n_cl-n_op-(S[i]=='?') >= 0) {
			ans += C[S[i] == '?'][n_right_q+n_cl-n_op-(S[i]=='?')];
			if(ans >= mod) ans -= mod;
		}
	}
	printf("%d\n", ans);
}