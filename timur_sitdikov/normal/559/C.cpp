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
const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;

pii pp[MAXN];

ll pow_mod(ll v, ll st){
    ll a = v, ans = 1ll;
    for(; st; st /= 2){
        if (st & 1){
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
    }
    return ans;
}

ll get_obr(ll v){
    return pow_mod(v, MOD - 2ll);
}

ll f[MAXN], f_obr[MAXN], dp[MAXN];

ll get_c(int i, int j){
    if (j > i || i < 0 || j < 0){
        return 0ll;
    }
    ll ans = (f[i] * f_obr[j]) % MOD;
    ans = (ans * f_obr[i - j]) % MOD;
    return ans;
}

void solve(){
    int i, j, h, w, m, n;
    scanf("%d%d%d", &h, &w, &n);
    m = h + w;
    f[0] = f_obr[0] = 1ll;
    REP(i, 1, m + 1){
        f[i] = (f[i - 1] * i) % MOD;
        f_obr[i] = (f_obr[i - 1] * get_obr(i)) % MOD;
    }
    REP(i, 1, n + 1){
        scanf("%d%d", &pp[i].first, &pp[i].second);
        pp[i].first--;
        pp[i].second--;
    }
    /*printf("#\n");
    return;*/
    sort(pp + 1, pp + n + 1);
    pp[n + 1] = mp(h - 1, w - 1);
    dp[0] = 1ll;
    /*printf("2\n");
    return;*/
    REP(i, 1, n + 2){
        dp[i] = get_c(pp[i].first + pp[i].second, pp[i].second);
        REP(j, 1, i){
            dp[i] = (dp[i] - dp[j] 
                * get_c(pp[i].first + pp[i].second - pp[j].first - pp[j].second, pp[i].first - pp[j].first)) % MOD;
            if (dp[i] < 0ll){
                dp[i] += MOD;
            }
        }
    }
    cout << dp[n + 1] << endl;
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