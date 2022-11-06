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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;

point pt[MAXN], s1, s2, f;

pair<double, int> p1[MAXN], p2[MAXN];

void read_point(point &a){
	double x, y;
	scanf("%lf%lf", &x, &y);
	a = point(x, y);
}

void solve(){
	int n;
	read_point(s1);
	read_point(s2);
	read_point(f);
	scanf("%d", &n);
	double sum = 0.;
	REP(i, 0, n){
		read_point(pt[i]);
		p1[i] = mp(abs(pt[i] - s1) - abs(pt[i] - f), i);
		p2[i] = mp(abs(pt[i] - s2) - abs(pt[i] - f), i);
		sum += 2. * abs(pt[i] - f);
	}
	sort(p1, p1 + n);
	sort(p2, p2 + n);
	double ans = sum + p1[0]._1;
	ans = min(ans, sum + p2[0]._1);
	if (n > 1){
		if (p1[0]._2 == p2[0]._2){
			ans = min(ans, sum + p1[1]._1 + p2[0]._1);
			ans = min(ans, sum + p1[0]._1 + p2[1]._1);
		} else {
			ans = min(ans, sum + p1[0]._1 + p2[0]._1);
		}
	}
	printf("%.12lf\n", ans);
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