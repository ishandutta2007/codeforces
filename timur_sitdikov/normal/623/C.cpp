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

#define REP(i, a, b) for((i) = (a); (i) < (int)(b); (i)++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll INF = 1e18;
const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;

ll mnypref[MAXN], mxypref[MAXN], mnysuf[MAXN], mxysuf[MAXN];
pair<ll, ll> pp[MAXN];

ll x[2], y[2];

int n;

ll get_ans(){
	ll ans = (x[1] - x[0]) * (x[1] - x[0]);
	ans = max(ans, (y[1] - y[0]) * (y[1] - y[0]));
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			ans = max(ans, x[i] * x[i] + y[j] * y[j]);
		}
	}
	return ans;
}

ll my_sqrt(ll v){
	ll ans = (ll)sqrt(v + 0.5);
	for(; ans * ans <= v; ans++);
	ans--;
	return ans;
}

int check(ll val){
	int i, j;
	ll lim = my_sqrt(val);
	for(i = 0, j = 0; i < n; i++){
		for(; j < n && pp[j].first <= pp[i].first + lim; j++);
		if (i == 0 && j == n){
			return 1;
		}
		x[0] = pp[i].first;
		x[1] = pp[j - 1].first;
		if (i > 0){
			y[0] = mnypref[i - 1];
			y[1] = mxypref[i - 1];
			if (j < n){
				y[0] = min(y[0], mnysuf[j]);
				y[1] = max(y[1], mxysuf[j]);
			}
		} else {
			y[0] = mnysuf[j];
			y[1] = mxysuf[j];
		}
		ll tmp = get_ans();
		if (tmp <= val){
			/*if (val == 1){
				cout << i << " " << j << " " << y[0] << " " << y[1] << endl;
			}*/
			return 1;
		}
	}
	return 0;
}

void solve(){
	int i, x0, y0;
	ll l, r, mid;
	scanf("%d", &n);
	REP(i, 0, n){
		scanf("%d%d", &x0, &y0);
		pp[i] = mp((ll)x0, (ll)y0);
	}
	ll ans = INF;
	for(int k = 0; k < 4; k++){
		sort(pp, pp + n);
		mnypref[0] = mxypref[0] = pp[0].second;
		REP(i, 1, n){
			ll cury = pp[i].second;
			mnypref[i] = min(mnypref[i - 1], cury);
			mxypref[i] = max(mxypref[i - 1], cury);
		}
		mnysuf[n - 1] = mxysuf[n - 1] = pp[n - 1].second;
		for(i = n - 2; i >= 0; i--){
			ll cury = pp[i].second;
			mnysuf[i] = min(mnysuf[i + 1], cury);
			mxysuf[i] = max(mxysuf[i + 1], cury);
		}
		ans = min(ans, (pp[n - 1].first - pp[0].first) * (pp[n - 1].first - pp[0].first));
		ll tmpy1, tmpy2;
		/*tmpy1 = tmpy2 = pp[0].second;
		for(i = 1; i < n; i++){
			tmpy1 = min(tmpy1, pp[i].second);
			tmpy2 = max(tmpy2, pp[i].second);
		}*/
		tmpy1 = mnypref[n - 1], tmpy2 = mxypref[n - 1];
		ans = min(ans, (tmpy2 - tmpy1) * (tmpy2 - tmpy1));
		//cout << ans << endl;
		if (check(0ll)){
			ans = 0ll;
		}
		for(l = 0ll, r = INF; l + 1 < r; ){
			mid = (l + r) >> 1;
			if (check(mid)){
				r = mid;
			} else {
				l = mid;
			}
		}
		ans = min(ans, r);
		if (k == 1){
			REP(i, 0, n){
				swap(pp[i].first, pp[i].second);
			}
		} else {
			REP(i, 0, n){
				pp[i].first *= -1ll;
			}
		}
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