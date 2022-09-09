#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll MOD = 998244353;
int n;
int arr[100100];
ll d[2][210][3];
ll s[2][210][3];

int main() {
    int i, j, a, b;

    scanf("%d",&n);
    arr[0] = arr[n+1] = 1;
    for (i=1;i<=n;i++)scanf("%d",&arr[i]);
    d[0][1][0] = 1;
    for (i=1;i<=n;i++) {
        for (j=1;j<=200;j++) for (int k=0;k<3;k++){
            d[0][j][k] = (d[0][j][k]+d[0][j-1][k])%MOD;
        }
        for (j=1;j<=200;j++) {
            if (arr[i]!=-1&&arr[i]!=j) {
                d[1][j][0] = d[1][j][1] = d[1][j][2] = 0;
                continue;
            }
            d[1][j][0] = (d[0][200][0]-d[0][j][0]+d[0][200][1]-d[0][j][1])%MOD;
            d[1][j][1] = (d[0][j][0]-d[0][j-1][0]+d[0][j][1]-d[0][j-1][1]+d[0][j][2]-d[0][j-1][2])%MOD;
            d[1][j][2] = (d[0][j-1][0]+d[0][j-1][1]+d[0][j-1][2])%MOD;
        }
        for (j=1;j<=200;j++) for (int k=0;k<3;k++){
            d[0][j][k] = d[1][j][k];
        }
    }
    ll sum = 0;
    for (j=1;j<=200;j++) {
        sum += d[0][j][0]+d[0][j][1];
    }
    printf("%lld\n",(sum%MOD+MOD)%MOD);

    return 0;
}