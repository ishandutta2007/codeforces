#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int T, n, S[5010];
int fa[5010];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void remove(int x) {
    fa[x] = find(x + 1);
}

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for (int i=1;i<=n+1;i++) {
            fa[i] = i;
        }
        LL ans = 0;
        for (int i=1;i<=n;i++) {
            scanf("%d",&S[i]);
            if (S[i] == 1) remove(i);
        }
        while(true) {
            int f = find(1);
            if (f == n+1) break;
            if (S[f] > n + 1) {
                ans += S[f] - n - 1;
                S[f] = n + 1;
            }
            //printf("f = %d\n",f);
            ans++;
            while(f <= n) {
                int tmp = f;
                f = find(min(f + S[f], n+1));
                //printf("?? %d\n",f);
                if (S[tmp] == 2) remove(tmp);
                S[tmp] = max(S[tmp] - 1, 1);
            }
        }
        printf("%lld\n",ans);
    }
}