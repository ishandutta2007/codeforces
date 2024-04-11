#include <bits/stdc++.h>
using namespace std;

#define point complex<double>
#define xx real()
#define yy imag()

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
const int MAXN = 1e5 + 5, MAXLOG = 18;
const ll MOD = 1e9 + 7;

ll cross(const point &o, const point &a, const point &b){
	return imag(conj(a - o) * (b - o));
}

ll dot(const point &o, const point &a, const point &b){
	return real(conj(a - o) * (b - o));
}

point pt[MAXN], pt0;

void solve(){
	int n, i, x0, y0, x, y;
	ll r1, r2;
	scanf("%d%d%d%d%d", &n, &x0, &y0, &x, &y);
	pt0 = point((ll)x0, (ll)y0);
	pt[0] = point((ll)x, (ll)y);
	r2 = r1 = (ll)(x - x0) * (ll)(x - x0) + (ll)(y - y0) * (ll)(y - y0);
	REP(i, 1, n){
		scanf("%d%d", &x, &y);
		pt[i] = point((ll)x, (ll)y);
		ll tmp = (ll)(x - x0) * (ll)(x - x0) + (ll)(y - y0) * (ll)(y - y0);
		r1 = min(r1, tmp);
		r2 = max(r2, tmp);
	}
	double r = sqrt(r1 + 0.);
	REP(i, 0, n){
		if (dot(pt[i], pt0, pt[(i + 1) % n]) >= 0 && dot(pt[(i + 1) % n], pt0, pt[i]) >= 0){
			r = min(r, fabs(cross(pt0, pt[i], pt[(i + 1) % n])) / abs(pt[i] - pt[(i + 1) % n]));
			// cout << r << endl;
		}
	}
	double ans = PI * (r2 - r * r);
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