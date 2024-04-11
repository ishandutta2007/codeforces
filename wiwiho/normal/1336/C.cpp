//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a) / (b) + !!((a) % (b)))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using namespace __gnu_pbds;

const ll MOD = 998244353;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

int main(){
    StarBurstStream

    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    vector<vector<ll>> dp(n, vector<ll>(n));

    for(int i = 0; i < n; i++){
        if(i >= m || s[0] == t[i]) dp[0][i] = 2;
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j + i < n; j++){
            if(j >= m || s[i] == t[j]) dp[i][j] += dp[i - 1][j + 1];
            if(j + i >= m || s[i] == t[j + i]) dp[i][j] += dp[i - 1][j];
            dp[i][j] %= MOD;
        }
    }
//    for(int i = 0; i < n; i++){
//        printv(dp[i], cerr);
//    }

    ll ans = 0;
    for(int i = m - 1; i < n; i++) ans += dp[i][0], ans %= MOD;
    cout << ans << "\n";

    return 0;
}