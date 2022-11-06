#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <fstream>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = (int)a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second

using namespace std;

typedef long long base;

int n;
int arr[501];
int dp[501][501];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    For(i, 0, n) cin >> arr[i];
    Out(L, n, 0) {
        dp[L][L] = 1;
        dp[L + 1][L] = 1;
        For(R, L + 1, n) {
            if (arr[L] == arr[R]) dp[L][R] = dp[L + 1][R - 1];
            else dp[L][R] = min(dp[L + 1][R], dp[L][R - 1]) + 1;
            For(M, L, R) dp[L][R] = min(dp[L][R], dp[L][M] + dp[M + 1][R]);
        }
    }
    cout << dp[0][n - 1];
}