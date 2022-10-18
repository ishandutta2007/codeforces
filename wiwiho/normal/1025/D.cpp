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

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n)));
    vector<vector<bool>> dp0(n, vector<bool>(n)), dp1(n, vector<bool>(n));

    for(int i = 0; i < n; i++){
        dp[i][i][i] = dp0[i][i] = dp1[i][i] = true;
    }

    vector<vector<int>> gcd(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) gcd[i][j] = __gcd(a[i], a[j]);
    }

    for(int len = 1; len < n; len++){
        for(int l = 0; l + len < n; l++){
            int r = l + len;

            for(int i = l + 1; i <= r; i++){
                if(!dp[l + 1][r][i]) continue;
                if(gcd[l][i] > 1) dp0[l][r] = true;
            }
            for(int i = l; i <= r - 1; i++){
                if(!dp[l][r - 1][i]) continue;
                if(gcd[r][i] > 1) dp1[l][r] = true;
            }

            for(int i = l; i <= r; i++){
                if(!dp1[l][i] || !dp0[i][r]) continue;
                dp[l][r][i] = true;
            }

        }
    }

    bool ans = false;
    for(bool i : dp[0][n - 1]) ans = ans || i;

    if(ans) cout << "YES\n";
    else cout << "NO\n";


    return 0;
}