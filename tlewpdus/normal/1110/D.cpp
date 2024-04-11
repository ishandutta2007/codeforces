#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n, m;
int cnt[1000100];
int D[1000100][3][3];

bool good(int i, int j, int k, int l) {
    return cnt[i-2]>=j+k+l&&cnt[i-1]>=k+l&&cnt[i]>=l;
}

int main() {
    int i, j, k, l;

    scanf("%d%d",&n,&m);
    for (i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        cnt[a+4]++;
    }
    for (j=0;j<3;j++) for (k=0;k<3;k++) D[2][j][k] = -INF;
    D[2][0][0] = 0;
    for (i=5;i<=m+10;i++) {
        for (j=0;j<3;j++) {
            for (k=0;k<3;k++) {
                for (l=0;l<3;l++) {
                    if (good(i,l,j,k)) {
                        D[i][j][k] = max(D[i][j][k],D[i-1][l][j]+(cnt[i-2]-j-k-l)/3+k);
                    }
                }
            }
        }
    }
    printf("%d\n",D[m+10][0][0]);

    return 0;
}