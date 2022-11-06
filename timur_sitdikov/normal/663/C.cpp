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

vector<pair<int, char> > g[MAXN];

int used[MAXN][2], col[MAXN][2];
vi tot[2], ans[2];
int impossible[2];
int cnt[2];

int dfs(int s, int ind, char sym){
	used[s][ind] = 1;
	tot[ind].pb(s);
	REP(i, 0, SZ(g[s])){
		int to = g[s][i].first;
		char sym2 = g[s][i].second;
		if (!used[to][ind]){
			col[to][ind] = (sym == sym2 ? col[s][ind] : col[s][ind] ^ 1);
			if (dfs(to, ind, sym)){
				return 1;
			}
		} else {
			if (sym == sym2 && col[s][ind] != col[to][ind] || sym != sym2 && col[s][ind] == col[to][ind]){
				return 1;
			}
		}
	}
	return 0;
}

void solve(){
	int n, m, a, b;
	char s[10];
	scanf("%d%d", &n, &m);
	REP(i, 0, m){
		scanf("%d%d%s", &a, &b, &s[0]);
		g[a].pb(mp(b, s[0]));
		g[b].pb(mp(a, s[0]));
	}
	REPN(i, 1, n){
		if (!used[i][0]){
			REP(j, 0, 2){
				tot[j].clear();
				char sym = (j == 0 ? 'R' : 'B');
				if (dfs(i, j, sym)){
					impossible[j] = 1;
				} else {
					cnt[0] = cnt[1] = 0;
					REP(k, 0, SZ(tot[j])){
						int ind = tot[j][k];
						cnt[col[ind][j]]++;
					}
					int mini = (cnt[0] < cnt[1] ? 0 : 1);
					REP(k, 0, SZ(tot[j])){
						int ind = tot[j][k];
						if (col[ind][j] == mini){
							ans[j].pb(ind);
						}
					}
				}
			}			
		}
	}
	if (impossible[0] && impossible[1]){
		printf("-1\n");
		return;
	}
	int mini = (impossible[0] ? 1 : (impossible[1] ? 0 : (SZ(ans[0]) < SZ(ans[1]) ? 0 : 1)));
	printf("%d\n", SZ(ans[mini]));
	REP(i, 0, SZ(ans[mini])){
		printf("%d ", ans[mini][i]);
	}
	putchar('\n');
}	

int main(){
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();	
	}
}