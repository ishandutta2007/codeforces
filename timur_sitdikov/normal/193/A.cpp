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

const int MAXN = 55;

char g[MAXN][MAXN];

int used[MAXN][MAXN];

int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};

int n, m, cnt, cnt0;
queue<pii> qq;

void bfs(int i0, int j0) {
	REP(i, 0, n) {
		REP(j, 0, m) {
			used[i][j] = 0;
		}
	}
	used[i0][j0] = 1;
	qq.push({i0, j0});
	cnt = 0;
	while(!qq.empty()) {
		i0 = qq.front()._1, j0 = qq.front()._2;
		cnt++;
		qq.pop();
		REP(k, 0, 4) {
			int i1 = i0 + di[k], j1 = j0 + dj[k];
			if (i1 >= 0 && j1 >= 0 && i1 < n && j1 < m && g[i1][j1] == '#' && !used[i1][j1]) {
				used[i1][j1] = 1;
				qq.push({i1, j1});
			}
		}
	}
}

bool check(int i0, int j0) {
	g[i0][j0] = '.';
	int si = -1, sj = -1;
	REP(i, 0, n) {
		REP(j, 0, m) {
			if (g[i][j] == '#') {
				si = i, sj = j;
			}
		}
	}
	bfs(si, sj);
	g[i0][j0] = '#';
	return cnt < cnt0 - 1;
}

void solve(){
	scanf("%d%d", &n, &m);
	REP(i, 0, n) {
		scanf("%s", &g[i][0]);
	}
	int si = -1, sj = -1;
	REP(i, 0, n) {
		REP(j, 0, m) {
			if (g[i][j] == '#') {
				si = i, sj = j;
			}
		}
	}
	bfs(si, sj);
	if (cnt <= 2) {
		printf("-1\n");
		return;
	}
	cnt0 = cnt;
	//printf("%d\n", cnt0);
	REP(i, 0, n) {
		REP(j, 0, m) {
			if (g[i][j] == '#' && check(i, j)) {
				//printf("%d %d\n", i, j);
				printf("1\n");
				return;
			}
		}
	}
	printf("2\n");
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