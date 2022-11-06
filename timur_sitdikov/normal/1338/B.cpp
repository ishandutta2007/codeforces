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
#define j0 gray_cat_j0

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 16;
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

const int MAXN = 2e5 + 5;

vi g[MAXN];

int dis[MAXN], used[MAXN];
int cnt[2];

void dfs(int s) {
	used[s] = 1;
	REP(i, 0, SZ(g[s])) {
		int to = g[s][i];
		if (!used[to]) {
			dis[to] = dis[s] + 1;
			dfs(to);
		}
	}
}

void solve(){
	int n;
	scanf("%d", &n);
	REP(i, 1, n) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	int mx = 0;
	REPN(i, 1, n) {
		if (SZ(g[i]) > 1) {
			int fl = 0;
			REP(j, 0, SZ(g[i])) {
				int to = g[i][j];
				if (SZ(g[to]) > 1 && to < i) {
					mx++;
				} else if (SZ(g[to]) == 1) {
					fl = 1;
				}
			}
			mx += fl;
		}
	}
	REPN(i, 1, n) {
		if (SZ(g[i]) > 1) {
			dfs(i);
			break;
		}
	}
	REPN(i, 1, n) {
		if (SZ(g[i]) == 1) {
			cnt[dis[i] & 1]++;
		}
	}
	int mn = 1;
	if (cnt[0] && cnt[1]) {
		mn = 3;
	}
	printf("%d %d\n", mn, mx);
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