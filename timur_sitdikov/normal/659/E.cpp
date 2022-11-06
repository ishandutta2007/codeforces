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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;

vi g[MAXN];
int used[MAXN], prv[MAXN];
int fl_dfs;

void dfs(int s){
	int to;
	used[s] = 1;
	REP(i, 0, SZ(g[s])){
		to = g[s][i];
		if (!used[to]){
			prv[to] = s;
			dfs(to);
		} else if (to != prv[s]){
			fl_dfs = 1;
		}
		
	}
}


void solve(){
	int n, m, a, b;
	scanf("%d%d", &n, &m);
	REP(i, 0, m){
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	int ans = 0;
	REPN(i, 1, n){
		if (!used[i]){
			fl_dfs = 0;
			dfs(i);
			ans += 1 - fl_dfs;
		}
	}
	printf("%d\n", ans);
}	

int main(){
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();	
	}
}