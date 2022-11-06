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
const int MAXN = 1e2 + 5;
const ll MOD = 1e9 + 7;

int v[MAXN][MAXN];
char c[MAXN][MAXN];

void solve(){
    int i, j, k, n, m, l;
    scanf("%d%d", &n, &m);
    REP(i, 0, n){
        scanf("%s", &c[i][0]);
        REP(j, 0, m){
            v[i][j] = (c[i][j] == 'W'? 1: -1);
        }
    }
    int ans = 0;
    for(i = n - 1; i >= 0; i--){
        for(j = m - 1; j >= 0; j--){
            if (v[i][j]){
                ans++;
                for(k = 0; k <= i; k++){
                    for(l = 0; l <= j; l++){
                        v[k][l] -= v[i][j];
                    }
                }
            }
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