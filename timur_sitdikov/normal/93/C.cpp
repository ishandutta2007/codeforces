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

const int MAXN = 256;

set<vi> states[6];

map<vi, pair<int, pii> > prv;

vi coef = {1, 2, 4, 8};

int ans[MAXN];
vector<pair<int, pii> > ans_pp[MAXN];

void solve(){
	int M = 4;
	states[0].insert({1});
	REPN(m, 1, M) {
		FA(it, states[m - 1]) {
			vi state = *it;
			int mn = state[m - 1] + 1;
			state.pb(0);
			REP(i, 0, m) {
				REP(k, 0, SZ(coef)) {
					int val1 = state[i] * coef[k];
					if (val1 >= mn && val1 < MAXN) {
						state[m] = val1;
						states[m].insert(state);
						prv[state] = mp(-1, mp(i, k));
					}
					REP(j, 0, m) {
						int val2 = state[i] * coef[k] + state[j];
						if (val2 >= mn && val2 < MAXN) {
							state[m] = val2;
							states[m].insert(state);
							prv[state] = mp(j, mp(i, k));
						}
					}
				}
			}
		}
	}
	REP(i, 0, MAXN) {
		ans[i] = INF;
	}
	REPN(m, 0, M) {
		//printf("******************************\n");
		//printf("%d: %d\n", m, SZ(states[m]));
		FA(it, states[m]) {
			vi state = *it;
			REP(i, 0, SZ(state)) {
				//printf("%d ", state[i]);
				if (ans[state[i]] == INF) {
					ans[state[i]] = m;
					vi tmp = state;
					for(int j = m; j; j--) {
						ans_pp[state[i]].pb(prv[tmp]);
						tmp.pop_back();
					}
				}
			}
			//putchar('\n');
		}
	}
	ans[254] = 5;
	ans_pp[254].pb(mp(0, mp(4, 0)));
	REP(i, 0, SZ(ans_pp[253])) {
		ans_pp[254].pb(ans_pp[253][i]);
	}
	
	int n;
	cin >> n;
	printf("%d\n", ans[n]);
	for(int j = ans[n] - 1, k = 1; j >= 0; j--, k++) {
		printf("lea e%cx, [", 'a' + (char)k);
		if (ans_pp[n][j]._1 != -1) {
			printf("e%cx + ", 'a' + (char)ans_pp[n][j]._1);
		}
		printf("%d*e%cx]\n", coef[ans_pp[n][j]._2._2], 'a' + (char)ans_pp[n][j]._2._1);
	}
	
	/*printf("******************************\n");
	REP(i, 0, MAXN) {
		printf("%d: %d\n", i, ans[i]);
	}*/
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