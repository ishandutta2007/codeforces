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

const int MAXN = 5e5 + 5;

vi g[MAXN];

int used[MAXN];
vi vals;

int ans[MAXN];

void dfs(int s) {
	used[s] = 1;
	vals.pb(s);
	REP(i, 0, SZ(g[s])) {
		int to = g[s][i];
		if (!used[to]) {
			dfs(to);
		}
	}
}

void solve(){
	int n, m;
	scanf("%d%d", &n, &m);
	REP(i, 0, m) {
		int k, last;
		scanf("%d", &k);
		REP(j, 0, k) {
			int a;
			scanf("%d", &a);
			if (j) {
				g[a].pb(last);
				g[last].pb(a);
			}
			last = a;
		}
	}
	REPN(i, 1, n) {
		if (!used[i]) {
			vals.clear();
			dfs(i);
			REP(j, 0, SZ(vals)) {
				ans[vals[j]] = SZ(vals);
			}
		}
	}
	REPN(i, 1, n) {
		printf("%d ", ans[i]);
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