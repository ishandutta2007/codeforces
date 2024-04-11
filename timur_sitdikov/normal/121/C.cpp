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
#define j0 gray_cat_j0

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 16;
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

const int MAXN = 20;

set<ll> goods;

ll f[MAXN];

void gen() {
	REPN(i, 1, 10) {
		REP(j, 0, 1 << i) {
			ll v = 0;
			ll st10 = 1;
			REP(k, 0, i) {
				// v *= 10;
				if (j & (1 << k)) {
					v += 7 * st10;
				} else {
					v += 4 * st10;
				}
				st10 *= 10;
			}
			goods.insert(v);
		}
	}
}

int per[MAXN];
int used[MAXN];

void solve(){
	gen();
	ll n, k;
	cin >> n >> k;
	f[0] = 1;
	int m;
	for(m = 1; ; m++) {
		f[m] = f[m - 1] * m;
		if (f[m] >= k) {
			break;
		}
	}
	if (m > n) {
		printf("-1\n");
		return;
	}
	int ans = 0;
	int offset = n - m;
	FA(it, goods) {
		if ((*it) <= offset) {
			ans++;
		}
	}
	k--;
	int top = 1;
	for(int i = m; i >= 1; i--) {
		int v = k / f[i - 1] + 1;
		int cnt = 0;
		REPN(j, 1, m) {
			if (!used[j]) {
				cnt++;
				if (cnt == v) {
					per[top++] = j;
					used[j] = 1;
					break;
				}
			}
		}
		k %= f[i - 1];
	}
	
	/*REPN(i, 1, m) {
		printf("%d ", per[i]);
	}
	putchar('\n');*/
	
	REPN(i, 1, m) {
		//printf("%d %d\n", i + offset, per[i] + offset);
		if (goods.count(i + offset) && goods.count(per[i] + offset)) {
			ans++;
		}
	}
	cout << ans << endl;
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