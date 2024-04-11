#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n;
int a[1010];
LL mi[1010][1010], sum[1010][1010];

int main() {
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&a[i]);
        if (i % 2 == 0) a[i] = -a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            sum[i][j] = sum[i][j - 1] + a[j];
            mi[i][j] = min(mi[i][j - 1], sum[i][j]);
            //printf("mi[%d][%d] = %lld\n",i,j,mi[i][j]);
        }
    }
    LL ans = 0;
    for (int i = 1; i <= n; i += 2) {
        for (int j = i + 1; j <= n; j += 2) {
            LL sm = sum[i + 1][j - 1];
            LL m = mi[i + 1][j - 1];
            LL L_upbound = a[i];
            LL L_lobound = 1;
            L_lobound = max(L_lobound, -m);
            L_upbound = min(L_upbound, abs(a[j]) - sm);
            L_lobound = max(L_lobound, 1 - sm);
            //printf("?? %d %d %d %d\n",i+1,j-1,1-sm,m);
            //printf("sm = %lld, mi = %lld\n",sm,m);
            //printf("%d %d %lld %lld %lld\n",i,j,L_upbound,L_lobound,L_upbound - L_lobound + 1);
            if (L_lobound > L_upbound) continue;
            
            ans += L_upbound - L_lobound + 1;
        }
    }
    printf("%lld\n",ans);
}