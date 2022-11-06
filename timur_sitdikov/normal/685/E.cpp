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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 1e3 + 5, MAXE = 2e5 + 5, MAXQ = 2e5 + 5;
const ll MOD = 1e9 + 7;

struct query{
	int l, r, s, t, index;
} qq[MAXQ];

bool cmp(int q_ind1, int q_ind2){
	return qq[q_ind1].l < qq[q_ind2].l;
}

int g[MAXN][MAXN];
pii ee[MAXE];

vi qq_ind[MAXN];
int v_ind[MAXN];
int ans[MAXQ];

void process_vertex(int v, int t){
	for(; v_ind[v] >= 0; v_ind[v]--){
		int ind = qq_ind[v][v_ind[v]];
		if (qq[ind].l <= t){
			break;
		}
		int to = qq[ind].t;
		if (g[v][to] <= qq[ind].r){
			ans[qq[ind].index] = 1;
		}		
	}
}

void solve(){
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	REPN(i, 1, m){
		scanf("%d%d", &ee[i].first, &ee[i].second);
	}
	REP(i, 0, q){
		scanf("%d%d%d%d", &qq[i].l, &qq[i].r, &qq[i].s, &qq[i].t);
		qq[i].index = i;
		qq_ind[qq[i].s].pb(i);
	}
	REPN(i, 1, n){
		sort(qq_ind[i].begin(), qq_ind[i].end(), cmp);
		v_ind[i] = SZ(qq_ind[i]) - 1;
	}
	REPN(i, 1, n){
		REPN(j, 1, n){
			g[i][j] = INF;
		}
	}
	for(int i = m; i > 0; i--){
		int a = ee[i].first, b = ee[i].second;
		process_vertex(a, i);
		process_vertex(b, i);
		REPN(j, 1, n){
			if (g[a][j] > g[b][j]){
				g[a][j] = g[b][j];
			} else {
				g[b][j] = g[a][j];
			}
		}
		g[a][a] = g[b][b] = i;
		g[a][b] = g[b][a] = i;
	}
	REPN(i, 1, n){
		process_vertex(i, 0);
	}
	REP(i, 0, q){
		printf("%s\n", ans[i] ? "Yes" : "No");
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