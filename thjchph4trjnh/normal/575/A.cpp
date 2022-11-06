#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

struct matrix {
	ll x[2][2];
	matrix() {ms(x, 0);}
};

const int maxn = 50010;
const int maxe = 16;
ll k, p;
int n;
int s[maxn];
int m;
map<ll, ll> except;
vi v;
matrix sp[maxn][maxe];

matrix mul(matrix A, matrix B) {
	matrix res;
	FOR(i, 0, 2) FOR(j, 0, 2) FOR(k, 0, 2) res.x[i][j] = (res.x[i][j] + A.x[i][k] * B.x[k][j]) % p;
	return res;
}

matrix ex(matrix A, ll k) {
	if (k == 1) return A;
	if (k & 1) return mul(A, ex(A, k - 1));
	matrix T = ex(A, k >> 1);
	return mul(T, T);
}

matrix cal(int i, ll d) {
	matrix res; res.x[0][0] = res.x[1][1] = 1;
	if (d == 0) return res;
	if (d > n) {
		ll k = d / n;
		d %= n;
		return mul(ex(cal(i, n), k), cal(i, d));
	}
	FORd(j, maxe, 0) if (d >= 1 << j) return mul(sp[i][j], cal((i + (1 << j)) % n, d - (1 << j)));
}

void solve() {
	scanf("%I64d%I64d", &k, &p);
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%d", s + i);
	FOR(i, 0, n) {sp[i][0].x[0][0] = s[(i + 1) % n]; sp[i][0].x[0][1] = 1; sp[i][0].x[1][0] = s[i];}
	FOR(j, 0, maxe - 1) FOR(i, 0, n) sp[i][j + 1] = mul(sp[i][j], sp[(i + (1 << j)) % n][j]);
	scanf("%d", &m);
	FOR(i, 0, m) {
		ll j, v; scanf("%I64d%I64d", &j, &v);
		except[j] = v;
	}
	if (k == 0) {printf("0"); return;}
	for (map<ll, ll>::iterator it = except.begin(); it != except.end(); it++) {
		ll u = it->first;
		if (u >= k) continue;
		if (u <= k - 2) v.push_back(u);
		if (u > 0) v.push_back(u - 1);
	}
	v.push_back(0); v.push_back(k - 2);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	matrix res; res.x[0][0] = 1; res.x[0][1] = 0;
	res = mul(res, sp[0][0]);
	FOR(i, 0, sz(v) - 1) {
		ll x = v[i] + 1;
		ll y = v[i + 1] - 1;
		ll d = y - x + 1;
		if (d > 0) res = mul(res, cal(x % n, d));
		matrix tmp;
		if (except.count(y + 2)) tmp.x[0][0] = except[y + 2]; else tmp.x[0][0] = s[(y + 2) % n];
		if (except.count(y + 1)) tmp.x[1][0] = except[y + 1]; else tmp.x[1][0] = s[(y + 1) % n];
		tmp.x[0][1] = 1;
		res = mul(res, tmp);
	}
	cout<<res.x[0][0] % p;
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}