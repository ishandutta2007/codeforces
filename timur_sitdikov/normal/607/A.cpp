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
const int INF = 1e9;
const int MAXN = 1e6 + 5;
const ll MOD = 1e9 + 7;

int dp[MAXN], dp_last[MAXN], v[MAXN];

void solve(){
    int n, i, ans = 0, a, b;
    scanf("%d", &n);
    REP(i, 0, n){
        scanf("%d%d", &a, &b);
        a++;
        v[a] = b;
    }
    int last = 0;
    REP(i, 1, MAXN){
        int tmp = i - v[i] - 1;
        if (tmp < 0){
            tmp = 0;
        }
        dp[i] = dp_last[tmp];
        if (v[i]){
            dp[i]++;
            last = dp[i];
        }
        //dp_max[i] = max(dp_max[i - 1], dp[i]);
        dp_last[i] = last;
        ans = max(ans, dp[i]);
    }
    /*REP(i, 0, 20){
        printf("%d %d\n", i, dp[i]);
    }*/
    printf("%d\n", n - ans);
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