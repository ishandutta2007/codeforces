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

vector<pii> ee;
int p[MAXN], used[MAXN];

void solve(){
    int n, i, j, k, cnt, fl;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &p[i]);
        if (p[i] == i){
            printf("YES\n");
            for(j = 1; j <= n; j++){
                if (j != i){
                    printf("%d %d\n", i, j);
                }
            }
            return;
        }
    }
    fl = 0;
    for(i = 1; i <= n; i++){
        if (p[p[i]] == i && !fl){
            fl = 1;
            ee.pb(mp(i, p[i]));
            used[i] = used[p[i]] = 1;
            for(j = 1; j <= n; j++){
                if (!used[j]){
                    cnt = 0;
                    for(k = j; !used[k]; k = p[k], cnt++){
                        used[k] = 1;
                        if (cnt & 1){
                            ee.pb(mp(i, k));
                        } else {
                            ee.pb(mp(p[i], k));
                        }
                    }
                    if (cnt & 1){
                        printf("NO\n");
                        return;
                    }
                }
            }
        }
    }
    if (!fl){
        printf("NO\n");
        return;
    }
    printf("YES\n");
    REP(i, 0, SZ(ee)){
        printf("%d %d\n", ee[i].first, ee[i].second);
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