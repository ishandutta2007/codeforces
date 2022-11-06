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

const int MAXN = 4e3 + 5, MAXV = 1e6 + 5;

vi cc[MAXV];
int vals[MAXN];
int pos[MAXN];
int used[MAXV];

void solve(){
	int n;
	scanf("%d", &n);
	int ans = 1;
	REP(i, 0, n) {
		scanf("%d", &vals[i]);
		pos[i] = SZ(cc[vals[i]]);
		cc[vals[i]].pb(i);
		ans = max(ans, SZ(cc[vals[i]]));
	}
	REP(i, 0, n) {
		int v = vals[i];
		if (cc[v][0] != i) {
			continue;
		}
		REP(j, i + 1, n) {
			int v2 = vals[j];
			if (v2 == v || used[v2] == i + 1) {
				continue;
			}
			used[v2] = i + 1;
			int cnt = 2;
			for(int i1 = 0, j1 = pos[j]; ; cnt++) {
				if (cnt & 1) {
					for(j1++; j1 < SZ(cc[v2]) && cc[v2][j1] < cc[v][i1]; j1++);
					if (j1 >= SZ(cc[v2])) {
						break;
					}
				} else {
					for(i1++; i1 < SZ(cc[v]) && cc[v][i1] < cc[v2][j1]; i1++);
					if (i1 >= SZ(cc[v])) {
						break;
					}
				}
			}
			ans = max(ans, cnt);
		}
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