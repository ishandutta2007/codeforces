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
const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;

int cnt[MAXN], sum[MAXN], last[MAXN];

void solve(){
    int n, a, i, j, k, tmp, tmp1;
    scanf("%d", &n);
    REP(i, 1, n + 1){
        scanf("%d", &a);
        for(j = 0, tmp = a; tmp; tmp >>= 1, j++){
            for(k = 0, tmp1 = tmp; tmp1 < MAXN; tmp1 <<= 1, k++){
                if (last[tmp1] != i){
                    last[tmp1] = i;
                    cnt[tmp1]++;
                    sum[tmp1] += j + k;
                }
            }
        }
    }
    int ans = INF;
    REP(i, 1, MAXN){
        if (cnt[i] == n){
            ans = min(ans, sum[i]);
        }
    }
    printf("%d\n", ans);
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