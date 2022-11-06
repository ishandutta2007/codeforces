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

const int MAXN = 1e3 + 5;

set<pii> stp;
pii pp[MAXN];

void solve(){
	int n;
	scanf("%d", &n);
	pii p_mx;
	REP(i, 0, n) {
		pii p;
		scanf("%d%d", &p._1, &p._2);
		stp.insert(p);
	}
	REP(i, 0, n) {
		scanf("%d%d", &pp[i]._1, &pp[i]._2);
		if (i == 0) {
			p_mx = pp[0];
		}
		p_mx = max(p_mx, pp[i]);
	}
	pii ans = *stp.begin();
	ans._1 += p_mx._1;
	ans._2 += p_mx._2;
	printf("%d %d\n", ans._1, ans._2);
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