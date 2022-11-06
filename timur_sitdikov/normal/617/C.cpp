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

const long double EPS = 1e-14;
const long double PI = acos(-1.);
const ll INF = 1e18;
const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;

point pt[MAXN], pt0[2];

ll abs2(const point &a){
	return a.xx * a.xx + a.yy * a.yy;
}

void solve(){
	int i, j, n;
	ll x, y;
	cin >> n;
	REP(i, 0, 2){
		cin >> x >> y;
		pt0[i] = point(x, y);
	}
	REP(i, 0, n){
		cin >> x >> y;
		pt[i] = point(x, y);
	}
	pt[n++] = pt0[0];
	pt[n++] = pt0[1];
	ll ans = INF;
	REP(i, 0, n){
		ll cur = abs2(pt0[0] - pt[i]);
		ll mx = 0ll;
		REP(j, 0, n){
			ll tmp = abs2(pt0[0] - pt[j]);
			if (tmp > cur){
				mx = max(mx, abs2(pt0[1] - pt[j]));
			}
		}
		ans = min(ans, cur + mx);
	}
	cout << ans << endl;
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