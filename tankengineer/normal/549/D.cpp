#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 105;

int n, m;

int cnt[N][N];

char map[N][N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", map[i]);
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            int f = map[i][j] == 'W' ? 1 : -1;
            if (j < m - 1) {
                cnt[i][j] += cnt[i][j + 1];
            }
            if (i < n - 1) {
                cnt[i][j] += cnt[i + 1][j];
            }
            if (i < n - 1 && j < m - 1) {
                cnt[i][j] -= cnt[i + 1][j + 1];
            }
            if (f != cnt[i][j]) {
                ++ans;
                int d = -cnt[i][j] + f;
                cnt[i][j] += d;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}