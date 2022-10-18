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
#define iceil(a, b) ((a + b - 1) / b)
#define tomax(a, b) (a = max(a, b))
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

ll fp(ll a, ll b){
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<vector<int>> dp(4, vector<int>(4));
    dp[0][0] = 1;
    int k = 0;

    string s;
    cin >> s;
    for(int i = 0; i < n; i++){
        if(s[i] == 'a'){
            dp[1][0]++;
        }
        else if(s[i] == 'b'){
            for(int j = 0; j <= 1; j++){
                dp[2][j] += dp[1][j];
                dp[2][j] %= MOD;
            }
        }
        else if(s[i] == 'c'){
            for(int j = 0; j <= 2; j++){
                dp[3][j] += dp[2][j];
                dp[3][j] %= MOD;
            }
        }
        else{
            k++;
            for(int j = 3; j >= 1; j--){
                for(int k = 1; k <= 3; k++){
                    dp[j][k] += dp[j - 1][k - 1];
                    dp[j][k] %= MOD;
                }
            }
        }
    }
//    for(int i = 1; i <= 3; i++) printv(dp[i], cerr);

    ll ans = 0;
    for(int i = 0; i <= 3; i++){
        ans += dp[3][i] * fp(3, k - i) % MOD;
        ans %= MOD;
    }

    cout << ans << "\n";

    return 0;
}