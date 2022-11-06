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
const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;

char c[2][MAXN], cc[2][MAXN], ccc[2 * MAXN];
int v[2][MAXN];
ll vv[2][MAXN], vvv[2 * MAXN];

int pfc[2 * MAXN], pfv[2 * MAXN];

void solve(){
	int len[2], top[2], i, j, k;
	
	scanf("%d%d", &len[0], &len[1]);
	REP(i, 0, 2){
		REP(j, 0, len[i]){
			scanf("%d%c%c", &v[i][j], &c[i][j], &c[i][j]);
		}
	}
	
	// printf("%s\n%s\n", c[0], c[1]);
	
	REP(i, 0, 2){
		top[i] = 0;
		REP(j, 0, len[i]){
			if (j > 0 && c[i][j] == c[i][j - 1]){
				vv[i][top[i] - 1] += v[i][j]; 
			} else {
				vv[i][top[i]] = v[i][j];
				cc[i][top[i]] = c[i][j];
				top[i]++;
			}
		}
	}
	
	// printf("%s\n%s\n", cc[0], cc[1]);
	
	/*REP(i, 0, 2){
		REP(j, 0, top[i]){
			printf("%d ", vv[i][j]);
		}
		putchar('\n');
	}*/
	
	ll ans = 0ll;
	
	if (top[0] < top[1]){
		cout << 0 << endl;
		return;
	}
	
	if (top[1] == 1){
		REP(i, 0, top[0]){
			if (cc[0][i] == cc[1][0] && vv[0][i] >= vv[1][0]){
				ans += vv[0][i] - vv[1][0] + 1;
			}
		}
		cout << ans << endl;
		return;
	}
	
	if (top[1] == 2){
		REP(i, 1, top[0]){
			if (cc[0][i - 1] == cc[1][0] && vv[0][i - 1] >= vv[1][0] 
				&& cc[0][i] == cc[1][1] && vv[0][i] >= vv[1][1]){
					
				// printf("%d\n", i);
				
				ans++;
			}
		}
		cout << ans << endl;
		return;
	}	
	
	int lens = top[1] - 2 + 1 + top[0] - 2;
	REP(i, 0, lens){
		if (i < top[1] - 2){
			ccc[i] = cc[1][i + 1];
			vvv[i] = vv[1][i + 1];
		} else if (i == top[1] - 2){
			ccc[i] = '#';
			vvv[i] = -1;
		} else {
			ccc[i] = cc[0][i - (top[1] - 2)];
			vvv[i] = vv[0][i - (top[1] - 2)];
		}
	}
	
	// printf("%s\n", ccc);
	
	REP(i, 1, lens){
		for(j = pfc[i - 1]; j > 0 && ccc[i] != ccc[j]; j = pfc[j - 1]);
		if (ccc[i] == ccc[j]){
			j++;
		}
		pfc[i] = j;
		for(j = pfv[i - 1]; j > 0 && vvv[i] != vvv[j]; j = pfv[j - 1]);
		if (vvv[i] == vvv[j]){
			j++;
		}
		pfv[i] = j;
		
		// printf("%d %d\n", pfc[i], pfv[i]);
		
		if (pfc[i] == top[1] - 2 && pfv[i] == top[1] - 2){
			int r = i - (top[1] - 2 + 1) + 1;
			int l = r - (top[1] - 2) + 1;					
			l--;
			r++;
			
			// printf("%d %d\n", l, r);
			
			// printf("%d %d %d %d\n", vv[0][l], vv[1][0], vv[0][r], vv[1][top[1] - 1]);
			
			if (l >= 0 && cc[0][l] == cc[1][0] && vv[0][l] >= vv[1][0] 
				&& r < top[0] && cc[0][r] == cc[1][top[1] - 1] && vv[0][r] >= vv[1][top[1] - 1]){
				ans++;
			}
		}
		
		
	}
	cout << ans << endl;
}	

int main(){
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();	
	}
}