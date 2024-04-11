#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<ll> point;
#define xx real()
#define yy imag()

#define REP(i, a, b) for((i) = (a); (i) < (int)(b); (i)++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;

ll abs2(const point &a){
	return a.xx * a.xx + a.yy * a.yy;
}

ll cross(const point &o, const point &a, const point &b){
	return imag(conj(a - o) * (b - o));
}

point pt[MAXN];

void solve(){
	int n, i, a, b, c, x, y;
	scanf("%d", &n);
	REP(i, 0, n){
		scanf("%d%d", &x, &y);
		pt[i] = point((ll)x, (ll)y);
	}
	a = 0;
	b = 1;
	REP(i, 1, n){
		if (abs2(pt[a] - pt[i]) < abs2(pt[a] - pt[b])){
			b = i;
		}
	}
	c = -1;
	// cout << b << " " << c << endl;
	REP(i, 1, n){
		if ((c == -1 || abs2(pt[a] - pt[i]) < abs2(pt[a] - pt[c])) && cross(pt[a], pt[b], pt[i]) != 0){
			c = i;
		}
	}
	printf("%d %d %d\n", a + 1, b + 1, c + 1);
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