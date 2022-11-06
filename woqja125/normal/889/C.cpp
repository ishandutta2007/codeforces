#include<cstdio>
using namespace std;
int dp[1000010];
const int MOD = 1000000007;
struct node {
	int sum=0;
	int mul=1;
	node *l, *r;

	void init(int x, int y);
	void mu(int s, int e, int x, int y, int v) {
		int m = (s + e) / 2;
		if (e < x || s > y) return;
		if (x <= s && e <= y) {
			mul = 1ll * mul*v%MOD;
			sum = 1ll * sum*v%MOD;
			return;
		}
		l->mu(s, m, x, y, v);
		r->mu(m + 1, e, x, y, v);
		sum = 1ll * (0ll + l->sum + r->sum % MOD) * mul % MOD;
	}
	void set(int l, int x, int y, int v) {
		if (x == l && y == l) {
			sum = v * mul;
			return;
		}
		int m = (x+y)/2;
		if (l <= m) this->l->set(l, x, m, v);
		else r->set(l, m + 1, y, v);
	}
	int getsum(int s, int e, int x, int y) {
		int m = (s + e) / 2;
		if (e < x || s > y) return 0;
		if (x <= s && e <= y) return sum;
		return (0ll + l->getsum(s, m, x, y) + r->getsum(m + 1, e, x, y)) % MOD * mul % MOD;
	}
} ST[2000001];
int C = 0;
node *nn() {
	return ST + C++;
}
int fact[1000010];
int inv[1000010];
int fi[1000010];
int P(int n, int r) {
	return 1ll * fact[n] * fi[n - r] % MOD;
}
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	fact[0] = fact[1] = inv[1] = fi[1] = fi[0] = 1;
	for (int i = 2; i <= n; i++) fact[i] = 1ll * fact[i - 1] * i % MOD;
	for (int i = 2; i <= n; i++) inv[i] = (0ll + MOD - (MOD / i))*inv[MOD%i] % MOD;
	for (int i = 2; i <= n; i++) fi[i] = 1ll * fi[i - 1] * inv[i] % MOD;
	int s = P(n-1, n-1);
	node *r = nn();
	r->init(1, n);
	r->set(1, 1, n, 1);
	for(int i=2; i<=n; i++){
		int t = r->getsum(1, n, i - k, i - 1);
		r->set(i, 1, n, t);
		s = (0ll + s + 1ll * t * P(n - 1, n - i)%MOD) % MOD;
		r->mu(1, n, i-k-1, i-1, i - 1);
	}
	int f = 1;
	f = (0ll + MOD + fact[n] - s)%MOD;
	printf("%d\n", f);
	return 0;
}

void node::init(int x, int y) {
	int m = (x + y) / 2;
	if (x == y) return;
	l = nn();
	r = nn();
	l->init(x, m);
	r->init(m + 1, y);
}