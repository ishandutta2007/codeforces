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

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

// Graph solving 2-SAT problem
// Works in O(n^2)

// Use:
// 1) Fill gg.n as number of variables (not number of vertices!!!! 
//    Number of vertices will be gg.n * 2)
// 2) Call gg.add_clause(a, val_a, b, val_b) for each clause.
//    For example, for clause !v[i] | v[j] call gg.add_clause(i, 0, j, 1)
// 3) Call gg.build()

// If gg.IsSatisfiable is false there is no solution
// Otherwise answer will be in boolean array gg.result

// Note number of vertices will be twice more than number of variables
const int MAXN = 4e2 + 5;

struct graph{
	// Number of variables (number of vertices will be 2 * n)
	int n;
	
	// Graph
	char g[MAXN][MAXN];
	
	// For dfs
	char used[MAXN];
	
	// For topological sorting
	vector<int> sorted;
	
	// Indices of condensation components for vertices
	int col[MAXN];
	
	// Current condensation component index
	int cur_col;
	
	// If has solution
	bool IsSatisfiable;
	
	bool result[MAXN];
	
	// Clear graph
	void clear(){
		for(int i = 0; i < 2 * n; i++){
			for(int j = 0; j < 2 * n; j++){
				g[i][j] = 0;
			}
		}
	}
	
	// Add edge (process clause (a | b) where val_a indicates whether we use a or !a)
	void add_clause(int a, int val_a, int b, int val_b){
		g[(a << 1) ^ val_a ^ 1][(b << 1) ^ val_b] = 1;
		g[(b << 1) ^ val_b ^ 1][(a << 1) ^ val_a] = 1;
	}
	
	// Dfs with top sorting
	void dfs(int s){
		used[s] = 1;
		for(int i = 0; i < 2 * n; i++){
			if (g[s][i] && !used[i]){
				dfs(i);
			}
		}
		sorted.push_back(s);
	}
	
	// DFS in reverse graph
	void dfs_r(int s){
		used[s] = 1;
		col[s] = cur_col;
		for(int i = 0; i < 2 * n; i++){
			if (g[i][s] && !used[i]){
				dfs_r(i);
			}
		}
	}
	
	// Building condensation
	void get_condensation(){
		// Init
		for(int i = 0; i < 2 * n; i++){
			used[i] = 0;
		}
		sorted.clear();
	
		// First DFS series
		for(int i = 0; i < 2 * n; i++){
			if (!used[i]){
				dfs(i);
			}
		}
		
		// Init
		for(int i = 0; i < 2 * n; i++){
			used[i] = 0;
		}
		cur_col = 0;
		
		// Second DFS series
		for(int i = 2 * n - 1; i >= 0; i--){
			int s = sorted[i];
			if (!used[s]){
				cur_col++;
				dfs_r(s);
			}
		}
	}
	
	void build(){
		// Get condensation
		get_condensation();
		
		// Find satisfability
		IsSatisfiable = true;
		for(int i = 0; i < 2 * n; i += 2){
			if (col[i] == col[i ^ 1]){
				IsSatisfiable = false;
				break;
			}
			if (col[i] > col[i ^ 1]){
				result[i / 2] = false;
			} else {
				result[i / 2] = true;
			}
		}	
	}
};

graph gg;

char tt[200];

char s[MAXN];

char ans[MAXN];

int used[2];

struct implic{
	int a, val_a, b, val_b;
} imp[MAXN * MAXN];

int n, m;

bool check(int r){
	gg.clear();
	
	REP(i, 0, m){
		gg.add_clause(imp[i].a, imp[i].val_a ^ 1, imp[i].b, imp[i].val_b);
	}
	
	REP(i, 0, r){
		gg.add_clause(i, tt[ans[i]], i, tt[ans[i]]);
	}
	
	/*REP(i, 0, 2 * gg.n){
		REP(j, 0, 2 * gg.n){
			printf("%d", gg.g[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');*/
	
	gg.build();
	return gg.IsSatisfiable;
}

void solve(){
	int l;
	int a, b;
	char sa[2], sb[2];
	scanf("%s%d%d", &tt['a'], &n, &m);
	l = strlen(tt + 'a');
	REP(i, 'a', 'a' + l){
		tt[i] = (tt[i] == 'V' ? 0 : 1);
	}
	gg.n = n;
	REP(i, 0, m){
		scanf("%d%s%d%s", &a, &sa[0], &b, &sb[0]);
		a--;
		b--;
		imp[i].a = a, imp[i].val_a = (sa[0] == 'V' ? 0 : 1);
		imp[i].b = b, imp[i].val_b = (sb[0] == 'V' ? 0 : 1);
		
		//printf("%d %d %d %d\n", imp[i].a, imp[i].val_a, imp[i].b, imp[i].val_b);
	}
	scanf("%s", &s[0]);
	REP(i, 0, n){
		ans[i] = s[i];
	}
	if (check(n)){
		printf("%s\n", ans);
		return;
	}
	REP(i, 'a', 'a' + l){
		used[tt[i]] = 1;
	}
	if (!used[0] || !used[1]){
		printf("-1\n");
		return;
	}
	int r;
	for(r = n - 1; r >= 0; r--){
		REP(i, 0, 2){
			used[i] = 0;
		}
		int fl = 0;
		REP(i, s[r] + 1, 'a' + l){
			if (!used[tt[i]]){
				used[tt[i]] = 1;
				ans[r] = i;
				if (check(r + 1)){
					fl = 1;
					break;
				}
			}
		}
		if (fl == 1){
			break;
		}
	}
	if (r == -1){
		printf("-1\n");
		return;
	}
	for(r++; r < n; r++){
		REP(i, 0, 2){
			used[i] = 0;
		}
		int fl = 0;
		int cnt = 0;
		REP(i, 'a', 'a' + l){
			if (!used[tt[i]]){
				used[tt[i]] = 1;
				ans[r] = i;
				if (cnt == 1 || check(r + 1)){
					fl = 1;
					break;
				}
				cnt++;
			}
		}
	}
	printf("%s\n", ans);
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