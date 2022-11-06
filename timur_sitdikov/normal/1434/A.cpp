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

const int MAXN = 6e5 + 5;

int a[MAXN];

pii pp[MAXN];

int cnt[MAXN];

void solve(){
	REP(i, 0, 6) {
		scanf("%d", &a[i]);
	}
	int n;
	scanf("%d", &n);
	REP(i, 0, n) {
		int b;
		scanf("%d", &b);
		REP(j, 0, 6) {
			pp[6 * i + j] = {b - a[j], i};
		}
	}
	sort(pp, pp + 6 * n);
	int l = 0, r = 0;
	int bad = n;
	int ans = pp[6 * n - 1]._1 - pp[0]._1;
	for(; l < 6 * n; ) {
		for(; r < 6 * n && bad > 0; ) {
			int r1 = r;
			for(r1 = r; r1 < 6 * n && pp[r1]._1 == pp[r]._1; r1++){
				int ind = pp[r1]._2;
				if (!cnt[ind]) {
					bad--;
				}
				cnt[ind]++;
			}
			r = r1;
		}
		if (bad == 0) {
			ans = min(ans, pp[r - 1]._1 - pp[l]._1);
		} else {
			break;
		}
		
		int l1 = l;
		for(l1 = l; l1 < 6 * n && pp[l1]._1 == pp[l]._1; l1++) {
			int ind = pp[l1]._2;
			cnt[ind]--;
			if (cnt[ind] == 0) {
				bad++;
			}
		}
		l = l1;
	}
	printf("%d\n", ans);
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