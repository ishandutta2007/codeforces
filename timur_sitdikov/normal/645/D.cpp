#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<long double> point;
#define xx real()
#define yy imag()

#define REP(i, a, b) for((i) = (a); (i) < (int)(b); (i)++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;

vector<int> g[MAXN];

vector<int> sorted;

pii ee[MAXN];
int used[MAXN];
int n;

void dfs(int s){
	int i, to;
	used[s] = 1;
	REP(i, 0, SZ(g[s])){
		to = g[s][i];
		if (!used[to]){
			dfs(to);
		}
	}
	sorted.pb(s);
}

int check(int v){
	int i, j;
	for(i = 1; i <= n; i++){
		used[i] = 0;
		g[i].clear();
	}
	REP(i, 0, v){
		g[ee[i].first].pb(ee[i].second);
	}
	sorted.clear();
	for(i = 1; i <= n; i++){
		if (!used[i]){
			dfs(i);
		}
	}
	/*printf("%d\n", v);
	REP(i, 0, SZ(sorted)){
		printf("%d ", sorted[i]);
	}
	putchar('\n');*/
	for(i = SZ(sorted) - 1; i > 0; i--){
		int a = sorted[i], b = sorted[i - 1];
		int fl = 0;
		REP(j, 0, SZ(g[a])){
			if (g[a][j] == b){
				fl = 1;
				break;
			}
		}
		if (!fl){
			return 0;
		}
	}
	return 1;
}

void solve(){
	int m, i;
	scanf("%d%d", &n, &m);
	REP(i, 0, m){
		scanf("%d%d", &ee[i].first, &ee[i].second);		
	}
	if (!check(m)){
		printf("-1\n");
		return;
	}
	int l = 0, r = m;
	for(; l + 1 < r; ){
		int mid = (l + r) >> 1;
		if(check(mid)){
			r = mid;
		} else {
			l = mid;
		}
	}
	cout << r << endl;
}	

int main(){
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();	
	}
}