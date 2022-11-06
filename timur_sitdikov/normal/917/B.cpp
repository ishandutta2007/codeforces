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

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 1e2 + 5;

int dp[MAXN][MAXN][26][2];

int g[MAXN][MAXN];

int order[MAXN], top_order;

int n;

int used[MAXN];

void dfs(int s){
	used[s] = 1;
	REPN(i, 1, n){
		if (g[s][i] && !used[i]){
			dfs(i);
		}
	}
	order[top_order++] = s;
}

void upd_ans(int a, int b){
	//printf("%d %d\n", a, b);
	REP(k, 0, 26){
		dp[a][b][k][0] = 1;
		dp[a][b][k][1] = 0;
		REPN(i, 1, n){
			if (g[a][i]){
				int k1 = g[a][i] - 'a';
				if (k1 >= k && dp[i][b][k1][1] == 0){
					dp[a][b][k][0] = 0;
				}
			}
			if (g[b][i]){
				int k1 = g[b][i] - 'a';
				if (k1 >= k && dp[a][i][k1][0] == 1){
					dp[a][b][k][1] = 1;
				}
			}
		}
	}
}

void solve(){
	int m, a, b;
	char s[10];
	scanf("%d%d", &n, &m);
	REP(i, 0, m){
		scanf("%d%d%s", &a, &b, &s[0]);
		g[a][b] = s[0];
	}
	REPN(i, 1, n){
		if (!used[i]){
			dfs(i);
		}
	}
	reverse(order, order + n);
	for(int i = n - 1; i >= 0; i--){
		a = order[i];
		for(int j = n - 1; j >= i; j--){
			b = order[j];
			upd_ans(a, b);
			if (a != b){
				upd_ans(b, a);
			}
		}
	}
	REPN(i, 1, n){
		REPN(j, 1, n){
			putchar(dp[i][j][0][0] + 'A');
		}
		putchar('\n');
	}
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