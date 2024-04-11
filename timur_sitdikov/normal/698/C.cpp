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
const int MAXN = 21;
const ll MOD = 1e9 + 7;

double dp[1 << MAXN], p[MAXN], ans[MAXN];

void solve(){
	int n, k;
	scanf("%d%d", &n, &k);
	int real_k = 0;
	REP(i, 0, n){
		scanf("%lf", &p[i]);
		dp[1 << i] = p[i];
		if (p[i] > EPS){
			real_k++;
		}
		//cout << p[i] << " " << i << " " << (1 << i) << " " << dp[1 << i] << endl;
	}
	real_k = min(real_k, k);
	REP(i, 0, 1 << n){
		int bit_cnt = 0;
		double pp = 0.;
		REP(j, 0, n){
			if (i & (1 << j)){
				bit_cnt++;
			} else {
				pp += p[j];
			}
		}
		if (pp > EPS){
			REP(j, 0, n){
				if (!(i & (1 << j))){
					dp[i | (1 << j)] += dp[i] * p[j] / pp;
				}
			}
		}
		if (bit_cnt == real_k){
			REP(j, 0, n){
				if (i & (1 << j)){
					//cout << j << " " << i << " " << dp[i] << endl;
					ans[j] += dp[i];
				}
			}
		}
	}
	REP(i, 0, n){
		printf("%.12lf ", ans[i]);
	}
	putchar('\n');
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