#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double DOUBLE;
typedef complex<double> point;
#define xx real()
#define yy imag()

#define REP(i, a, b) for(int i = (a); i < (int)(b); i++)
#define REPN(i, a, b) for(int i = (a); i <= (int)(b); i++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))
#define _1 first
#define _2 second

#define x0 gray_cat_x0
#define y0 gray_cat_y0
#define x1 gray_cat_x1
#define y1 gray_cat_y1
#define j0 gray_cat_j0

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 16;
const int INF = 1e9 + 10;
// const ll MOD = 1e9 + 7;
const ll MOD = 998244353;

const int MAXN = 1e5 + 5;

ll disk_heads[MAXN], tracks_to_read[MAXN];
int n, m;

bool can_cover(ll o, ll l, ll r, ll lim) {
	if (l > r) {
		return true;
	}
	l = min(l, o);
	r = max(r, o);
	ll d = r - l + min(o - l, r - o);
	return d <= lim;
}

bool check(ll lim) {
	int last = 0;
	REP(i, 0, n) {
		int cur;
		for(cur = last; cur < m; cur++) {
			if (!can_cover(disk_heads[i], tracks_to_read[last], tracks_to_read[cur], lim)) {
				break;
			}
		}
		last = cur;
	}
	return last == m;
}

void solve(){
	scanf("%d%d", &n, &m);
	REP(i, 0, n) {
		scanf("%lld", &disk_heads[i]);
	}
	REP(i, 0, m) {
		scanf("%lld", &tracks_to_read[i]);
	}
	if (check(0)) {
		printf("0\n");
		return;
	}
	ll l = 0, r = 2e10;
	while(l + 1 < r) {
		ll mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	printf("%lld\n", r);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}