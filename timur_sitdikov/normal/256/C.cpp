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

const int MAXN = 1e6 + 5, MAXV = 100;

int cnt[MAXV];
int grandi[MAXN];
int used[MAXV];

vector<pii> segs[MAXV];

int get_sq(ll v) {
	return (int)sqrt(v + 0.5);
}

void solve(){
	/*int l = 2, r = 1;
	REP(i, 4, MAXN) {
		if (l * l * l * l < i) {
			cnt[grandi[l]]--;
			l++;
		}
		if ((r + 1) * (r + 1) <= i) {
			r++;
			cnt[grandi[r]]++;
		}
		for(; cnt[grandi[i]]; grandi[i]++);
	}
	REP(i, 1, MAXN) {
		// printf("%d: %d\n", i, grandi[i]);
		if (grandi[i] != grandi[i - 1]) {
			printf("%d %d\n", i, grandi[i]);
		}
	}*/
	segs[0].pb({1, 3});
	segs[1].pb({4, 15});
	segs[2].pb({16, 81});
	segs[0].pb({82, 6723});
	segs[3].pb({6724, 50625});
	segs[1].pb({50626, 1000000});
	int n;
	scanf("%d", &n);
	int ans = 0;
	REP(i, 0, n) {
		ll v;
		scanf("%lld", &v);
		int r = get_sq(v);
		int l = get_sq(r);
		if ((ll)l * (ll)l * (ll)l * (ll)l < v) {
			l++;
		}
		if (r == v) {
			r--;
		}
		REP(j, 0, 4) {
			used[j] = 0;
			REP(k, 0, SZ(segs[j])) {
				int l1 = max(segs[j][k]._1, l);
				int r1 = min(segs[j][k]._2, r);
				if (l1 <= r1) {
					used[j] = 1;
				}
			}
		}
		int cur = 0;
		for(; used[cur]; cur++);
		ans ^= cur;
	}
	if (ans) {
		printf("Furlo\n");
	} else {
		printf("Rublo\n");
	}
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