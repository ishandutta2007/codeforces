#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, T, u, v;
int a[1100010];

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d",&n,&u,&v);
        for (int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
        }
        bool con = true;
        for (int i=2;i<=n;i++) {
            if (a[i] < a[i - 1] - 1 || a[i] > a[i - 1] + 1) con = false;
        }
        if (!con) {
            puts("0");
            continue;
        }
        bool all_same = true;
        int ans = 1e9;
        for (int i=2;i<=n;i++) {
            if (a[i] != a[i - 1]) {
                all_same = false;
                ans = min(u, v);
            }
        }
        if (all_same) {
            ans = v + min(u, v);
        }
        printf("%d\n",ans);
    }

}