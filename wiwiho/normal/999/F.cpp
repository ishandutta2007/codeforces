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

    int n, k;
    cin >> n >> k;

    vector<int> cnt(100001);
    vector<int> fcnt(100001);

    for(int i = 0; i < n * k; i++){
        int c;
        cin >> c;
        cnt[c]++;
    }

    for(int i = 0; i < n; i++){
        int f;
        cin >> f;
        fcnt[f]++;
    }

    vector<int> h(k + 1);
    for(int i = 1; i <= k; i++) cin >> h[i];

    ll ans = 0;
    for(int i = 1; i <= 100000; i++){
        vector<ll> dp(cnt[i] + 1);
        for(int j = 0; j < fcnt[i]; j++){
            vector<ll> dp2 = dp;
            for(int l = 1; l <= k; l++){
                for(int m = l; m <= cnt[i]; m++){
                    dp2[m] = max(dp2[m], dp[m - l] + h[l]);
                }
            }
            dp = dp2;
        }
        ans += dp[cnt[i]];
    }

    cout << ans << "\n";

    return 0;
}