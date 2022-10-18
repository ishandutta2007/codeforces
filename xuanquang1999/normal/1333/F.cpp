#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500005;

int n, ans[MAXN];
bool avail[MAXN];

int main() {
    scanf("%d", &n);

    fill(avail + 1, avail + n + 1, true);

    int lastCnt = n, curCnt = n;

    for(int x = n/2; x >= 1; --x) {
        for(int i = x * 2; i <= n; i += x) {
            if (avail[i]) {
                avail[i] = false;
                --curCnt;
            }
        }
        for(int i = curCnt + 1; i <= lastCnt; ++i)
            ans[i] = x;            
        lastCnt = curCnt;
    }

    for(int i = 2; i <= n; ++i)
        printf("%d ", ans[i]);
    puts("");

    return 0;
}