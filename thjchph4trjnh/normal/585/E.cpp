#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define EPS 1e-9
const int mod = 1000000007;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

const int maxn = 500010;
int n;
int a[maxn];
vi d[maxn];
int cnt[20 * maxn];
bool isprime[maxn];
vi prime;
vii tmp;

void go1(int k, int pos, int cur, int sig) {
    if (pos == sz(d[k])) {
        if (cur > 1) {
            cnt[1] += sig * (cnt[cur] + 1);
            if (cnt[1] < 0) cnt[1] += mod;
            else if (cnt[1] >= mod) cnt[1] -= mod;
            tmp.push_back(make_pair(cur, cnt[cur] + 1));
        }
        return;
    }
    go1(k, pos + 1, cur, sig);
    go1(k, pos + 1, cur * d[k][pos], sig * -1);
}

int go2(int k, int pos, int cur, int sig) {
    if (pos == sz(d[k])) return (sig * cnt[cur] + mod) % mod;
    int res = go2(k, pos + 1, cur, sig);
    res += go2(k, pos + 1, cur * d[k][pos], sig * -1);
    return res % mod;
}

void solve() {
    ms(isprime, 1); FOR(i, 2, maxn) if (isprime[i]) {for (ll j = 1LL * i * i; j < maxn; j += i) isprime[j] = 0; prime.push_back(i);}
    ms(cnt, 0);
    scanf("%d", &n);
    ll tot = 0;
    FOR(i, 0, n) {
        int b; scanf("%d", &b); a[i] = 1;
        for (int j = 0; j < sz(prime) && 1LL * prime[j] * prime[j] <= b; j++) {
            if (b % prime[j] != 0) continue;
            d[i].push_back(prime[j]); a[i] *= prime[j];
            while (b % prime[j] == 0) b /= prime[j];
        }
        if (b > 1) {d[i].push_back(b); a[i] *= b;}
        go1(i, 0, 1, -1);
        FOR(j, 0, sz(tmp)) cnt[tmp[j].first] = (cnt[tmp[j].first] + tmp[j].second) % mod;
        tmp.clear();
    }
//    if (n == 500000 && a[0] == 7949370) return;
    ll ans = 0;
    FOR(i, 0, n) ans = (ans + go2(i, 0, 1, 1)) % mod;
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