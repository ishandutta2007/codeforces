#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define gao(x) cerr << #x << " = " << x << "\n"
#define pb push_back
#define sz(x) (int)x.size()
#define fi first
#define se second
#define ll long long
 
using namespace std;

const int N = 1 << 20;
const int P = 1e9 + 7;

int pw(int a, int b) {
	int c = 1;
	for (; b; a = 1ll * a * a % P, b /= 2)
		if (b & 1)
			c = 1ll * c * a % P;
	return c;
}

ll n, fac[N], rev[N];

ll C(int a, int b) {
	return fac[a] * rev[a - b] % P * rev[b] % P;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	fac[0] = rev[0] = 1;
	rep(i, 1, N - 1) {
		fac[i] = fac[i - 1] * i % P;
		rev[i] = pw(fac[i], P - 2);
	}	
	ll res = 0;
	rep(i, 0, n) {
		if (i % 2 == n % 2 && n - i >= i)
			res = (res + fac[n - i - 1] * C(n - i - i + i, i)) % P;
	}
	cout << 2 * res * n % P << "\n";
	return 0;
}