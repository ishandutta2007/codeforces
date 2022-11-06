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
    ll a[3], ans, l, i, j, lim;
    cin >> a[0] >> a[1] >> a[2] >> l;
    ans = 0;
    for(i = 0; i <= l; i++){
        ans += (i + 1) * (i + 2) / 2;
    }
    //cout << ans << endl;
    for(i = 0; i <= l; i++){
        for(j = 0; j < 3; j++){
            lim = -(a[(j + 1) % 3] + a[(j + 2) % 3] - a[j] - i);
            lim = min(lim, l - i);
            //cout << "#" << lim << endl;
            if (lim >= 0){
                ans -= (lim + 1) * (lim + 2) / 2;
            }
        }
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