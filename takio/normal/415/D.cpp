#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const long long mod = 1e9 + 7;

vector <long long> g[2010];
long long dp[2010][2010], sum[2010][2010];

int main() {
    long long n, k;
    cin >> n >> k;
    for (long long i = 2; i <= n; i++){
        g[i].push_back(1);
        for (long long j = 2; j <= (int)sqrt(i); j++)
            if(i % j == 0) {
                g[i].push_back(j);
                if(i / j != j) g[i].push_back(i / j);
            }
    }
//    for (long long i = 1; i <= n; i++){
//        cout << i << ':';
//        for(long long j = 0; j < g[i].size(); j++)
//            cout << ' ' << g[i][j];
//        cout << endl;
//    }
    for (long long i = 1; i <= k; i++) dp[1][i] = 1, sum[1][i] = i;
    for (long long i = 2; i <= n; i++){
        for (long long l = 1; l <= k; l++){
            for (long long j = 0; j < g[i].size(); j++)
                dp[i][l] += sum[g[i][j]][l - 1],
                dp[i][l] %= mod;
            dp[i][l]++;
            sum[i][l] = sum[i][l - 1] + dp[i][l];
            sum[i][l] %= mod;
        }
    }
    long long res = 0;
//    for (long long i = 1; i <= n; i++){
//        for (long long j = 1; j <= k; j++)
//            cout << dp[i][j] << ' ';
//            cout <<endl;
//    }
    for(long long i = 1; i <= n; i++)
        res += dp[i][k];
        res %= mod;
    cout << res;
}