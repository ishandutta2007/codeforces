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
const int MAXN = 2e5 + 105;
const ll MOD = 1e9 + 7;

ll coefs0[MAXN], coefs[MAXN];
int n;
ll lim;

int correct_coefs(){
	int i;
	REP(i, 0, MAXN){
		coefs[i] = coefs0[i];
	}
	REP(i, 0, MAXN - 1){
		if (coefs[i] < 0ll && coefs[i] % 2ll != 0ll){
			coefs[i + 1] += (coefs[i] - 1ll) / 2ll;
			coefs[i] = 1ll;
		} else {
			coefs[i + 1] += coefs[i] / 2ll;
			coefs[i] %= 2ll;
		}		
	}
}

void solve(){
	int i, j, tmp, last;
	cin >> n >> lim;
	REP(i, 0, n + 1){
		scanf("%d", &tmp);
		coefs0[i] = tmp;
	}
	correct_coefs();
	for(last = MAXN - 1; last >= 0; last--){
		if (coefs[last]){
			break;
		}
	}
	assert(last >= 0);
	if (coefs[last] < 0){
		REP(i, 0, MAXN){
			coefs0[i] = -coefs0[i];
		}
		correct_coefs();
	}
	for(last = MAXN - 1; last >= 0; last--){
		if (coefs[last]){
			break;
		}
	}
	int ans = 0;
	for(i = 0; ; i++){
		if (i + 32 >= last){
			ll val = 0ll;
			for(j = last; j >= i; j--){
				val = val * 2ll + coefs[j];
			}
			if (coefs[i]){
				val--;
			}
			val = -val;
			// cout << i << " " << val << endl;
			if (i <= n && abs(val - coefs[i] + coefs0[i]) <= lim){
				// cout << i << endl;
				if (!(i == n && abs(val - coefs[i] + coefs0[i]) == 0)){
					ans++;
				}
			}
		}				
		if (coefs[i]){
			break;
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