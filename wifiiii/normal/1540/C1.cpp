#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9+7;
int c[105],b[105];
ll dp[105][10005],sdp[10005];
int main() {
    int n;
    cin >> n;
    for(int i=1;i<=n;++i) cin>>c[i];
    for(int i=1;i<n;++i) cin>>b[i];
    int q,x;
    cin>>q>>x;
    dp[0][0]=1;
    int s=0,s2=0;
    for(int i=1;i<=n;++i) {
        sdp[0]=dp[i-1][0];
        s+=x+s2;
        for(int j=1;j<=n*100;++j) sdp[j]=(sdp[j-1]+dp[i-1][j])%mod;
        for(int j=0;j<=n*100;++j) {
            dp[i][j]=sdp[j];
            if(j-c[i]-1>=0) dp[i][j]-=sdp[j-c[i]-1];
        }
        for(int j=0;j<min(n*100,s);++j) dp[i][j]=0;
        // sum >= s
        s2+=b[i];

    }
    s=max(s,0);
    ll ans=0;
    for(int i=s;i<=n*100;++i) ans+=dp[n][i];
    ans%=mod;
    if(ans<0) ans+=mod;
    cout<<ans<<endl;
}