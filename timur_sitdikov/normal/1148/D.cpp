#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 3e5 + 5;

pii pp[MAXN];
int cnt[2];

vector<pii> vv;

void solve(){
	int n;
	scanf("%d", &n);
	REP(i, 0, n) {
		scanf("%d%d", &pp[i]._1, &pp[i]._2);
		if (pp[i]._1 < pp[i]._2) {
			cnt[0]++;
		} else {
			cnt[1]++;
		}
	}
	if (cnt[0] > cnt[1]) {
		REP(i, 0, n) {
			if (pp[i]._1 < pp[i]._2) {
				vv.pb(mp(pp[i]._2, i));
			}
		}
		SORT(vv);
		reverse(BE(vv));
	} else {
		REP(i, 0, n) {
			if (pp[i]._1 > pp[i]._2) {
				vv.pb(mp(pp[i]._2, i));
			}
		}
		SORT(vv);
	}
	printf("%d\n", SZ(vv));
	REP(i, 0, SZ(vv)) {
		printf("%d ", vv[i]._2 + 1);
	}
	putchar('\n');
}   

int main(){

    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}