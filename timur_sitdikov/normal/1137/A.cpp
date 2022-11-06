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

const int MAXN = 1e3 + 5;

pair<int, pii> pp[MAXN * MAXN];

int last_g[MAXN], last_v[MAXN];
int cnt_g[MAXN], cnt_v[MAXN];
int add_g[MAXN][MAXN], add_v[MAXN][MAXN];
int ans[MAXN][MAXN];
int val[MAXN][MAXN];

void solve(){
	int n, m;
	scanf("%d%d", &n, &m);
	REP(i, 0, n) {
		REP(j, 0, m) {
			scanf("%d", &val[i][j]);
			pp[i * m + j] = mp(val[i][j], mp(i, j));
		}
	}
	sort(pp, pp + n * m);
	REP(i, 0, n * m) {
		int i0 = pp[i]._2._1;
		int j0 = pp[i]._2._2;
		int value = pp[i]._1;
		if (last_g[i0] != value) {
			cnt_g[i0]++;
			last_g[i0] = value;
		}
		if (last_v[j0] != value) {
			cnt_v[j0]++;
			last_v[j0] = value;
		}
		if (cnt_g[i0] >= cnt_v[j0]) {
			add_v[i0][j0] = cnt_g[i0] - cnt_v[j0];
		} else {
			add_g[i0][j0] = -(cnt_g[i0] - cnt_v[j0]);
		}
	}
	
	REP(i, 0, n) {
		REP(j, 0, m) {
			ans[i][j] = max(cnt_g[i] + add_g[i][j], cnt_v[j] + add_v[i][j]);
			printf("%d ", ans[i][j]);
		}
		putchar('\n');
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