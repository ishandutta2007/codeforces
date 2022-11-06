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

pii pp[MAXN];
int cnt[2];
vi ans;

void output() {
	printf("%d\n", SZ(ans));
	REP(i, 0, SZ(ans)) {
		printf("%d ", ans[i] + 1);
	}
	putchar('\n');
}


void solve(){
	int n;
	scanf("%d", &n);
	REP(i, 0, n) {
		scanf("%d%d", &pp[i]._1, &pp[i]._2);
		pp[i]._1 += 1e6;
		pp[i]._2 += 1e6;
	}
	int it = 0;
	while(1) {
		int st2 = 1 << 25;
		REP(i, 0, n) {
			st2 = gcd(st2, pp[i]._1);
			st2 = gcd(st2, pp[i]._2);
		}
		cnt[0] = cnt[1] = 0;
		REP(i, 0, n) {
			pp[i]._1 /= st2;
			pp[i]._2 /= st2;
			cnt[(pp[i]._1 & 1) ^ (pp[i]._2 & 1)]++;
		}
		if (cnt[0] && cnt[1]) {
			REP(i, 0, n) {
				if ((pp[i]._1 & 1) ^ (pp[i]._2 & 1)) {
					ans.pb(i);
				}
			}
			output();
			return;
		}
		if (cnt[1] == 0) {
			int cnt1 = 0, cnt2 = 0;
			REP(i, 0, n) {
				if (pp[i]._1 & 1) {
					cnt1++;
				} else {
					cnt2++;
				}
			}
			if (cnt1 > 0 && cnt2 > 0) {
				REP(i, 0, n) {
					if (pp[i]._1 & 1) {
						ans.pb(i);
					}
				}
				output();
				return;
			}
			REP(i, 0, n) {
				pp[i]._1++;
				pp[i]._2++;
			}
		} else {
			int cnt1 = 0, cnt2 = 0;
			REP(i, 0, n) {
				if (pp[i]._1 & 1) {
					cnt1++;
				} else {
					cnt2++;
				}
			}
			if (cnt2 > cnt1) {
				REP(i, 0, n) {
					pp[i]._2++;
				}
			} else {
				REP(i, 0, n) {
					pp[i]._1++;
				}
			}
		}
		
		/*it++;
		printf("%d\n", it);
		REP(i, 0, n) {
			printf("%d %d\n", pp[i]._1, pp[i]._2);
		}
		if (it == 10) {
			return;
		}*/
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