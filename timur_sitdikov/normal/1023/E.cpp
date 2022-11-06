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

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 1e5 + 5;

vector<pii> goods1, goods2;

char ans[MAXN];

int make_query(int r1, int c1, int r2, int c2) {
	printf("? %d %d %d %d\n", r1, c1, r2, c2);
	fflush(stdout);
	char s[10];
	scanf("%s", &s[0]);
	if (s[0] == 'B') {
		exit(1);
	}
	return (s[0] == 'Y' ? 1 : 0);
}

void solve(){
	int n;
	scanf("%d", &n);
	goods1.pb(mp(1, 1));
	REP(i, 1, n) {
		pii pp = goods1[SZ(goods1) - 1];
		int tmp = make_query(pp._1 + 1, pp._2, n, n);
		if (tmp) {
			goods1.pb(mp(pp._1 + 1, pp._2));
		} else {
			goods1.pb(mp(pp._1, pp._2 + 1));
		}
	}
	
	goods2.pb(mp(n, n));
	REP(i, 1, n - 1) {
		pii pp = goods2[SZ(goods2) - 1];
		int tmp = make_query(1, 1, pp._1, pp._2 - 1);
		if (tmp) {
			goods2.pb(mp(pp._1, pp._2 - 1));
		} else {
			goods2.pb(mp(pp._1 - 1, pp._2));
		}
	}
	
	for(int i = SZ(goods2) - 1; i >= 0; i--) {
		goods1.pb(goods2[i]);
	}
	
	REP(i, 1, SZ(goods1)) {
		if (goods1[i]._1 == goods1[i - 1]._1) {
			ans[i - 1] = 'R';
		} else {
			ans[i - 1] = 'D';
		}
	}
	printf("! %s\n", ans);
	fflush(stdout);
}   

int main(){
/*#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif*/
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}