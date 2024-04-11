//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define ef(a) emplace_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
#define tomin(a, b) ((a) = min((a), (b)))
#define topos(a) (((a) % MOD + MOD) % MOD)
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

//#define TEST

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tiii = tuple<int, int, int>;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

int main(){
    StarBurstStream

    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> dp(k, -MAX);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        vector<vector<ll>> dp2(m / 2 + 1, vector<ll>(k, -MAX));
        dp2[0][0] = 0;
        for(int j = 0; j < m; j++){
            int a;
            cin >> a;
            vector<vector<ll>> tdp2 = dp2;
            for(int ii = 0; ii < m / 2; ii++){
                for(int jj = 0; jj < k; jj++){
                    tdp2[ii + 1][(jj + a) % k] = max(tdp2[ii + 1][(jj + a) % k], dp2[ii][jj] + a);
                }
            }
            dp2 = tdp2;
        }
//        cerr << i << "\n";
//        for(int j = 0; j <= m / 2; j++) printv(dp2[j], cerr);
        vector<ll> tdp = dp;
        for(int j = 0; j < k; j++){
            ll mx = -MAX;
            for(int jj = 0; jj <= m / 2; jj++) mx = max(mx, dp2[jj][j]);
            for(int ii = 0; ii < k; ii++){
                tdp[(ii + j) % k] = max(tdp[(ii + j) % k], dp[ii] + mx);
            }
        }
        dp = tdp;
//        printv(dp, cerr);
    }

    cout << dp[0] << "\n";

    return 0;
}