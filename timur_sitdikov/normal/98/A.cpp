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

const int MAXN = 2e5 + 5;

struct cube {
	vector<char> col;
};

void rotate_1(cube &c) {
	char tmp = c.col[0];
	c.col[0] = c.col[1];
	c.col[1] = c.col[5];
	c.col[5] = c.col[4];
	c.col[4] = tmp;
}

void rotate_2(cube &c) {
	char tmp = c.col[0];
	c.col[0] = c.col[2];
	c.col[2] = c.col[5];
	c.col[5] = c.col[3];
	c.col[3] = tmp;
}

set<vector<char> > st;

char s[MAXN];

int per[MAXN];

void solve(){
	scanf("%s", &s[0]);
	cube c0;
	REP(i, 0, 6) {
		c0.col.pb(s[i]);
	}
	
	st.insert(c0.col);
	REP(i, 0, 6) {
		per[i] = i;
	}
	REP(f, 0, 720) {
		cube ci;
		REP(i, 0, 6) {
			ci.col.pb(c0.col[per[i]]);
		}
		int fl = 0;
		REP(i, 0, 4) {
			cube cj = ci;
			REP(j, 0, 4) {
				cube ck = cj;
				REP(k, 0, 4) {
					cube cl = ck;
					REP(l, 0, 4) {
						if (st.find(cl.col) != st.end()) {
							fl = 1;
							break;
						}
						rotate_2(cl);
					}
					rotate_1(ck);
				}
				rotate_2(cj);
			}
			rotate_1(ci);
		}
		if (!fl) {
			st.insert(ci.col);
		}
		next_permutation(per, per + 6);
	}
	/*FA(it, st) {
		REP(i, 0, 6) {
			putchar((*it)[i]);
		}
		putchar('\n');
	}*/
	printf("%d\n", SZ(st));
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