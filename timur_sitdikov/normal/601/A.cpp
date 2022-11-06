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
#define REPN(i, a, b) for((i) = (a); (i) <= (int)(b); (i)++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 405;
const ll MOD = 1e9 + 7;

int g[MAXN][MAXN];

int dis[2][MAXN];
int n;

queue<int> qq;

void bfs(int s){
	int i, k;
	REP(k, 0, 2){
		REPN(i, 1, n){
			dis[k][i] = INF;
		}
		dis[k][1] = 0;
		qq.push(1);
		while(!qq.empty()){
			int s = qq.front();
			qq.pop();
			REPN(i, 1, n){
				if (g[s][i] == k && dis[k][i] > dis[k][s] + 1){
					dis[k][i] = dis[k][s] + 1;
					qq.push(i);
				}
			}
		}
	}
}

void solve(){
	int m, i, a, b;
	scanf("%d%d", &n, &m);
	REP(i, 0, m){
		scanf("%d%d", &a, &b);
		g[a][b] = g[b][a] = 1;
	}
	bfs(1);
	if (dis[0][n] == INF || dis[1][n] == INF){
		printf("-1\n");
		return;
	}
	printf("%d\n", max(dis[0][n], dis[1][n]));
}	

int main(){
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();	
	}
}