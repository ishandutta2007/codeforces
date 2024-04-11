#include <cstdio>
#include <algorithm>

using namespace std;

int binom[1013][1013];
int c[1013];
const int MOD = 1000000007;

int main() {
    binom[0][0] = 1;
    for (int i=1;i<1013;i++) for (int j=0;j<1013;j++) {
        binom[i][j] = binom[i-1][j];
        if (j) binom[i][j] = (binom[i][j]+binom[i-1][j-1])%MOD;
    }
    int k;
    scanf("%d",&k);
    for (int i=0;i<k;i++) scanf("%d",&c[i]);
    int ans = 1;
    for (int i=k-1;i>=0;i--) {
        int tot = 0;
        for (int j=0;j<=i;j++) tot+=c[j];
        ans = ((long long) ans*binom[tot-1][c[i]-1])%MOD;
    }
    printf("%d\n",ans);

    return 0;
}