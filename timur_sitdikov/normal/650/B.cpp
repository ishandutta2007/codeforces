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
const ll INF = 1e12;
const int MAXN = 1e6 + 5;
const ll MOD = 1e9 + 7;

ll dpl[MAXN], dpr[MAXN];

char s[MAXN];

void solve(){
	int n, i, j, k;
	ll t, a, b;
	cin >> n >> a >> b >> t;
	scanf("%s", &s[0]);
	int ans = 0;
	REP(k, 0, 2){
		// reverse(s + 1, s + n);
		dpl[0] = 1;
		if (s[0] == 'w'){
			dpl[0] += b;
		}		
		REP(i, 1, n){
			dpl[i] = dpl[i - 1] + a + 1;
			if (s[i] == 'w'){
				dpl[i] += b;
			}
			dpr[i] = dpr[i - 1] + a + 1;
			if (s[n - i] == 'w'){
				dpr[i] += b;
			}
		}
		/*REP(i, 0, n){
			cout << i << " " << dpl[i] << " " << dpr[i] << endl;
		}*/
		dpr[n] = INF;
		REP(i, 0, n){
			if (dpl[i] <= t){
				ans = max(ans, i + 1);
				ll t1 = dpl[i] + a * i;
				//cout << "# " << i << " " << i + 1 << " " << t1 << endl;
				if (t1 <= t){
					int ind2 = upper_bound(dpr + 1, dpr + n, t - t1) - (dpr + 1);
					ans = max(ans, i + 1 + ind2);
					ans = min(ans, n);
					//cout << "# " << ind2 << endl;
				}
			}
		}
		reverse(s + 1, s + n);
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