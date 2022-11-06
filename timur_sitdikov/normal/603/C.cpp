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
const int MAXN = 1e3 + 5;
const ll MOD = 1e9 + 7;
const int MAXD = 5;

int dp[MAXN];

int used[MAXD];
int ans2[16] = {2, 0, 1, 0, 1, 0, 1, 0, 2, 0, 1, 0, 2, 0, 1, 0}; 

int get(int v, int k){
    if (k % 2 == 0){
        if (v < 100){
            return dp[v];
        } else {
            return 1 - v % 2;
        }
    } else {
        if (v < 100){
            return dp[v];
        } else {
            if (v % 32){
                return ans2[(v - 100) % 16];
            }
            int tmp1 = get(v - 1, k);
            int tmp2 = get(v / 2, k);
            used[0] = used[1] = used[2] = 0;
            used[tmp1] = 1;
            used[tmp2] = 1;
            int i;
            for(i = 0; used[i]; i++);
            return i;
        }
    }
}

void solve(){
    int n, k, i, j, a;
    scanf("%d%d", &n, &k);
    for(i = 1; i < MAXN; i++){
        for(j = 0; j < MAXD; j++){
            used[j] = 0;
        }
        used[dp[i - 1]] = 1;
        if (i % 2 == 0){
            if (k % 2 == 0){
                used[dp[0]] = 1;
            } else {
                used[dp[i / 2]] = 1;
            }
        }
        for(j = 0; used[j]; j++);
        dp[i] = j;
    }
    /*for(i = 0; i < MAXN; i++){
        if (dp[i] != get(i, k)){
            printf("%d %d\n", i, k);
            if (i % 32){
                printf("**********************\n");
            }
        } else {
            printf(":)\n");
        }
        //printf("%d %d\n", i, dp[i]);
    }*/
    int ans = 0;
    REP(i, 0, n){
        scanf("%d", &a);
        ans ^= get(a, k);
    }
    if (ans){
        printf("Kevin\n");
    } else {
        printf("Nicky\n");
    }
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