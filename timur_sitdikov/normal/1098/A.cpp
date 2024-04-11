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
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

const int MAXN = 1e5 + 5;

int p[MAXN];
vi g[MAXN];
int v[MAXN];

void solve(){
	int n;
	scanf("%d", &n);
	REPN(i, 2, n) {
		scanf("%d", &p[i]);
		g[p[i]].pb(i);
	}
	REPN(i, 1, n) {
		scanf("%d", &v[i]);
	}
	REPN(i, 1, n) {
		if (v[i] == -1) {
			int add = INF;
			REP(j, 0, SZ(g[i])){
				int to = g[i][j];
				add = min(add, v[to]);
			}
			if (add < v[p[i]]) {
				printf("-1\n");
				return;
			}
			if (add == INF) {
				add = v[p[i]];
			}
			v[i] = add;
		}
	}
	ll sum = 0ll;
	REPN(i, 1, n) {
		sum += v[i] - v[p[i]];
	}
	printf("%lld\n", sum);
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