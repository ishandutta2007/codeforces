#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<long double> point;
#define xx real()
#define yy imag()

#define REP(i, a, b) for(int i = (a); i < (int)(b); i++)
#define REPN(i, a, b) for(int i = (a); i <= (int)(b); i++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const long double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;

long double p[MAXN], sump[MAXN], q[MAXN], sumq[MAXN], mn[MAXN], mx[MAXN];

void solve(){
	int n;
	scanf("%d", &n);
	REPN(i, 1, n){
		double tmp;
		scanf("%lf", &tmp);
		mx[i] = tmp;
	}
	REPN(i, 1, n){
		double tmp;
		scanf("%lf", &tmp);
		mn[i] = tmp;
	}
	REPN(i, 1, n){
		long double b = -sumq[i - 1]  - mx[i] - mn[i] + sump[i - 1];
		long double c = mx[i] - sump[i - 1] * mx[i] - sump[i - 1] * mn[i];
		long double d = b * b - 4. * c;		
		if (fabs(d) < EPS){
			d = 0.;
		}
		assert(d >= 0.);
		p[i] = (-b + sqrt(d)) / 2.;
		q[i] = mx[i] + mn[i] - p[i];
		if (p[i] < -EPS || p[i] > 1. + EPS || q[i] < -EPS || q[i] > 1. + EPS){
			p[i] = (-b - sqrt(d)) / 2.;
			q[i] = mx[i] + mn[i] - p[i];
			if (p[i] < -EPS || p[i] > 1. + EPS || q[i] < -EPS || q[i] > 1. + EPS){
				assert(false);
			}
		}
		sump[i] = sump[i - 1] + p[i];
		sumq[i] = sumq[i - 1] + q[i];
		/*printf("%d %lf %lf %lf %lf %lf %lf %lf\n", i, b, c, d, p[i], q[i], sump[i], sumq[i]);
		return;*/
	}
	REPN(i, 1, n){
		printf("%.12lf ", (double)p[i]);
	}
	putchar('\n');
	REPN(i, 1, n){
		printf("%.12lf ", (double)q[i]);
	}
	putchar('\n');
}	

int main(){
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();	
	}
}