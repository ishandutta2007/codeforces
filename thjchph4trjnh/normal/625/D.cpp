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
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}

const int maxn = 100010;
int n;
int a[maxn];
int b[maxn];

int check() {
	if (!b[0]) return 0;
	int r = 0;
	FOR(i, 0, n) {
		int d = (b[i] + b[n - i - 1] + r) % 10;
		r = (b[i] + b[n - i - 1] + r) / 10;
		if (d != a[n - i - 1]) return 0;
	}
	return 1;
}

void go1() {
	int r1 = 0, r2 = 0;
	FOR(i, 0, (n + 1) >> 1) {
		if (a[i] == (a[n - i - 1] - r1 + 10) % 10) {
			if (r2) {
				if (i == n - i - 1) {
					if (a[i] & 1) return;
					b[i] = b[n - i - 1] = a[i] / 2 + 5;
				}
				else {
					b[i] = 9;
					b[n - i - 1] = a[i] + 1;
				}
				if (a[i] == 9) return;
				r1 = (b[i] + b[n - i - 1] + r1) / 10;
			}
			else {
				if (i == n - i - 1) {
					if (a[i] & 1) return;
					b[i] = b[n - i - 1] = a[i] / 2;
				}
				else {
					b[i] = a[i];
					b[n - i - 1] = 0;
				}
				r1 = (b[i] + b[n - i - 1] + r1) / 10;
			}
			r2 = 0;
		}
		else if ((a[i] + 9) % 10 == (a[n - i - 1] - r1 + 10) % 10) {
			if (r2) {
				if (i == n - i - 1) {
					if (!(a[i] & 1)) return;
					b[i] = b[n - i - 1] = (a[i] + 9) / 2;
				}
				else {
					b[i] = 9;
					b[n - i - 1] = a[i];
				}
				r1 = (b[i] + b[n - i - 1] + r1) / 10;
			}
			else {
				if (!a[i]) return;
				if (i == n - i - 1) {
					if (!(a[i] & 1)) return;
					b[i] = b[n - i - 1] = (a[i] - 1) / 2;
				}
				else {
					b[i] = a[i] - 1;
					b[n - i - 1] = 0;
				}
				r1 = (b[i] + b[n - i - 1] + r1) / 10;
			}
			r2 = 1;
		}
		else return;
	}
	if (check()) {
		FOR(i, 0, n) cout<<b[i];
		exit(0);
	}
}

void go2() {
	if (a[0] != 1) return;
	n--; FOR(i, 0, n) a[i] = a[i + 1];
	int r1 = 0, r2 = 1;
	FOR(i, 0, (n + 1) >> 1) {
		if (a[i] == (a[n - i - 1] - r1 + 10) % 10) {
			if (r2) {
				if (i == n - i - 1) {
					if (a[i] & 1) return;
					b[i] = b[n - i - 1] = a[i] / 2 + 5;
				}
				else {
					b[i] = 9;
					b[n - i - 1] = a[i] + 1;
				}
				if (a[i] == 9) return;
				r1 = (b[i] + b[n - i - 1] + r1) / 10;
			}
			else {
				if (i == n - i - 1) {
					if (a[i] & 1) return;
					b[i] = b[n - i - 1] = a[i] / 2;
				}
				else {
					b[i] = a[i];
					b[n - i - 1] = 0;
				}
				r1 = (b[i] + b[n - i - 1] + r1) / 10;
			}
			r2 = 0;
		}
		else if ((a[i] + 9) % 10 == (a[n - i - 1] - r1 + 10) % 10) {
			if (r2) {
				if (i == n - i - 1) {
					if (!(a[i] & 1)) return;
					b[i] = b[n - i - 1] = (a[i] + 9) / 2;
				}
				else {
					b[i] = 9;
					b[n - i - 1] = a[i];
				}
				r1 = (b[i] + b[n - i - 1] + r1) / 10;
			}
			else {
				if (!a[i]) return;
				if (i == n - i - 1) {
					if (!(a[i] & 1)) return;
					b[i] = b[n - i - 1] = (a[i] - 1) / 2;
				}
				else {
					b[i] = a[i] - 1;
					b[n - i - 1] = 0;
				}
				r1 = (b[i] + b[n - i - 1] + r1) / 10;
			}
			r2 = 1;
		}
		else return;
	}
	if (check()) {
		FOR(i, 0, n) cout<<b[i];
		exit(0);
	}
}

void solve() {
	string s; cin>>s; n = sz(s);
	FOR(i, 0, n) a[i] = s[i] - '0';
	go1();
	go2();
	cout<<0;
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}