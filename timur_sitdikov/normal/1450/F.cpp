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
const ll MOD = 1e9 + 7;

const int MAXN = 3e5 + 5;

int p[MAXN];

int cnt[MAXN];

vector<pii> segs;

void solve(){
	int n;
	// Input
	scanf("%d", &n);
	REP(i, 0, n) {
		scanf("%d", &p[i]);
		p[i]--;
	}
	
	// Fill initial segs
	segs.clear();
	int last = 0;
	REP(i, 1, n) {
		if (p[i] == p[i - 1]) {
			segs.pb({last, i - 1});
			last = i;
		}
	}
	segs.pb({last, n - 1});
	
	// Calc count
	REP(i, 0, n) {
		cnt[i] = 0;
	}
	REP(i, 0, SZ(segs)) {
		cnt[p[segs[i]._1]]++;
		cnt[p[segs[i]._2]]++;
	}
	
	// Calc the most frequent
	int maxi = 0;
	REP(i, 0, n) {
		if (cnt[i] > cnt[maxi]) {
			maxi = i;
		}
	}
	
	// Calc add cnt
	int add_cnt = 0;
	REP(i, 1, n) {
		if (p[i - 1] != p[i] && p[i - 1] != maxi && p[i] != maxi) {
			add_cnt++;
		}
	}
	
	// Check and use add_cnt
	int need_cnt = cnt[maxi] - SZ(segs) - 1;
	
	/*REP(i, 0, SZ(segs)) {
		printf("[%d %d],", segs[i]._1, segs[i]._2);
	}
	putchar('\n');
	printf("maxi: %d\n", maxi);
	printf("max cnt: %d\n", cnt[maxi]);
	printf("tot: %d\n", 2 * SZ(segs));
	printf("need cnt: %d\n", need_cnt);
	printf("available cnt: %d\n", add_cnt);*/
	
	if (need_cnt > add_cnt) {
		printf("-1\n");
		return;
	}
	printf("%d\n", SZ(segs) - 1 + max(0, need_cnt));
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}