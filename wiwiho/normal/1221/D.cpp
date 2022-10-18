//#define NDEBUG

#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
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
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 1LL << 62;

int main(){
    StarBurstStream

    int q;
    cin >> q;

    while(q--){

        int n;
        cin >> n;

        vector<ll> a(n + 1), b(n + 1);
        for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];

        vector<vector<ll>> dp(n + 1, vector<ll>(3));

        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= 2; j++){
                dp[i][j] = MAX;
                for(int k = 0; k <= 2; k++){
                    if(a[i] + j == a[i - 1] + k) continue;
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + b[i] * j);
                }
            }
        }

        cout << min({dp[n][0], dp[n][1], dp[n][2]}) << "\n";


    }

    return 0;
}