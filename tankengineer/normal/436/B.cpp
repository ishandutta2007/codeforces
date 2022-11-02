#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m, k;

int ans[2005];

char buf[2005];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        for (int j = 0; j < m; ++j) {
            int pos = -1;
            if (buf[j] == 'U') {
                pos = (i & 1) ? -1 : j;
            } else if (buf[j] == 'D') {
                pos = -1;
            } else if (buf[j] == 'L') {
                pos = j - i;
            } else if (buf[j] == 'R') {
                pos = j + i;
            }
            if (pos >= 0 && pos < m) {
                ++ans[pos];
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        printf("%d%c", ans[i], i == m - 1 ? '\n' : ' ');
    }
    return 0;
}