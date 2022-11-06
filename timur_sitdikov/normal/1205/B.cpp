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
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

const int MAXN = 2e5 + 5;
const int MAXLOG = 61;

ll v[MAXN];

vi bb[MAXLOG];

vi g[MAXN];

int dis[MAXN];
int col[MAXN];
int prv[MAXN];
int cl;

vi comp;

queue<int> qq;

int ans;

void bfs(int s) {
	cl = s;
	comp.clear();
	col[s] = cl;
	dis[s] = 0;
	qq.push(s);
	while(!qq.empty()) {
		int s = qq.front();
		qq.pop();
		comp.pb(s);
		REP(i, 0, SZ(g[s])) {
			int to = g[s][i];
			if (col[to] != cl) {
				col[to] = cl;
				prv[to] = s;
				dis[to] = dis[s] + 1;
				qq.push(to);
			}
		}
	}
	REP(i, 1, SZ(comp)) {
		REP(j, i + 1, SZ(comp)) {
			REP(k, 0, SZ(g[comp[i]])) {
				if (g[comp[i]][k] == comp[j] && prv[comp[j]] != comp[i]) {
					ans = min(ans, dis[comp[i]] + dis[comp[j]] + 1);
				}
			}
		}
	}
}

void solve(){
	int n;
	scanf("%d", &n);
	REPN(i, 1, n) {
		scanf("%lld", &v[i]);
	}
	REP(i, 0, MAXLOG) {
		REPN(j, 1, n) {
			if (v[j] & (1ll << i)) {
				bb[i].pb(j);
				if (SZ(bb[i]) >= 3) {
					printf("3\n");
					return;
				}
			}
		}
	}
	REP(i, 0, MAXLOG) {
		if (SZ(bb[i]) == 2) {
			g[bb[i][0]].pb(bb[i][1]);
			g[bb[i][1]].pb(bb[i][0]);
		}
	}
	ans = INF;
	REPN(i, 1, n) {
		bfs(i);
	}
	if (ans == INF) {
		ans = -1;
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