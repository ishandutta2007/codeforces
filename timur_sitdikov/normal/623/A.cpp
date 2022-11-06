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
const int MAXN = 505;
const ll MOD = 1e9 + 7;

int g[MAXN][MAXN];

char ans[MAXN];

void solve(){
	int i, j, k, n, m, a, b;
	scanf("%d%d", &n, &m);
	REP(i, 0, m){
		scanf("%d%d", &a, &b);
		g[a][b] = g[b][a] = 1;
	}
	for(i = 1; i <= n; i++){
		int cnt = 0;
		for(j = 1; j <= n; j++){
			cnt += g[i][j];
		}
		if (cnt == n - 1){
			ans[i] = 'b';
		}
	}
	for(i = 1; i <= n; i++){
		if (!ans[i]){
			ans[i] = 'a';
			for(j = 1; j <= n; j++){
				if (!ans[j] && !g[i][j]){
					ans[j] = 'c';
				} else if (!ans[j] && g[i][j]){
					ans[j] = 'a';
				}
			}
			for(i = 1; i <= n; i++){
				for(j = 1; j <= n; j++){
					if (i == j){
						continue;
					}
					if (g[i][j] && ans[i] == 'a' && ans[j] == 'c'){
						//printf("1 %d %d\n", i, j);
						printf("No\n");
						return;
					}
					if (!g[i][j] && ans[i] == ans[j]){
						//printf("2 %d %d\n", i, j);
						printf("No\n");
						return;
					}
				}
			}
			break;
		}
	}
	printf("Yes\n%s\n", &ans[1]);
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