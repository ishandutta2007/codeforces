#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define EPS 1e-9
const int mod = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

const int MAXN = 1000010;
bool flag[MAXN];
int sp[MAXN];
void Sieve() {
    for (int i = 2; i < MAXN; i += 2) sp[i] = 2;
    for (int i = 3; i < MAXN; i += 2) if (!flag[i]) {
        sp[i] = i;
        for (int j = i; 1LL * i * j < MAXN; j += 2) if (!flag[i * j]) {
            flag[i * j] = 1;
            sp[i * j] = i;
        }
    }
}

int inv[MAXN];
void build(int p) {
    inv[1] = 1;
    for (int i = 2; i < MAXN; i++) inv[i] = (p - 1LL * (p / i) * inv[p % i] % p) % p;
}

const int maxn = 200010;
int n, q;
int a[maxn];
vector<pair<pi, int> > query;
int prf[maxn];
int prv[5 * maxn];
int ans[maxn];

int bit[maxn];
void add(int p, int val) {
    for (; p < maxn; p += p & -p) bit[p] = 1LL * bit[p] * val % mod;
}
int get(int p) {
    int res = 1;
    for (; p > 0; p -= p & -p) res = 1LL * res * bit[p] % mod;
    return res;
}

int exp(int n, int k) {
    if (!k) return 1;
    if (k & 1) return 1LL * n * exp(n, k - 1) % mod;
    int t = exp(n, k >> 1);
    return 1LL * t * t % mod;
}

void update(int k) {
    int t = a[k];
    while (t > 1) {
        if (prv[sp[t]] < k) {
            if (prv[sp[t]]) add(prv[sp[t]], 1LL * sp[t] * inv[sp[t] - 1] % mod);
            add(k, 1LL * (sp[t] - 1) * inv[sp[t]] % mod);
            prv[sp[t]] = k;
        }
        t /= sp[t];
    }
}

void solve() {
    Sieve(); build(mod); FOR(i, 0, maxn) bit[i] = 1;
    scanf("%d", &n);
    FOR(i, 1, n + 1) scanf("%d", a + i);
    scanf("%d", &q);
    FOR(i, 0, q) {
        int l, r; scanf("%d%d", &l, &r);
        query.pb(mp(mp(r, l), i));
    }
    sort(all(query));
    int cur = 1; prf[0] = 1;
    FOR(i, 0, q) {
        while (cur <= query[i].fi.fi) {
            update(cur);
            prf[cur] = 1LL * prf[cur - 1] * a[cur] % mod;
            cur++;
        }
        ans[query[i].se] = 1LL * get(query[i].fi.fi) * exp(get(query[i].fi.se - 1), mod - 2) % mod;
        ans[query[i].se] = 1LL * ans[query[i].se] * prf[query[i].fi.fi] % mod * exp(prf[query[i].fi.se - 1], mod - 2) % mod;
    }
    FOR(i, 0, q) printf("%d\n", ans[i]);
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