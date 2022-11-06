#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
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
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

const int maxn = 100010;
const int maxm = 5010;
int n, m, k;
ll p;
ll h[maxn];
ll a[maxn];
ll b[maxn];
int t[maxm];

bool check(ll mid) {
    ll tot = 0;
    FOR(i, 0, n) if (b[i] > mid) tot += max(0LL, (b[i] - mid + p - 1) / p);
    if (tot > m * k) return false;
    ms(t, 0);
    FOR(i, 0, n) {
        ll end = b[i] - mid - h[i];
        for (ll j = end; j + h[i] > 0; j -= p) {
            if (j <= 0) t[0]++;
            else if (j > a[i] * (m - 1)) return false;
            else t[(j + a[i] - 1) / a[i]]++;
        }
    }
    int tmp = 0;
    FOR(i, 0, m) {
        tmp += t[i];
        tmp = max(0, tmp - k);
    }
    return tmp == 0;
}

void solve() {
    scanf("%d%d%d%I64d", &n, &m, &k, &p);
    FOR(i, 0, n) scanf("%I64d%I64d", h + i, a + i);
    FOR(i, 0, n) b[i] = h[i] + a[i] * m;
    ll l = 0, r = 1e18;
    while (l < r) {
        ll mid = (l + r) >> 1;
        if (!check(mid)) l = mid + 1; else r = mid;
    }
    printf("%I64d", l);
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