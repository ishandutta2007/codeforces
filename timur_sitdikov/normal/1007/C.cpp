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

vector<ll> x, y, c12, c23, c13;
ll a, b;

int get_response(ll xcur, ll ycur){
	int t;
	
	scanf("%d", &t);
	/*if (xcur == a && ycur == b) {
		return 0;
	}
	
	int ind = 0;
	REP(i, 1, SZ(x)){
		if (abs(x[i] - xcur) + abs(y[i] - ycur) < abs(x[ind] - xcur) + abs(y[ind] + ycur)) {
			ind = i;
		}
	}
	
	if (xcur < a && ycur < b) {
		return c12[ind];
	}
	if (xcur < a && ycur > b) {
		return c13[ind];
	}
	if (xcur < a && ycur == b) {
		return 1;
	}
	if (xcur > a && ycur < b) {
		return c23[ind];
	}
	if (xcur == a && ycur < b){
		return 2;
	}
	return 3;*/
	
	
	return t;
}

void solve(){
	a = 999999999999999917;
	b = 69;
	
	x.pb(1ll);
	y.pb(1ll);
	c12.pb(1ll);
	c13.pb(1ll);
	c23.pb(2ll);
	
	x.pb(1000000000000000000);
	y.pb(1000000000000000000);
	c12.pb(2ll);
	c13.pb(3ll);
	c23.pb(3ll);
	
	ll n;
	scanf("%lld", &n);
	ll xl = 1, xm = n, xr = n, yl = 1, ym = n, yr = n;
	while(xm > xl || ym > yl){
		ll xcur = (xm + xl) / 2;
		ll ycur = (ym + yl) / 2;
		if ((long double)(yr - ym) * (long double)(xm - xl + 1) 
			> (long double)(ym - yl + 1) * (long double)(xm - xl + 1)
			+ (long double)(ym - yl + 1) * (long double)(xr - xm)){
			ycur = ym;
		} else if ((long double)(xr - xm) * (long double)(ym - yl + 1) 
			> (long double)(xm - xl + 1) * (long double)(ym - yl + 1)
			+ (long double)(xm - xl + 1) * (long double)(yr - ym)){
			xcur = xm;
		} 
		printf("%lld %lld\n", xcur, ycur);
		fflush(stdout);
		int t = get_response(xcur, ycur);
		//printf("%lld %lld %lld %lld %lld %lld\n", xl, xm, xr, yl, ym, yr);
		//printf("1 %d\n", t);
		if (t == 0){
			return;
		}
		
		if (t == 1) {
			xl = xcur + 1;
		} else if (t == 2) {
			yl = ycur + 1;
		} else {
			xm = xcur - 1;
			ym = ycur - 1;
		}
			
		if (xm < xl) {
			xm = xr;
			yr = ym;
		} else if (ym < yl) {
			ym = yr;
			xr = xm;
		}
	}
	
	
	
	while(xl < xr) {
		ll xcur = (xl + xr) / 2;
		ll ycur = yl;
		
		printf("%lld %lld\n", xcur, ycur);
		fflush(stdout);
		int t = get_response(xcur, ycur);
		//printf("%lld %lld %lld %lld %lld %lld\n", xl, xm, xr, yl, ym, yr);
		//printf("2 %d\n", t);
		if (t == 0){
			return;
		}
		
		if (t == 1) {
			xl = xcur + 1;
			yr = yl;
		} else if (t == 2) {
			yl = ycur + 1;
			xr = xl;
		} else if (t == 3) {
			xr = xcur - 1;
		}
	}
	
	while(yl < yr) {
		ll xcur = xl;
		ll ycur = (yl + yr) / 2;
		
		printf("%lld %lld\n", xcur, ycur);
		fflush(stdout);
		int t = get_response(xcur, ycur);
		//printf("3 %d\n", t);
		if (t == 0){
			return;
		}
		
		if (t == 1) {
			assert(false);
		} else if (t == 2) {
			yl = ycur + 1;
		} else if (t == 3) {
			yr = ycur - 1;
		}
	}
	
	printf("%lld %lld\n", xl, yl);
	fflush(stdout);
	int t = get_response(xl, yl);
	//printf("%d\n", t);
	if (t == 0){
		return;
	}
}   

int main(){

    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}