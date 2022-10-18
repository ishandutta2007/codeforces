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

const ll MOD = 998244353;
const ll MAX = 2147483647;

int main(){
    StarBurstStream

    int w, h;
    cin >> w >> h;

    vector<vector<vector<ll>>> dp(4, vector<vector<ll>>(w + 1, vector<ll>(h + 1)));
    dp[0][1][1] = 1;
    dp[1][1][1] = 1;
    dp[2][1][1] = 1;
    dp[3][1][1] = 1;

    for(int i = 1; i <= w; i++){

        for(int j = 1; j <= h; j++){

            if(i == 1 && j == 1) continue;

            dp[0][i][j] = max(max(dp[0][i - 1][j] + dp[1][i - 1][j], 1LL) % MOD, (max(dp[0][i][j - 1] + dp[3][i][j - 1], 1LL)) % MOD) % MOD;
            dp[1][i][j] = max(max(dp[0][i - 1][j] + dp[1][i - 1][j], 1LL) % MOD, (max(dp[1][i][j - 1] + dp[2][i][j - 1], 1LL)) % MOD) % MOD;
            dp[2][i][j] = max(max(dp[2][i - 1][j] + dp[3][i - 1][j], 1LL) % MOD, (max(dp[1][i][j - 1] + dp[2][i][j - 1], 1LL)) % MOD) % MOD;
            dp[3][i][j] = max(max(dp[2][i - 1][j] + dp[3][i - 1][j], 1LL) % MOD, (max(dp[0][i][j - 1] + dp[3][i][j - 1], 1LL)) % MOD) % MOD;
            //cerr << i << " " << j << " " << dp[0][i][j] << " " << dp[1][i][j] << " " << dp[2][i][j] << " " << dp[3][i][j] << "\n";
        }

    }

    cout << (dp[0][w][h] + dp[1][w][h] + dp[2][w][h] + dp[3][w][h]) % MOD << "\n";


    return 0;

}