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
const int MAXN = 3e5 + 5;
const ll MOD = 1e9 + 7;

vi g[MAXN];
int prv[MAXN], sz[MAXN], ans[MAXN];

void dfs(int s){
	sz[s] = 1;
	REP(i, 0, SZ(g[s])){
		int to = g[s][i];
		dfs(to);
		sz[s] += sz[to];
	}
	ans[s] = s;
	REP(i, 0, SZ(g[s])){
		int to = g[s][i];
		if (sz[to] * 2 > sz[s]){
			for(ans[s] = ans[to]; sz[ans[s]] * 2 <= sz[s]; ans[s] = prv[ans[s]]);
		}
	}
}

void solve(){
	int n, q, a;
	scanf("%d%d", &n, &q);
	REPN(i, 2, n){
		scanf("%d", &prv[i]);
		g[prv[i]].pb(i);
	}
	dfs(1);	
	for(; q; q--){
		scanf("%d", &a);
		printf("%d\n", ans[a]);
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