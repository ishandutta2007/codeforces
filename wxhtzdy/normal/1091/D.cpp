#include <bits/stdc++.h>

using namespace std;

const long long md = 998244353;

int main(){
    int n;
    cin >> n;
    long long dp[n + 1];
    dp[1] = 1;
    long long fact = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + fact - 1) * i % md;
        fact *= i;
        fact %= md;
        dp[i] %= md;
    }
    cout << dp[n];
}