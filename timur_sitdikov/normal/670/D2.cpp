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

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;

int a[MAXN], b[MAXN];

void solve(){
	int n, k;
	scanf("%d%d", &n, &k);
	REP(i, 0, n){
		scanf("%d", &a[i]);
	}
	REP(i, 0, n){
		scanf("%d", &b[i]);
	}
	ll l = 0, r = 2e9 + 10;
	while(l + 1ll < r){
		ll mid = (l + r) / 2ll;
		ll cur_k = k;
		REP(i, 0, n){
			ll dif = max(0ll, (ll)a[i] * mid - (ll)b[i]);
			cur_k -= dif;
			if (cur_k < 0ll){
				break;
			}
		}
		// cout << mid << " " << cur_k << endl;
		if (cur_k < 0ll){
			r = mid;
		} else {
			l = mid;
		}
	}
	cout << l << endl;
}	

int main(){
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();	
	}
}