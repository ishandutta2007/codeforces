#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
typedef long long ll;
using namespace std;

const int N = 1e6 + 2020;
const int P = 998244353;

ll power(ll a, ll b) {
	ll res = 1;
	for (; b; a = a * a % P, b /= 2)
		if (b & 1)
			res = res * a % P;
	return res;
}

ll fac[N], inv[N], sieve[N];

void init() {
	fac[0] = inv[0] = 1;
	rep(i, 1, N) {
		fac[i] = fac[i - 1] * i % P;
		inv[i] = power(fac[i], P - 2);
	}
	
	rep(i, 2, N) 
		if (!sieve[i])
			rep(j, 2, (N - 1) / i + 1)
				sieve[i * j] = 1;
}

ll C(int n, int k) {
	return fac[n] * inv[n - k] % P * inv[k] % P;
}

int T, n;
string s;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	init();

	cin >> T;
	while (T--) {
		cin >> n >> s;
		int white = 0;
		int pairs = 0;
		for (int i = 0; i < n;) {
			if (s[i] == '0') {
				white++;
				i++;
				continue;
			}
			int j = i;
			while (j < n && s[j] == '1')
				j++;
			pairs += (j - i) / 2;
			i = j;
		}
		cout << C(white + pairs, pairs) << endl;
	}

	return 0;
}