#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
typedef double DOUBLE;
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 10;
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

const int MAXN = 2e5 + 5;

map<int, int> cnt;

pii pp[MAXN];

ll cur;

void solve(){
	int n;
	scanf("%d", &n);
	REP(i, 0, n) {
		scanf("%d", &pp[i]._1);
	}
	REP(i, 0, n) {
		scanf("%d", &pp[i]._2);
	}
	sort(pp, pp + n);
	ll ans = 0ll;
	int pos = 0;
	for(int i = 0; i < n || !cnt.empty(); ) {
		if (cnt.empty()) {
			pos = pp[i]._1;
		}
		for(; i < n && pp[i]._1 == pos; i++) {
			cur += pp[i]._2;
			cnt[pp[i]._2]++;
		}
		int a = cnt.rbegin()->_1;
		cur -= a;
		cnt[a]--;
		if (cnt[a] == 0) {
			cnt.erase(a);
		}
		ans += cur;
		pos++;
	}
	printf("%lld\n", ans);
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