#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <iostream>
#include <ctime>
#define ll long long
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r

using namespace std;

const int N = 100100, mod = 1e9 + 7;
int dp[N], sum[N];

int main () {
    int t, k;
    cin >> t >> k;
    dp[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        if (i - k < 0) dp[i] = dp[i - 1];
        else (dp[i] = dp[i - 1] + dp[i - k]) %= mod;
        (sum[i] = sum[i - 1] + dp[i]) %= mod;
    }
//    for (int i = 1; i <= 4; i++) cout <<dp[i] << ' ';
    int a, b;
    for (int i = 1; i <= t; i++) {
        scanf ("%d%d", &a, &b);
        printf ("%d\n", ((sum[b] - sum[a - 1]) % mod + mod) % mod);
    }
}