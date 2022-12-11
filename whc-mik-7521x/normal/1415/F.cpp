#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+10;
int n,t[N],x[N],dp[N][N],tim[N];
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld%lld",&t[i],&x[i]);
    for(int i=1;i<=n;i++){
        for(int o=1;o<n;o++){
            if(t[o]>t[o+1])swap(t[o],t[o+1]),swap(x[o],x[o+1]);
        }
    }
    memset(tim,63,sizeof tim);
    dp[0][0]=1;
    tim[0]=0;
    for(int i=1;i<=n;i++){
        for(int o=i+1;o<=n;o++){
            if(abs(t[i]-t[i-1])>=abs(x[i]-x[i-1]))dp[i][o]|=dp[i-1][o];
            if(i>2&&dp[i-2][i-1]&&max(t[i-1],abs(x[i-2]-x[o])+t[i-2])+abs(x[o]-x[i])<=t[i])dp[i][o]|=dp[i-2][i-1];
            if(max(tim[i-1]+abs(x[i-1]-x[o]),t[i-1])+abs(x[o]-x[i])<=t[i])dp[i][o]=1;
        }
        for(int o=i;o<=n;o++)if(dp[i-1][o])tim[i]=min(tim[i],t[i-1]+abs(x[i-1]-x[i]));
        tim[i]=min(tim[i],max(tim[i-1]+abs(x[i-1]-x[i]),t[i-1]));
        if(i>2&&dp[i-2][i-1])tim[i]=min(tim[i],max(t[i-1],t[i-2]+abs(x[i-2]-x[i])));
        if(tim[i]>t[i])tim[i]=1e18;
    }
    puts(tim[n]<=t[n]||dp[n-1][n]?"YES":"NO");
}