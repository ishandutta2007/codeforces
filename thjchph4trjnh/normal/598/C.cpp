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
int n;

void solve() {
    scanf("%d", &n);
    vector<pair<ld, int> > angle;
    FOR(i, 0, n) {
        int x, y; scanf("%d%d", &x, &y);
        ld alpha;
        if (x != 0) {
			alpha = atan((ld) y / x);
	        if (x < 0) alpha += PI;
	        else if (y < 0) alpha += 2 * PI;
		}
    	else alpha = PI / 2 + (y < 0 ? PI : 0);
        angle.pb(mp(alpha, i));
    }
    sort(all(angle));
    angle.pb(mp(angle[0].fi + 2 * PI, angle[0].se));
    ld amin = INF;
    pi ans;
    FOR(i, 0, n) {
        ld t = angle[i + 1].fi - angle[i].fi;
        t = min(t, 2 * PI - t);
        if (amin > t) {
            amin = t;
            ans = mp(angle[i].se, angle[i + 1].se);
        }
    }
    printf("%d %d", ans.fi + 1, ans.se + 1);
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