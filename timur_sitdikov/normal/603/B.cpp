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

int used[MAXN];

ll pow_mod(ll v, ll st){
    ll ans = 1ll, a = v;
    for(; st; st /= 2){
        if (st % 2){
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
    }
    return ans;
}

void solve(){
    int l;
    ll k, k1, p, ans;
    cin >> p >> k;
    if (k == 0){
        l = 1;
    } else {
        for(k1 = k, l = 1; k1 != 1; k1 = (k1 * k) % p, l++);    
    }
    ans = pow_mod((ll)p, (ll)(p - 1) / l);
    if (k == 1){
        ans = (ans * p) % MOD;
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