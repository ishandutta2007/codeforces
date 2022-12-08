#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll pw(ll a, ll b) {
	ll an = 1;
	for (; b; b >>= 1) {
		if (b & 1) an = an * a % mod;
		a = a * a % mod;
	}
	return an;
}
const int N = 111111;
int x, y, q[N], f[N], n;
int main() {
	scanf("%d%d", &x, &y);
	if (y % x != 0) return puts("0"), 0;
	y /= x;
	for (int i = 1; i * i <= y; ++i) if (y % i == 0) {
		q[++n] = i;
		if (i * i != y) q[++n] = y / i;
	}
	sort(q + 1, q + n + 1);
	for (int i = n; i; --i) {
		f[i] = pw(2, y / q[i] - 1);
		for (int j = i + 1; j <= n; ++j) 
			if (q[j] % q[i] == 0) f[i] = (f[i] - f[j] + mod) % mod;
	}
	cout << f[1] << endl;
	return 0;
}