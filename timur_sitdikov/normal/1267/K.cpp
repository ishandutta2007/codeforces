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

const int MAXN = 50;

map<int, int> cnt;
vi vv;
int len;

ll c[MAXN][MAXN];

void init() {
	REP(i, 0, MAXN) {
		c[i][0] = c[i][i] = 1ll;
		REP(j, 1, i) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
}
ll calc() {
	ll ans = 1ll;
	FA(it, cnt) {
		int val = -(it->_1);
		int available = len - val;
		if (val) {
			available++;
		}
		//printf("%d %d %d\n", len, available, it->_2);
		ll mul = c[available][it->_2];
		ans *= mul;
		len -= it->_2;
	}
	return ans;
}

void solve(){
	ll n;
	scanf("%lld", &n);
	cnt.clear();
	int my_len = 0;
	for(int i = 2; n; i++) {
		//printf("%d ", n % i);
		cnt[-(n % i)]++;
		n /= i;
		my_len++;
	}
	//putchar('\n');
	len = my_len;
	ll ans = calc();
	if (cnt.count(0)) {
		cnt[0]--;
		if (cnt[0] == 0) {
			cnt.erase(0);
		}
		len = my_len - 1;
		ans -= calc();
	}
	printf("%lld\n", ans - 1);
}   

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	init();
    int t = 1;
    cin >> t;
    while(t--){
        solve();    
    }
}