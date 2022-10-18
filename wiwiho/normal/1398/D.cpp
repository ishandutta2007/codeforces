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

    int R, G, B;
    cin >> R >> G >> B;

    vector<int> r(R + 1), g(G + 1), b(B + 1);
    for(int i = 1; i <= R; i++) cin >> r[i];
    for(int i = 1; i <= G; i++) cin >> g[i];
    for(int i = 1; i <= B; i++) cin >> b[i];

    sort(r.begin() + 1, r.end());
    sort(g.begin() + 1, g.end());
    sort(b.begin() + 1, b.end());

    vector<vector<vector<ll>>> dp(R + 1, vector<vector<ll>>(G + 1, vector<ll>(B + 1)));
    ll ans = 0;
    for(int i = 0; i <= R; i++){
        for(int j = 0; j <= G; j++){
            for(int k = 0; k <= B; k++){

                if(i && j){
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + r[i] * g[j]);
//                    cerr << "rg " << dp[i - 1][j - 1][k] << " " << r[i] * g[j] << "\n";
                }
                if(j && k){
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + g[j] * b[k]);
//                    cerr << "gb\n";
                }
                if(i && k){
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + r[i] * b[k]);
//                    cerr << "rb\n";
                }
//                cerr << i << " " << j << " " << k << " " << dp[i][j][k] << " " << r[i] << " " << g[j] << " " << b[k] << "\n";
                ans = max(ans, dp[i][j][k]);

            }
        }
    }
    cout << ans << "\n";

    return 0;
}