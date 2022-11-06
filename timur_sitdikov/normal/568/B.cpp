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
const int MAXN = 4e3 + 5;
const ll MOD = 1e9 + 7;

ll dp[2][MAXN], c[2][MAXN], v[2][MAXN], b[MAXN];

void solve(){
    int i, j, ind, n;
    cin >> n;
    c[0][0] = 1;
    dp[0][0] = 1;
    v[0][0] = 1;
    b[0] = 1;
    for(i = 1; i <= n; i++){
        ind = i & 1;
        for(j = 0; j <= n; j++){
            dp[ind][j] = v[ind][j] = 0;
        }
        c[ind][0] = 1;
        for(j = 1; j <= i; j++){
            c[ind][j] = (c[ind ^ 1][j - 1] + c[ind ^ 1][j]) % MOD;
            //printf("%lld ", c[ind][j]);
        }
        v[ind][0] = 0;
        for(j = 1; j <= i; j++){
            v[ind][j] = (v[ind ^ 1][j - 1] + v[ind ^ 1][j] * j) % MOD;
            //printf("%lld ", v[ind][j]);
            b[i] = (b[i] + v[ind][j]) % MOD;
        }
        for(j = 0; j <= i; j++){
            dp[ind][j] = (c[ind][j] * b[i - j]) % MOD;
        }
        //putchar('\n');
    }
    ll ans = 0ll;
    ind = n & 1;
    for(i = 1; i <= n; i++){
        ans = (ans + dp[ind][i]) % MOD;
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