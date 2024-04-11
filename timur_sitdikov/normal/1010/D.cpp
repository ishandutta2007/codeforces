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

const int MAXN = 1e6 + 5;

vi g[MAXN];
int type[MAXN];
int value[MAXN];

int found[MAXN];

void dfs_calc(int s){
	REP(i, 0, SZ(g[s])){
		int to = g[s][i];
		dfs_calc(to);
	}
	int a, b;
	if (type[s] == 'I'){
		return;
	}
	a = g[s][0];
	if (type[s] == 'N'){
		value[s] = (value[a] ^ 1);
		return;
	}
	b = g[s][1];
	if (type[s] == 'A'){
		value[s] = (value[a] & value[b]);
	} else if (type[s] == 'O') {
		value[s] = (value[a] | value[b]);
	} else if (type[s] == 'X') {
		value[s] = (value[a] ^ value[b]);
	}
}

void dfs_find(int s){
	//printf("%d %d\n", s, value[s]);
	
	
	if (type[s] == 'I'){
		found[s] = 1;
		return;
	}
	int a, b;
	a = g[s][0];
	if (type[s] == 'N'){
		dfs_find(a);
		return;
	}
	b = g[s][1];
	if (type[s] == 'A'){
		if (value[s] == 1){
			dfs_find(a);
			dfs_find(b);
		} else {
			if (value[a] == 1) {
				dfs_find(b);
			}
			if (value[b] == 1) {
				dfs_find(a);
			}
		}
	} else if (type[s] == 'O') {
		if (value[s] == 1){
			if (value[b] == 0) {
				dfs_find(a);
			}
			if (value[a] == 0) {
				dfs_find(b);
			}
		} else {
			dfs_find(a);
			dfs_find(b);
		}
	} else if (type[s] == 'X') {
		dfs_find(a);
		dfs_find(b);
	}
}

void solve(){
	int n, a, b;
	char c[10];
	scanf("%d", &n);
	REPN(i, 1, n){
		scanf("%s%d", &c[0], &a);
		type[i] = c[0];
		if (c[0] == 'A' || c[0] == 'O' || c[0] == 'X'){
			scanf("%d", &b);
			g[i].pb(a);
			g[i].pb(b);
		} else if (c[0] == 'N'){
			g[i].pb(a);
		} else if (c[0] == 'I'){
			value[i] = a;
		}
	}
	dfs_calc(1);
	dfs_find(1);
	//printf("%d\n", value[1]);
	REPN(i, 1, n){
		if (type[i] == 'I') {
			putchar((value[1] ^ found[i]) + '0');
		}
	}
	printf("\n");
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