#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define pii pair <int, int>
#define LL long long
using namespace std;

int num[100005];
LL dp[100005][3];

int main () {
    int n, a;
    cin >> n;
    for (int i = 1; i <= n; i++){
        scanf ("%d", &a);
        num[a]++;
    }
    dp[1][0] = 0;
    dp[1][1] = num[1];
    for (int i = 2; i <= 100000; i++){
        dp[i][0] = max (dp[i - 1][1], dp[i - 2][1]);
        dp[i][1] = dp[i - 1][0] + 1LL * num[i] * i;
    }
    cout << max (dp[100000][0], dp[100000][1]) << endl;
}