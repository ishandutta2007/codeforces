#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5005;

int n;

short diff[N][N]; 
bool cmp[N][N];

char s[N];

bool bk[N];
int dp[N][N], mins[N][N], ways[N][N], sum[N][N];

const int MOD = 1000000007;

const int INF = 1000000000;

int num1[N], num2[N];

bool cmpp(int pos1, int delta1, int pos2, int delta2) {
//cout << pos1 << ' ' << delta1 << ' ' << pos2 << ' ' << delta2 << endl;
    if (delta1 >= delta2) {
        return false;
    }
    int len = 0;
    for (int i = n - 1; i >= pos2; --i) {
        num1[len++] = 0;
    }
    for (int i = pos2 - 1; i >= pos1; --i) {
        num1[len++] = s[i] - '0';
    }
    int top = 0, delta = delta2 - delta1;
    while (delta) {
        num2[top++] = delta & 1;
        delta >>= 1;
    }
    if (len != top) {
        return len < top;
    }
    for (int i = len - 1; i >= 0; --i) {
        if (num1[i] != num2[i]) {
            return num1[i] < num2[i];
        }
    }
    return false;
}

int cal(int pos, int delta) {
    int ret = 0;
    for (int i = pos; i < n; ++i) {
        ret = (ret * 2 + (s[i] - '0')) % MOD;
    }
    return (ret + delta) % MOD;
}

int main() {
    scanf("%s", s);
    n = strlen(s);
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            if (s[i] == s[j]) {
                if (j + 1 == n) {
                    diff[i][j] = 0;
                } else {
                    diff[i][j] = 1 + diff[i + 1][j + 1];
                }
            } else {
                diff[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int len = diff[i][j];
            if (i + len >= j || s[i + len] <= s[j + len]) {
                cmp[i][j] = true;
            } else {
                cmp[i][j] = false;
            }
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = INF;
        }
    }
    for (int j = 0; j < n; ++j) {
        if (j != n - 1 && s[j + 1] != '1') {
            continue;
        }
        for (int i = 0; i <= j; ++i) {
            if (s[i] != '1') {
                continue;
            }
            if (i == 0) {
                dp[i][j] = 1;
                ways[i][j] = 1;
            } else {
                int len = j - i + 1;
                dp[i][j] = mins[max(0, i - len + 1)][i - 1] + 1;
                ways[i][j] = sum[max(0, i - len + 1)][i - 1];
                if (i - len >= 0 && cmp[i - len][i]) {
                    dp[i][j] = min(dp[i][j], dp[i - len][i - 1] + 1);
                    (ways[i][j] += ways[i - len][i - 1]) %= MOD;
                }
            }
        }
        mins[j + 1][j] = INF;
        sum[j + 1][j] = 0;
        for (int i = j; i >= 0; --i) {
            mins[i][j] = min(dp[i][j], mins[i + 1][j]);
            (sum[i][j] = ways[i][j] + sum[i + 1][j]) %= MOD;
        }
    }
    int ans1 = -1, ans2 = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (ways[i][n - 1]) {
            (ans2 += ways[i][n - 1]) %= MOD;
            if (ans1 == -1 || cmpp(i, dp[i][n - 1], ans1, dp[ans1][n - 1])) {
                ans1 = i;
            }
        }
    }
    printf("%d\n%d\n", ans2, cal(ans1, dp[ans1][n - 1]));
    return 0;
}