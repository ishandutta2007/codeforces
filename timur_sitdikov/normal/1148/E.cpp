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

pii pp_s[MAXN];
int pp_f[MAXN];

set<pii> st0, st1;

vector<pair<pii, int> > ans;

void solve(){
	int n;
	scanf("%d", &n);
	REP(i, 0, n) {
		scanf("%d", &pp_s[i]._1);
		pp_s[i]._2 = i;
	}
	REP(i, 0, n) {
		scanf("%d", &pp_f[i]);
	}
	sort(pp_s, pp_s + n);
	sort(pp_f, pp_f + n);
	REP(i, 0, n) {
		if (pp_s[i]._1 < pp_f[i]) {
			st0.insert(mp(pp_f[i], i));
		} else if (pp_s[i]._1 > pp_f[i]) {
			st1.insert(mp(pp_f[i], i));
		} 
	}
	while(!st1.empty()) {
		
		/*printf("*************\n");
		FA(it, st0) {
			printf("%d %d;", it->_1, it->_2);
		}
		putchar('\n');
		FA(it, st1) {
			printf("%d %d;", it->_1, it->_2);
		}
		putchar('\n');*/
		
		
		if (st0.empty()) {
			//printf("1\n");
			printf("NO\n");
			return;
		}
		pii ppa = *st0.begin();
		pii ppb = *st1.begin();
		
		if (ppa._1 > ppb._1) {
			//printf("2\n");
			printf("NO\n");
			return;
		}
		
		int froma = pp_s[ppa._2]._1;
		int fromb = pp_s[ppb._2]._1;
		int toa = ppa._1;
		int tob = ppb._1;
		
		//printf("%d->%d %d->%d\n", froma, toa, fromb, tob);
		
		int d = min(abs(toa - froma), abs(fromb - tob));
		
		if (d > 0) {
			ans.pb(mp(mp(pp_s[ppa._2]._2, pp_s[ppb._2]._2), d));
			pp_s[ppa._2]._1 += d;
			pp_s[ppb._2]._1 -= d;
			if (d == abs(toa - froma)) {
				st0.erase(st0.begin());
			}
			if (d == abs(fromb - tob)) {
				st1.erase(st1.begin());
			}
		} else {
			//printf("3\n");
			printf("NO\n");
			
			return;
		}
	}
	
	if (!st0.empty() || !st1.empty()) {
		printf("NO\n");
		return;
	}
	
	/*REP(i, 0, n) {
		printf("%d ", pp_s[i]._1);
	}
	putchar('\n');
	REP(i, 0, n) {
		printf("%d ", pp_f[i]);
	}
	putchar('\n');*/
	
	
	printf("YES\n%d\n", SZ(ans));
	REP(i, 0, SZ(ans)) {
		printf("%d %d %d\n", ans[i]._1._1 + 1, ans[i]._1._2 + 1, ans[i]._2);
	}
}   

int main(){

    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}