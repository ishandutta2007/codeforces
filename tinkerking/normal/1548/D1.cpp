#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n;
int x[6010], y[6010];
int cnt[2][2];

int fuck(int dx,int dy) {
    if (dx % 2 == 0 && dy % 2 == 0) return 0;
    return 1;
}

int main() {
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d",&x[i],&y[i]);
        x[i] /= 2;
        y[i] /= 2;
    }
    LL ans = 0;
    for (int i = 1; i <= n; i++) {
        memset(cnt, 0, sizeof(cnt));
        for (int j = 1; j <= n; j++) {
            if (j != i) cnt[abs((x[i] - x[j]) % 2)][abs((y[i] - y[j]) % 2)]++;
        }
        for (int dx1 = 0; dx1 < 2; dx1++) {
            for (int dy1 = 0; dy1 < 2; dy1++) {
                for (int dx2 = 0; dx2 < 2; dx2++) {
                    for (int dy2 = 0; dy2 < 2; dy2++) {
                        int cnt1 = cnt[dx1][dy1];
                        int cnt2 = cnt[dx2][dy2];
                        if (dx1 == dx2 && dy1 == dy2) cnt2--;
                        int dx3 = abs((dx1 - dx2) % 2);
                        int dy3 = abs((dy1 - dy2) % 2);
                        int tmp = (fuck(dx1, dy1) + fuck(dx2, dy2) + fuck(dx3, dy3)) % 2;
                        if (tmp % 2 == 0) ans += 1LL * cnt1 * cnt2;
                    }
                }
            }
        }
    }
    ans /= 6;
    printf("%lld\n",ans);
}