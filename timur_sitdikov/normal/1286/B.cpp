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

const int MAXN = 2005;

vi g[MAXN];

pii pp[MAXN];
int prv[MAXN];
int dis[MAXN];
int used[MAXN];
int ans[MAXN];

void dfs(int s) {
	REP(i, 0, SZ(g[s])) {
		int to = g[s][i];
		dis[to] = dis[s] + 1;
		dfs(to);
	}
}

void solve(){
	int n;
	scanf("%d", &n);
	int s = 0;
	REPN(i, 1, n) {
		scanf("%d%d", &prv[i], &pp[i]._1);
		if (prv[i] == 0) {
			s = i;
		} else {
			g[prv[i]].pb(i);
		}
	}
	dfs(s);
	REPN(i, 1, n) {
		pp[i]._2 = dis[i];
	}
	REPN(i, 1, n) {
		int ind = 0;
		REPN(j, 1, n) {
			if (!used[j] && (ind == 0 || pp[j] < pp[ind])) {
				ind = j;
			}
		}
		if (pp[ind]._1 != 0) {
			printf("NO\n");
			return;
		}
		used[ind] = 1;
		ans[ind] = i;
		for(int par = prv[ind]; par; par = prv[par]) {
			if (!used[par]) {
				pp[par]._1--;
			}
		}
	}
	
	printf("YES\n");
	REPN(i, 1, n) {
		printf("%d ", ans[i]);
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