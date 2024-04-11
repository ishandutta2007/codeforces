#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, m;
int cnt[200010];

int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d",&u,&v);
        if (u > v) swap(u, v);
        cnt[u]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (cnt[i] == 0);
    }
    int Q;
    scanf("%d",&Q);
    while(Q--) {
        int tp, u, v;
        scanf("%d",&tp);
        if (tp == 1) {
            scanf("%d%d",&u,&v);
            if (u > v) swap(u, v);
            if (++cnt[u] == 1) ans--;
        } else if (tp == 2) {
            scanf("%d%d",&u,&v);
            if (u > v) swap(u, v);
            if (--cnt[u] == 0) ans++;
        } else {
            printf("%d\n",ans);
        }
    }
}