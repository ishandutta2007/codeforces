#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int MOD = 1000000007;

const int N = 5005;

int n;

int f[N][N];

char s[N];

int mem[N][N];

int cmp(int i, int j) {
    if (mem[i][j] != -1) {
        return mem[i][j];
    } else {
        return mem[i][j] = s[i] == s[j] ? 1 + cmp(i + 1, j + 1) : 0;
    }
}

int cmp(int i, int j, int len) {
    int l = cmp(i, j);
    if (l >= len) {
        return 0;
    } else {
        if (s[i + l] < s[j + l]) {
            return -1;
        } else {
            return 1;
        }
    }
}

int main() {
    memset(mem, -1, sizeof(mem));
    scanf("%d%s", &n, s);
    f[1][1] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= i; ++j) {
            (f[i + 1][j + 1] += f[i][j]) %= MOD;
            if (s[i] != '0' && i + j <= n && cmp(i - j, i, j) < 0) {
                (f[i + j][j] += f[i][j]) %= MOD;
            } else if (s[i] != '0' && i + j + 1 <= n) {
                (f[i + j + 1][j + 1] += f[i][j]) %= MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += f[n][i];
        ans %= MOD;
    }
    printf("%d\n", ans);
    return 0;
}