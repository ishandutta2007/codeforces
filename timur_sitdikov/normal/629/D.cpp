#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define REP(i, a, b) for((i) = (int)(a); (i) < (int)(b); (i)++)
#define REPN(i, a, b) for((i) = (int)(a); (i) <= (int)(b); (i)++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;

double tt[4 * MAXN];

void calc(int ind){
	tt[ind] = max(tt[ind << 1], tt[(ind << 1) + 1]);
}

double get_val(int ind, int tl, int tr, int l, int r){
	if (l > r){
		return 0.;
	}
	if (l == tl && r == tr){
		return tt[ind];
	}
	int tm = (tl + tr) >> 1;
	return max(get_val(ind << 1, tl, tm, l, min(r, tm)), get_val((ind << 1) + 1, tm + 1, tr, max(l, tm + 1), r));
}

void upd_val(int ind, int tl, int tr, int pos, double val){
	if (tl == tr){
		tt[ind] = val;
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm){
		upd_val(ind << 1, tl, tm, pos, val);
	} else {
		upd_val((ind << 1) + 1, tm + 1, tr, pos, val);
	}
	calc(ind);
}

pair<double, int> pp[MAXN], pp0[MAXN];

void solve(){
	int n, i, l, r, ind;
	double R, H;
	scanf("%d", &n);
	REP(i, 0, n){
		scanf("%lf%lf", &R, &H);
		pp[i] = mp(PI * R * R * H, i);
		pp0[i] = pp[i];
	}
	sort(pp, pp + n);
	double ans = 0.;
	REP(i, 0, n){
		l = 0;
		ind = lower_bound(pp, pp + n, pp0[i]) - pp;
		r = lower_bound(pp, pp + n, mp(pp0[i].first, 0)) - pp - 1;
		double tmp = get_val(1, 0, n - 1, l, r) + pp0[i].first;
		ans = max(ans, tmp);
		upd_val(1, 0, n - 1, ind, tmp);
	}
	printf("%.12lf\n", ans);
}	

int main(){
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();	
	}
}