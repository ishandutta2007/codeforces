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
const int MAXN = 1e6 + 5;
const ll MOD = 1e9 + 7;

vi vals[MAXN], ans[MAXN];
pair<int, pii> coord[MAXN];

int dpi[MAXN], dpj[MAXN];

vi g[2 * MAXN];

int used[2 * MAXN];
vector<int> ind1, ind2;


void dfs(int s){
	int i, to;
	ind2.pb(s);
	used[s] = 1;
	REP(i, 0, SZ(g[s])){
		to = g[s][i];
		if (!used[to]){
			dfs(to);
		}
	}
}

void solve(){
	int n, m, i, j, k, l, i0, j0, cnt;
	scanf("%d%d", &n, &m);
	cnt = 0;
	REP(i, 0, n){
		vals[i].resize(m);
		ans[i].resize(m);
		REP(j, 0, m){
			scanf("%d", &vals[i][j]);
			coord[cnt++] = mp(vals[i][j], mp(i, j));
		}
	}
	sort(coord, coord + cnt);
	/*REP(i, 0, cnt){
		printf("%d %d\n", i, coord[i].first);
	}*/
	for(i = 0; i < cnt; ){
		ind1.clear();
		for(j = i; j < cnt && coord[j].first == coord[i].first; j++){
			i0 = coord[j].second.first;
			j0 = coord[j].second.second;
			ind1.pb(i0);
			ind1.pb(MAXN + j0);			
		}
		REP(j, 0, SZ(ind1)){
			int s = ind1[j];
			g[s].clear();
			used[s] = 0;
		}
		for(j = i; j < cnt && coord[j].first == coord[i].first; j++){
			i0 = coord[j].second.first;
			j0 = coord[j].second.second;
			g[i0].pb(MAXN + j0);
			g[MAXN + j0].pb(i0);
		}
		i = j;
		REP(j, 0, SZ(ind1)){
			int s = ind1[j];
			if (!used[s]){
				ind2.clear();
				dfs(s);
				int mx = 0;
				REP(k, 0, SZ(ind2)){
					i0 = ind2[k];
					if (i0 < MAXN){
						REP(l, 0, SZ(g[i0])){
							j0 = g[i0][l];
							j0 -= MAXN;
							mx = max(mx, dpi[i0]);
							mx = max(mx, dpj[j0]);
						}
					}
				}
				mx++;
				REP(k, 0, SZ(ind2)){
					i0 = ind2[k];
					if (i0 < MAXN){
						dpi[i0] = mx;
						REP(l, 0, SZ(g[i0])){
							j0 = g[i0][l];
							j0 -= MAXN;
							dpj[j0] = mx;
							ans[i0][j0] = mx;
						}
					}
				}
			}
		}
	}
	REP(i, 0, n){
		REP(j, 0, m){
			printf("%d ", ans[i][j]);
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