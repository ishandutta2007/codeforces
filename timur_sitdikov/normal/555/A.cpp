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

void solve(){
    int n, m, i, j, l, fl, a, last, cnt;
    scanf("%d%d", &n, &m);
    REP(i, 0, m){
        scanf("%d%d", &cnt, &a);
        fl = 0;
        if (a == 1){
            fl = 1;
            l = 1;
        }
        for(j = 1; j < cnt; j++){
            scanf("%d", &a);
            //printf("%d %d\n", a, l);
            if (fl && a == l + 1){
                l++;
            }
        }
    }
    //printf("%d %d %d\n", n, m, l);
    int ans = 2 * n - 2 * l + 1 - m;
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