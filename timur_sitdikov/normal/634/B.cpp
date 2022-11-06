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

void solve(){
	ll s, x;
	int i;
	cin >> s >> x;
	int cnt = 0;
	for(i = 0; (1ll << i) <= x; i++){
		if (x & (1ll << i)){
			cnt++;
			s -= (1ll << i);
		}
	}
	if (s < 0 || s % 2 == 1){
		cout << 0 << endl;
		return;
	}
	ll a = s / 2ll;
	for(i = 0; (1ll << i) <= a; i++){
		if ((a & (1ll << i)) && (x & (1ll << i))){
			/*cout << i << endl;
			cout << (1ll << i) << endl;*/
			cout << 0 << endl;
			return;
		}
	}
	ll ans = (1ll << cnt);
	if (a == 0){
		ans -= 2ll;
		ans = max(ans, 0ll);
	}
	cout << ans << endl;
}	

int main(){
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();	
	}
}