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

const int MAXN = 1e6 + 5;

vi g[MAXN];
deque<int> dq;
int dp[MAXN];
int used[MAXN];
int cnt_viewed[MAXN], cnt_total[MAXN];

void bfs(int n, int s) {
	REPN(i, 1, n) {
		dp[i] = INF;
	}
	dp[s] = 0;
	dq.pb(s);
	while(!dq.empty()) {
		int s = dq.front();
		dq.pop_front();
		if (used[s]) {
			continue;
		}
		used[s] = 1;
		REP(i, 0, SZ(g[s])) {
			int to = g[s][i];
			if (dp[to] <= dp[s]) {
				continue;
			}
			cnt_viewed[to]++;
			if (cnt_viewed[to] == cnt_total[to]) {
				dp[to] = dp[s];
				dq.push_front(to);
			} else if (dp[to] == INF) {
				dp[to] = dp[s] + 1;
				dq.push_back(to);
			}
		}
	}
}

void solve(){
	int n, m;
	scanf("%d%d", &n, &m);
	REP(i, 0, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[b].pb(a);
		cnt_total[a]++;
	}
	int s, t;
	scanf("%d%d", &s, &t);
	bfs(n, t);
	if (dp[s] == INF) {
		dp[s] = -1;
	}
	printf("%d\n", dp[s]);
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