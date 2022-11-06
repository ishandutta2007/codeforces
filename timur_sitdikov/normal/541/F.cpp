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

vector<int> v[MAXN];

void solve(){
    int n, i, j, q, t, lim;
    cin >> n >> lim;
    for(i = 0; i < n; i++){
        cin >> t >> q;
        v[lim - t].pb(q);
    }
    for(i = 0; i < lim; i++){
        SORT(v[i]);
        reverse(BE(v[i]));
    }
    /*printf("#\n");
    return;*/
    for(i = lim - 1; i >= 0; i--){
        vi cur;
        int i1, i2;
        /*printf("#\n");
        return;*/
        /*printf("%d %d\n", (int)v[i].size(), (int)v[i + 1].size());
        return;*/
        for(i1 = i2 = 0; i1 < (int)v[i].size() || i2 < (int)v[i + 1].size(); ){
            int v1 = 0, v2 = 0, offset1 = 0, offset2 = 0;
            /*printf("%d %d\n", i1, i2);
            return;*/
            if (i1 < SZ(v[i])){
                v1 = v[i][i1];
                offset1 = 1;
            }
            if (i2 < SZ(v[i + 1])){
                if (i2 == SZ(v[i + 1]) - 1){
                    v2 = v[i + 1][i2];
                    offset2 = 1;
                } else {
                    v2 = v[i + 1][i2] + v[i + 1][i2 + 1];
                    offset2 = 2;
                }
            }
            /*printf("%d %d\n", i1, i2);
            return;*/
            /*if (offset1 == 0 && offset2 == 0){
                printf("#\n");
                return;
            }*/
            if (v1 > v2){
                cur.pb(v1);
                i1 += offset1;
            } else {
                cur.pb(v2);
                i2 += offset2;
            }
        }
        v[i] = cur;
    }
    if (v[0].empty()){
        v[0].pb(0);
    }
    printf("%d\n", v[0][0]);
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