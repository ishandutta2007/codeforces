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

const int maxn = 100010;
ll n, k;
map<ll, int> tb;
vector<ll> dvs;
vector<ll> d[maxn];
vector<ll> e[maxn];
int ok[maxn];
ll f[maxn][64];

void process(int u) {
    ll t = dvs[u];
    for (int i = 1; (ll) i * i <= t; i++) {
        if (t % i == 0) {
            d[u].pb(tb[i]);
            if (t != (ll) i * i) {
                d[u].pb(tb[t / i]);
            }
        }
    }
    sort(all(d[u]));
}

void process2(int u) {
    if (ok[u]) return; ok[u] = 1;
    FOR(i, 0, sz(d[u])) {
        int v = d[u][i];
        int w = tb[dvs[u] / dvs[v]];
        if (dvs[v] > 1 && dvs[w] > 1 && gcd(dvs[v], dvs[w]) == 1) {
            process2(v); process2(w);
            FOR(j, 0, sz(e[v])) e[u].pb(e[v][j]);
            FOR(j, 0, sz(e[w])) e[u].pb(e[w][j]);
            return;
        }
    }
    e[u].pb(sz(d[u]) - 1);
}

ll calc(int u, int k) {
    ll res = 1;
    FOR(i, 0, sz(e[u])) {
        int d = e[u][i];
        res *= f[k][d];
        res = min(res, (ll) INF);
    }
    return res;
}

void go(int u, int k, int l) {
    if (!k) {
        printf("%I64d ", dvs[u]);
        return;
    }
    if (l == 1) {
    	printf("%d ", 1);
    	return;
    }
    ll tot = l;
    FOR(i, 0, sz(d[u])) {
        int v = d[u][i];
        ll t = calc(v, k - 1);
        go(v, k - 1, min(tot, t));

        tot -= t;
        if (tot <= 0) break;
    }
}

void solve() {
    scanf("%I64d%I64d", &n, &k);
    if (n == 1) {printf("%d", 1); return;}
    if (k > 100000) {FOR(i, 0, 100000) printf("%d ", 1); return;}
    for (int i = 1; (ll) i * i <= n; i++) {
        if (n % i == 0) {
            dvs.pb(i);
            if (n != (ll) i * i) dvs.pb(n / i);
        }
    }
    sort(all(dvs));
    FOR(i, 0, sz(dvs)) tb[dvs[i]] = i;
    FOR(i, 0, sz(dvs)) process(i);
    FOR(i, 0, sz(dvs)) process2(i);
    FOR(i, 0, 64) f[0][i] = 1;
    FOR(i, 1, maxn) FOR(j, 0, 64) FOR(l, 0, j + 1) {
        f[i][j] += f[i - 1][l];
        f[i][j] = min(f[i][j], (ll) INF);
    }
    go(sz(dvs) - 1, k, 100000);
}

int main() {
//  ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef _LOCAL_
    //printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}