#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int mod = 998244353;

namespace {
	int add(int x) {return (x >= mod) ? x - mod : x;}
	int sub(int x) { return (x < 0) ? x + mod : x;}
	void Add(int &x, int y) {x = add(x + y);}
	void Sub(int &x, int y) {x = sub(x - y);}
	int Pow(int x, int y = mod - 2) {
		int res = 1;
		for(; y; y >>= 1, x = 1LL * x * x % mod) {
			if(y & 1)
			res = 1LL * res * x % mod;
		}
		return res;
	}
}

int n, m, A[N], t, f[N], rf[N];
int C(int x, int y) {
	return 1LL * f[x] * rf[y] % mod * rf[x - y] % mod;
}

char s[N];

int main() {
	n = 1e5; f[0] = 1;
	for(int i = 1; i <= n; ++ i)
	f[i] = 1LL * f[i - 1] * i % mod;
	rf[n] = Pow(f[n]);
	for(int i = n - 1; i >= 0; -- i)
	rf[i] = 1LL * rf[i + 1] * (i + 1) % mod;
	for(cin >> t; t --;) {
		scanf("%d", &n);
		scanf("%s", s + 1);
		n = strlen(s + 1);
		int l = 0, r = 0;
		for(int i = 1; i <= n; ++ i) {
			if(s[i] == '0') {
				++ r; continue;
			}
			
			if(i + 1 <= n && s[i + 1] == '1') {
				++ l; ++ i; continue;
			}
			
		}
		cout << C(l + r, l) << endl;
	}
}