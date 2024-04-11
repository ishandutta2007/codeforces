#define NDEBUG

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
const ll MAX = 1000000000;

char rgb[3] = {'R', 'G', 'B'};

int main(){
    StarBurstStream

    int q;
    cin >> q;
    while(q--){

        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector<vector<int>> dp(n, vector<int>(3));

        int ans = MAX;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < k; j++){
                if(s[j] != rgb[(j + i) % 3]) dp[0][i]++;
            }
            ans = min(ans, dp[0][i]);
        }

        for(int i = 1; i + k - 1 < n; i++){
            for(int j = 0; j < 3; j++){
                dp[i][j] = dp[i - 1][(j + 2) % 3];
                if(s[i + k - 1] != rgb[(k + j - 1) % 3]){
                    dp[i][j]++;
                    //cerr << "test1 " << i << " " << j << "\n";
                }
                if(s[i - 1] != rgb[(j + 2) % 3]){
                    dp[i][j]--;
                    //cerr << "test2 " << i << " " << j << "\n";
                }
                ans = min(ans, dp[i][j]);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}