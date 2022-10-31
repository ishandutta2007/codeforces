#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli = long long;
using pii = pair<int,int>;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

int n,m;
char str[2010][2010];

const int MOD = 1e9+7;
int ps[2010][2010][2], md[2010][2010][2], dp[2010][2010][2];

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",str[i]+1);

    if(n==1 && m==1) {
        puts("1");
        return 0;
    }

    for(int i=1;i<=n;i++) {
        int cnt=0;
        for(int j=m;j;j--) {
            md[i][j][0] = m-cnt;
            cnt += str[i][j]=='R';
        }
    }
    for(int j=1;j<=m;j++) {
        int cnt=0;
        for(int i=n;i;i--) {
            md[i][j][1] = n-cnt;
            cnt += str[i][j]=='R';
        }
    }

    ps[n][m][0] = ps[n][m][1] = 1;
    for(int i=n;i;i--) for(int j=m;j;j--) {
        if(i==n && j==m) continue;

        dp[i][j][0] = ((ps[i][j+1][1] - ps[i][md[i][j][0]+1][1])%MOD + MOD)%MOD;
        dp[i][j][1] = ((ps[i+1][j][0] - ps[md[i][j][1]+1][j][0])%MOD + MOD)%MOD;
        ps[i][j][0] = (dp[i][j][0] + ps[i+1][j][0])%MOD;
        ps[i][j][1] = (dp[i][j][1] + ps[i][j+1][1])%MOD;
    }

    printf("%d\n", (dp[1][1][0] + dp[1][1][1])%MOD);

    return 0;
}