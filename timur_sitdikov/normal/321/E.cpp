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
const int MAXN = 4e3 + 5, MAXD = 805;
const ll MOD = 1e9 + 7;

char v[MAXN][MAXN];
int sum[MAXN][MAXN], sum1[MAXN][MAXN];
int dp[MAXD][MAXN], prv[MAXD][MAXN];

void calc(int i, int j, int prvl, int prvr){
    int k, tmp;
    dp[i][j] = dp[i - 1][prvl] + sum[prvl + 1][j];
    prv[i][j] = prvl;
    for(k = prvl + 1; k <= prvr; k++){
        tmp = dp[i - 1][k] + sum[k + 1][j];
        if (tmp < dp[i][j]){
            dp[i][j] = tmp;
            prv[i][j] = k;
        }
    }
}

void rec_sol(int i, int l, int r, int prvl, int prvr){
    if (l > r){
        return;
    }
    int mid = (l + r) >> 1, prvm;
    calc(i, mid, prvl, prvr);
    prvm = prv[i][mid];
    rec_sol(i, l, mid - 1, prvl, prvm);
    rec_sol(i, mid + 1, r, prvm, prvr);
}

void solve(){
    int n, m, i, j, a;
    scanf("%d%d", &n, &m);
    REP(i, 0, n){
        REP(j, 0, n){
            while(v[i][j] = getchar(), v[i][j] < '0' || v[i][j] > '9');
            v[i][j] -= '0';
            sum1[i][j] = v[i][j];
            if (j){
                sum1[i][j] += sum1[i][j - 1];
            }
        }
    }
    REP(i, 0, n){
        sum[i][i] = 0;
        REP(j, i + 1, n){
            sum[i][j] = sum[i][j - 1] + sum1[j][j];
            if (i){
                sum[i][j] -= sum1[j][i - 1];
            }
        }
        dp[1][i] = sum[0][i];
    }
    for(i = 2; i <= m; i++){
        rec_sol(i, 0, n - 1, 0, n - 1);
    }
    printf("%d\n", dp[m][n - 1]);
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