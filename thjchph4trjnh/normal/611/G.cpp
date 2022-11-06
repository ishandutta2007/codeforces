#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) ((n) & (1LL << (i)))
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = (int) 1e9 + 7) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

const int maxn = 500010;
const int maxe = 25;
int n;
ll x[maxn << 1];
ll y[maxn << 1];
int sumx[maxn << 1];
int sumy[maxn << 1];
ll sum[maxn << 1];
int stb[maxn << 1][maxe];

int calcx(int a, int b) {
	if (a > b) return 0;
	if (!a) return sumx[b];
	return (sumx[b] - sumx[a - 1] + MOD) % MOD;
}

int calcy(int a, int b) {
	if (a > b) return 0;
	if (!a) return sumy[b];
	return (sumy[b] - sumy[a - 1] + MOD) % MOD;
}

ll ccross(int a, int b) {
	if (a > b) return 0;
	if (b < n) {
		if (!a) return sum[b];
		return sum[b] - sum[a - 1];
	}
	else {
		return sum[n - 1] - ccross(b - n + 1, a - 1);
	}
}

int calc(int a, int b) {
	int k = b - a;
	int res = 0;
	FORd(i, maxe, 0) {
		ll t = 1 << i;
		if (k >= t) {
			res = (res + stb[a][i] + (k - t) * (ccross(a, a + t - 1) % MOD)) % MOD;
			k -= t; a += t;
		}
	}
	return res;
}

int calc(int a, int b, int c) {
	ll res = calc(b, c);
	ll t = -x[a] * y[b] + x[b] * y[a];
	t = (t % MOD + MOD) % MOD;
	res = (res + t * (c - b)) % MOD;
	res += x[a] * calcy(b + 1, c) - y[a] * calcx(b + 1, c);
	res = (res % MOD + MOD) % MOD;
	return res;
}

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) {
		scanf("%I64d%I64d", x + i, y + i);
		x[i + n] = x[i]; y[i + n] = y[i];
	}
	ll area = 0;
	FOR(i, 0, n << 1) {
		if (!i) {
			sumx[i] = x[i] % MOD;
			sumy[i] = y[i] % MOD;
		}
		else {
			sumx[i] = (sumx[i - 1] + x[i]) % MOD;
			sumy[i] = (sumy[i - 1] + y[i]) % MOD;
		}
		sumx[i] = (sumx[i] + MOD) % MOD;
		sumy[i] = (sumy[i] + MOD) % MOD;
		ll cross = -1LL * x[i] * y[(i + 1) % n] + 1LL * x[(i + 1) % n] * y[i];
		if (i < n) area += cross;
		if (!i) sum[i] = cross;
		else sum[i] = sum[i - 1] + cross;
		stb[i][0] = (cross % MOD + MOD) % MOD;
	}
	FOR(k, 1, maxe) {
		FOR(i, 0, n << 1) {
			ll t = 1 << (k - 1);
			if (i + 2 * t <= 2 * n)
				stb[i][k] = (t * (ccross(i, i + t - 1) % MOD) + stb[i][k - 1] + stb[i + t][k - 1]) % MOD;
		}
	}
	ll ans = 0;
	FOR(i, 0, n) {
		int l = i + 2, r = i + n - 2;
		while (l < r) {
			int m = (l + r) >> 1;
			ll tot = ccross(i, m - 1);
			tot += x[i] * y[m] - x[m] * y[i];
			if (tot < (area + 1) / 2) l = m + 1; else r = m;
		}
		ll cur = ccross(i, l - 1) + x[i] * y[l] - x[l] * y[i];
		if (cur >= (area + 1) / 2) {
			cur %= MOD;
			int k = i + n - l - 1;
			if (k > 0) {
				ans += 2 * (k * cur + calc(i, l, i + n - 2)) - area % MOD * k;
				ans = (ans % MOD + MOD) % MOD;
			}
		}
		else l++;
		int k = l - i - 2;
		if (k > 0) {
			ans += area % MOD * k - 2 * calc(i, i + 1, l - 1);
			ans = (ans % MOD + MOD) % MOD;
		}
	}
	ans = ans * fpow(2, MOD - 2) % MOD;
	printf("%I64d", ans);
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}