#include <iostream>
#include <vector>
using namespace std;

using cat = long long;

int main() {
	int N;
	cin >> N;
	cat mod = 998244353;
	vector<cat> fac(N+1, 1), dec_fac(N+1, 1);
	for(int i = 1; i <= N; i++) fac[i] = fac[i-1] * i % mod;
	for(int i = 0; i < N; i++) dec_fac[i+1] = dec_fac[i] * (N-i) % mod;
	long long ans = (fac[N]-1) * (fac[N]-2) % mod * N % mod * N % mod * 499122177 % mod;
	for(int i = 1; i <= N; i++) ans += dec_fac[i] % mod;
	for(int i = 1; i <= N-1; i++) ans += dec_fac[N-i] * (fac[i]-1) % mod;
	ans += (N > 1) + 3LL * (N-1) * (N-1) % mod;
	for(int i = 1; i <= N-2; i++) {
		cat c = (1LL*i*i+1) * (i+2) % mod * (N-i) % mod + (3LL*i+5LL) * i * i % mod;
		ans += dec_fac[N-i-2] * c % mod;
	}
	ans %= mod;
	cout << ans << "\n";
}