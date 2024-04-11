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

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;

int dp[MAXN][3];
int a[MAXN];

void solve(){
	int n, ans = 0;
	cin >> n;
	REPN(i, 1, n){
		cin >> a[i];
		REP(j, 0, 3){
			if (j && !(a[i] & j)){
				dp[i][j] = 0;
				continue;
			}
			REP(k, 0, 3){
				if (k == j && k != 0){
					continue;
				}
				dp[i][j] = max(dp[i][j], dp[i - 1][k] + (j ? 1 : 0));	
				ans = max(ans, dp[i][j]);
			}
			//cout << i << " " << j<< " " << dp[i][j] << endl;
		}
	}	
	cout << n - ans << endl;
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