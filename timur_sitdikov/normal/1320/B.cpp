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

const int MAXN = 2e5 + 5;

vi g[MAXN], g_inv[MAXN];

vi path;

int dis[MAXN];
int dp[MAXN], dp2[MAXN];

queue<int> qq;

int n;

void bfs(int s) {
	REPN(i, 1, n) {
		dis[i] = INF;
	}
	dis[s] = 0;
	qq.push(s);
	while(!qq.empty()) {
		s = qq.front();
		qq.pop();
		REP(i, 0, SZ(g_inv[s])) {
			int to = g_inv[s][i];
			if (dis[to] == INF) {
				dis[to] = dis[s] + 1;
				qq.push(to);
			}
		}
	}
}

void solve(){
	int m;
	scanf("%d%d", &n, &m);
	REP(i, 0, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		g_inv[b].pb(a);
	}
	int k;
	scanf("%d", &k);
	REP(i, 0, k) {
		int a;
		scanf("%d", &a);
		path.pb(a);
	}
	int s = path[0], f = path[k - 1];
	bfs(f);
	for(int i = k - 2; i >= 0; i--) {
		int s = path[i], to = path[i + 1];
		dp[s] = dp[to];
		dp2[s] = dp2[to];
		if (dis[s] <= dis[to]) {
			dp[s]++;
			dp2[s]++;
		} else {
			int fl = 0;
			REP(j, 0, SZ(g[s])) {
				int to1 = g[s][j];
				if (to1 != to && dis[to1] == dis[to]) {
					fl = 1;
				}
			}
			dp[s] += fl;
		}
	}
	printf("%d %d\n", dp2[s], dp[s]);
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