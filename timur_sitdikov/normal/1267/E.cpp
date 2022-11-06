#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
typedef double DOUBLE;
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
const ll LL_INF = 1e17 + 10;
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

const int MAXN = 1e3 + 5;

int v[MAXN][MAXN];
int ind, n, m;
int sum[MAXN];

int per[MAXN];

bool cmp(int a, int b) {
	return v[a][ind] - v[a][n - 1] < v[b][ind] - v[b][n - 1];
}

vi ans_v;

void solve(){
	scanf("%d%d", &n, &m);
	REP(i, 0, m) {
		REP(j, 0, n) {
			scanf("%d", &v[i][j]);
			sum[j] += v[i][j];
		}
	}
	int ans = INF;
	REP(i, 0, m) {
		per[i] = i;
	}
	REP(i, 0, n - 1) {
		ind = i;
		sort(per, per + m, cmp);
		int r, sum_n = sum[n - 1], sum_ind = sum[ind];
		for(r = 0; sum_n > sum_ind; r++) {
			sum_n -= v[per[r]][n - 1];
			sum_ind -= v[per[r]][ind];
		}
		if (r < ans) {
			ans = r;
			ans_v.clear();
			REP(j, 0, r) {
				ans_v.pb(per[j]);
			}
		}
	}
	printf("%d\n", SZ(ans_v));
	REP(i, 0, SZ(ans_v)) {
		printf("%d ", ans_v[i] + 1);
	}
	putchar('\n');
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