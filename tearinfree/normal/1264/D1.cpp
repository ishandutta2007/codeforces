#include <bits/stdc++.h>
using namespace std;

using lli = long long;
const lli MOD = 998244353;

int n,ps[2011];
lli dp[2011][2011][2][2];
char str[2011];

lli power(lli a,lli p) {
    lli ret=1;
    while(p) {
        if(p&1) ret=ret*a%MOD;
        a=a*a%MOD;
        p>>=1;
    }
    return ret;
}

int get(char ch) {
    if(ch=='(') return 1;
    else if(ch==')') return 2;
    else return 3;
}
lli DP(int l,int r,int lf,int rf) {
    if(l>=r) return 0;
    if(l+1 == r) return lf==0 && rf==1;

    lli &ret = dp[l][r][lf][rf];
    if(ret!=-1) return ret;

    ret = 0;
    if(lf != rf) {
        int nl = get(str[l+1]), nr = get(str[r-1]), ad = (lf==0) * power(2, ps[r-1]-ps[l])%MOD;
        ret = ad;
        if(l+2!=r) {
            for(int i=0;i<2;i++) if(nl>>i&1) for(int j=0;j<2;j++) if(nr>>j&1) {
                ret = (ret + DP(l+1, r-1, i, j))%MOD;
            }
        }
    } else if(lf == 1) {
        int nl = get(str[l+1]);
        for(int i=0;i<2;i++) if(nl>>i&1) ret = (ret + DP(l+1, r, i, rf))%MOD;
    } else {
        int nr = get(str[r-1]);
        for(int i=0;i<2;i++) if(nr>>i&1) ret = (ret + DP(l, r-1, lf, i))%MOD;
    }

    return ret;
}

int main() {
    scanf("%s",str+1);
    n = strlen(str+1);
    for(int i=1;i<=n;i++) ps[i] = ps[i-1] + (str[i] == '?');

    memset(dp,-1,sizeof(dp));

    int nl=get(str[1]), nr = get(str[n]);
    lli ans=0;
    for(int i=0;i<2;i++) if(nl>>i&1) for(int j=0;j<2;j++) if(nr>>j&1) {
        ans = (ans + DP(1, n, i, j))%MOD;
    }
    printf("%lld\n",ans);
    
    return 0;
}