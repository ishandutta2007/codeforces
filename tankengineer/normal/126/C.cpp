#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2005;
int n;

char map[N][N];

int cur[N], mid[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", map[i]);
    }
    int ans = 0;
    memset(cur, 0, sizeof(cur));
    memset(mid, 0, sizeof(mid));
    for (int i = 0; i < n; ++i) {
        int acc = 0;
        for (int j = n - 1; j > i; --j) {
            if ((cur[j] ^ acc) != map[i][j] - '0') {
                cur[j] ^= 1, acc ^= 1;
                ++ans;
            }
        }
        mid[i] = acc ^ cur[i];
    }
    memset(cur, 0, sizeof(cur));
    for (int i = n - 1; i >= 0; --i) {
        int acc = 0;
        for (int j = 0; j < i; ++j) {
            if ((cur[j] ^ acc) != map[i][j] - '0') {
                cur[j] ^= 1, acc ^= 1;
                ++ans;
            }
        }
        mid[i] ^= acc ^ cur[i];
    }
    for (int i = 0; i < n; ++i) {
        ans += mid[i] ^ (map[i][i] - '0');
    }
    printf("%d\n", ans);
    return 0;
}