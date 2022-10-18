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
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
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

    int n, l, r;
    cin >> n >> l >> r;

    vector<ll> cnt(3);
    cnt[0] = max(0, (r / 3 * 3 - (l + 2) / 3 * 3) / 3 + 1);
    cnt[1] = cnt[0] - 1 + (l % 3 == 1) + (r % 3 >= 1);
    cnt[2] = r - l + 1 - cnt[0] - cnt[1];
//    printv(cnt, cerr);

    vector<vector<ll>> dp(3, vector<ll>(n + 1));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
//                cerr << i << " " << j << " " << k << " " << dp[j][i - 1] << " " << cnt[k] << "\n";
                dp[(j + k) % 3][i] += dp[j][i - 1] * cnt[k] % MOD;
                dp[(j + k) % 3][i] %= MOD;
            }
        }
    }
//    printv(dp[0], cerr);
//    printv(dp[1], cerr);
//    printv(dp[2], cerr);
    cout << dp[0][n] << "\n";

    return 0;
}