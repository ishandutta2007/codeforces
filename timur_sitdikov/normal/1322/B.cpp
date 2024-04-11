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

const int MAXN = 4e5 + 5;
const int MAXLOG = 25;

int v[MAXN];
int vs[2][MAXN];
int top[2];

ll add[MAXLOG + 3];

void solve(){
	int n;
	scanf("%d", &n);
	REP(i, 0, n) {
		scanf("%d", &v[i]);
	}
	REP(i, 0, MAXLOG) {
		int mask = (1 << i);
		
		top[0] = top[1] = 0;
		REP(j, 0, n) {
			if (v[j] & mask) {
				vs[1][top[1]++] = v[j];
			} else {
				vs[0][top[0]++] = v[j];
			}
		}
		
		add[i] += (ll)top[0] * (ll)top[1];
		
		REP(j, 0, top[0]) {
			v[j] = vs[0][j];
		}
		REP(j, 0, top[1]) {
			v[top[0] + j] = vs[1][j];
		}
		
		ll cnt = 0;
		mask = mask * 2 - 1;
		for(int r = n - 1, l = 0; r >= 0; r--) {
			for(; l < r && (v[l] & mask) + (v[r] & mask) <= mask; l++);
			if (l >= r) {
				break;
			}
			cnt += r - l;
		}
		add[i + 1] += cnt;
	}
	
	int ans = 0;
	REP(i, 0, MAXLOG) {
		//printf("%d: %lld\n", i, add[i]);
		if (add[i] & 1) {
			ans |= (1 << i);
		}
	}
	
	printf("%d\n", ans);
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