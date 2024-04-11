#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    const int32_t mod = 1e9 + 7;
    int n, k, d;
    cin >> n >> k >> d;
    vector<vector<int>> dp; // first is k, second is contains >d
    dp.push_back({1, 0});
    for(int i = 1; i <= n; i++){
        dp.push_back({0, 0});
        for(int j = 1; j <= min(i, k); j++){
            dp[i][0] += dp[i-j][0];
            dp[i][0] %= mod;
            if(j >= d){
                dp[i][1] += dp[i-j][0];
                dp[i][1] %= mod;
            }
            else{
                dp[i][1] += dp[i-j][1];
                dp[i][1] %= mod;
            }
        }
    }
    printf("%d\n", dp[n][1]);
    return 0;
}