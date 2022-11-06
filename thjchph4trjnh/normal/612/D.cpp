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

const int maxn = 1000010;
int n, k;
int a[maxn];
int b[maxn];

void solve() {
    scanf("%d%d", &n, &k);
    vii v;
    FOR(i, 0, n) {
        scanf("%d%d", a + i, b + i);
        a[i] <<= 1; b[i] <<= 1;
        v.pb(mp(a[i], 1));
        v.pb(mp(b[i], 0));
        v.pb(mp(b[i] + 1, -1));
    }
    sort(all(v));
    vii ans;
    int cur = -1, tot = 0;
    FOR(i, 0, sz(v)) {
        tot += v[i].se;
        if (tot < k) {
            if (~cur) {
                ans.pb(mp(cur, v[i - 1].fi));
                cur = -1;
            }
        }
        else if (!~cur) cur = v[i].fi;
    }
    printf("%d\n", sz(ans));
    FOR(i, 0, sz(ans)) printf("%d %d\n", ans[i].fi >> 1, ans[i].se >> 1);
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