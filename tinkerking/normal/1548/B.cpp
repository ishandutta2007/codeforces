#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n;
LL a[200010], b[200010];
typedef pair<LL,LL> pll;
vector<pll> f[200010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for (int i = 0; i <= n; i++) f[i].clear();
        for (int i = 1; i <= n; i++) {
            scanf("%lld",&a[i]);
        }
        for (int i = 1; i < n; i++) {
            b[i] = abs(a[i + 1] - a[i]);
        }
        n--;
        for (int i = 1; i <= n; i++) {
            f[i].emplace_back(b[i], i);
            int v1 = f[i - 1].size(), v2 = 1;
            for (int j = 0; j < v1; j++) {
                LL tmp = __gcd(b[i], f[i - 1][j].first);
                if (tmp == f[i][v2 - 1].first) {
                    f[i][v2 - 1].second = f[i - 1][j].second;
                } else {
                    f[i].emplace_back(tmp, f[i - 1][j].second);
                    v2++;
                }
            }
        }
        //for (int i = 1; i <= n; i++) printf("%lld ",b[i]); puts("");
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            for (auto &t : f[i]) {
                //printf("%d %lld %lld\n",i,t.first,t.second);
                if (t.first == 1) continue;
                ans = max(ans, int(i - t.second + 2));
            }
        }
        printf("%d\n",ans);
    }
}