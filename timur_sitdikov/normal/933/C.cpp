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

const int MAXN = 1e5 + 5;

vector<pair<double, double> > pp0, pp;
vector<int> vv;

int g[3][3];

void get_intersections(int x1, int y1, int r1, int ind1, int x2, int y2, int r2, int ind2){
	if (x1 == x2 && y1 == y2){
		return;
	}
	int a = -2 * (x2 - x1);
	int b = -2 * (y2 - y1);
	int c = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + r1 * r1 - r2 * r2;
	double x0 = -a * c / (a * a + b * b + 0.0),  y0 = -b * c / (a * a + b * b + 0.0);
	if (c * c > r1 * r1 * (a * a + b * b)){
		return;
	} else if (c * c == r1 * r1 * (a * a + b * b)) {
		pp0.pb(mp(x0 + x1, y0 + y1));
	}
	else {
		double d = r1 * r1 - c * c / (a * a + b * b + 0.0);
		double mult = sqrt(d / (a * a + b * b + 0.0));
		double ax, ay, bx, by;
		ax = x0 + b * mult;
		bx = x0 - b * mult;
		ay = y0 - a * mult;
		by = y0 + a * mult;
		pp0.pb(mp(ax + x1, ay + y1));
		pp0.pb(mp(bx + x1, by + y1));
	}
	g[ind1][ind2] = g[ind2][ind1] = 1;
}

bool on_circle(double x0, double y0, double r, double x, double y){
	return fabs((x0 - x) * (x0 - x) + (y0 - y) * (y0 - y) - r * r) < EPS;
}

int x[3], y[3], r[3];

int cnt[3];

int used[MAXN];

int dfs(int s, int n, int col){
	used[s] = col;
	REP(i, 0, n){
		if (g[s][i] && !used[i]){
			dfs(i, n, col);
		}
	}
}

void solve(){
	int n;
	scanf("%d", &n);
	REP(i, 0, n){
		scanf("%d%d%d", &x[i], &y[i], &r[i]);
	}
	REP(i, 0, n){
		REP(j, i + 1, n){
			get_intersections(x[i], y[i], r[i], i, x[j], y[j], r[j], j);
		}
	}
	REP(i, 0, SZ(pp0)){
		
		//cout << pp0[i]._1 << " " << pp0[i]._2 << endl;
		
		int fl = 0;
		REP(j, i + 1, SZ(pp0)){
			if (fabs(pp0[i]._1 - pp0[j]._1) + fabs(pp0[i]._2 - pp0[j]._2) < EPS){
				fl = 1;
			}
		}
		if (!fl){
			pp.pb(pp0[i]);
		}
	}
	
	REP(i, 0, n){
		REP(j, 0, SZ(pp)){
			if (on_circle(x[i], y[i], r[i], pp[j]._1, pp[j]._2)){
				cnt[i]++;
			}
			/*if (fabs((x[i] - pp[j]._1) * (x[i] - pp[j]._1) + (y[i] - pp[j]._2) * (y[i] - pp[j]._2) - r[i] * r[i]) < EPS){
				cnt[i]++;
			}*/
		}
	}
	REP(i, 0, SZ(pp)){
		vv.pb(0);
	}
	
	int ans = 1;
	int col = 1;
	REP(i, 0, n){
		if (!used[i]){
			dfs(i, n, col);
			ans++;
			REP(j, 0, n){
				if (used[j] == col){
					ans += cnt[j];
					REP(k, 0, SZ(vv)){
						if (vv[k] != col && on_circle(x[j], y[j], r[j], pp[k]._1, pp[k]._2)){
							vv[k] = col;
							ans--;
						}
					}
				}
			}
			col++;
			//printf("%d\n", ans);
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