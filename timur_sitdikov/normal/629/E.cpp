#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define REP(i, a, b) for((i) = (int)(a); (i) < (int)(b); (i)++)
#define REPN(i, a, b) for((i) = (int)(a); (i) <= (int)(b); (i)++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 1e5 + 5, MAXLOG = 18;
const ll MOD = 1e9 + 7;

vi g[MAXN];
int prv[MAXN][MAXLOG], tin[MAXN], tout[MAXN], timer, dis[MAXN];
ll dp_sum[MAXN], dp_sum_prv[MAXN];
int cnt[MAXN];
int n;

void dfs(int s, int p = 1){
	int i, to;
	tin[s] = ++timer;
	prv[s][0] = p;
	REP(i, 1, MAXLOG){
		prv[s][i] = prv[prv[s][i - 1]][i - 1];
	}
	REP(i, 0, SZ(g[s])){
		to = g[s][i];
		if (to != p){
			dis[to] = dis[s] + 1;
			dfs(to, s);
			dp_sum[s] += dp_sum[to] + cnt[to];
			cnt[s] += cnt[to];
		}
	}	
	tout[s] = ++timer;
	cnt[s]++;
}

void dfs1(int s){
	int i, to;
	REP(i, 0, SZ(g[s])){
		to = g[s][i];
		if (to != prv[s][0]){
			dp_sum_prv[to] = (dp_sum[s] - (dp_sum[to] + cnt[to]) + dp_sum_prv[s]) + (n - cnt[to]);
			dfs1(to);
		}
	}
}

bool is_prv(int a, int b) {
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
	if (is_prv(a, b)){
		return a;
	}
	if (is_prv(b, a)){
		return b;
	}	
	for (int i = MAXLOG - 1; i >= 0; i--){
		if (!is_prv(prv[a][i], b)){
			a = prv[a][i];
		}
	}
	return prv[a][0];
}

int get_prv(int s, int d){
	for(int i = MAXLOG - 1, st2 = 1 << (MAXLOG - 1); i >= 0 && d; i--, st2 >>= 1){
		if (st2 <= d){
			d -= st2;
			s = prv[s][i];
		}
	}
	return s;
}

void solve(){
	int i, a, b, q;
	scanf("%d%d", &n, &q);
	REP(i, 1, n){
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	REP(i, 0, MAXLOG){
		prv[1][i] = 1;
	}
	dfs(1);	
	dfs1(1);
	while(q--){
		scanf("%d%d", &a, &b);
		if (dis[a] > dis[b]){
			swap(a, b);
		}
		int p = lca(a, b);
		double sa, sb = dp_sum[b] / (cnt[b] + 0.);
		if (p == a){
			int b1 = get_prv(b, dis[b] - (dis[p] + 1));
			sa = (dp_sum[a] - (dp_sum[b1] + cnt[b1]) + dp_sum_prv[a]) / (n - cnt[b1] + 0.);
		} else {
			sa = dp_sum[a] / (cnt[a] + 0.);
		}
		// cout << a << " " << dis[a] << " " << sa << " " << b << " " << dis[b] << " " << sb << endl;
		double ans = sa + sb + dis[a] + dis[b] - 2. * dis[p] + 1.;
		printf("%.12lf\n", ans);
	}
}	

int main(){
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();	
	}
}