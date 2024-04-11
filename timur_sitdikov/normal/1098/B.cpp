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

const int MAXN = 3e5 + 5;

char c[MAXN];
string s;

int n, m;

vector<char> per;
int mode;

vector<string> g, g_ans;

map<pair<vector<char>, int>, int> cnt;

void calc_answer(bool fill = false) {
	int tot = 0;
	if (mode == 0) {
		REP(i, 0, n) {
			int d[2];
			char s[2][2];
			
			REP(j, 0, 2) {
				s[j][0] = per[(i % 2) * 2 + (0 ^ j)];
				s[j][1] = per[(i % 2) * 2 + (1 ^ j)];
				d[j] = 0;
				REP(k, 0, m) {
					if (g[i][k] != s[j][k % 2]) {
						d[j]++;
					}
				}
			}
			
			tot += min(d[0], d[1]);
			
			if (fill) {
				int j0 = (d[0] < d[1] ? 0 : 1);
				REP(k, 0, m) {
					g_ans[i][k] = s[j0][k % 2];
				}
			}
		}
	} else {
		REP(i, 0, m) {
			int d[2];
			char s[2][2];
			
			REP(j, 0, 2) {
				s[j][0] = per[(i % 2) * 2 + (0 ^ j)];
				s[j][1] = per[(i % 2) * 2 + (1 ^ j)];
				d[j] = 0;
				REP(k, 0, n) {
					if (g[k][i] != s[j][k % 2]) {
						d[j]++;
					}
				}
			}
			
			tot += min(d[0], d[1]);
			
			if (fill) {
				int j0 = (d[0] < d[1] ? 0 : 1);
				REP(k, 0, n) {
					g_ans[k][i] = s[j0][k % 2];
				}
			}
		}
	}
	
	cnt[mp(per, mode)] = tot;
}

void solve(){
	scanf("%d%d", &n, &m);
	REP(i, 0, n) {
		scanf("%s", &c[0]);
		s = c;
		g.pb(s);		
	}
	
	per.resize(4);
	per[0] = 'A';
	per[1] = 'C';
	per[2] = 'G';
	per[3] = 'T';
	REP(i, 0, 24) {
		REP(j, 0, 2) {
			mode = j;
			calc_answer(false);
		}
		next_permutation(BE(per));
	}
	int best = n * m + 1;
	FA(it, cnt) {
		if (it->_2 < best) {
			best = it->_2;
			per = it->_1._1;
			mode = it->_1._2;
		}
	}
	g_ans = g;
	calc_answer(true);
	REP(i, 0, n) {
		REP(j, 0, m) {
			c[j] = g_ans[i][j];
		}
		c[m] = 0;
		printf("%s\n", c);
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