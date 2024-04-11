#include <bits/stdc++.h>
using namespace std;

const int maxn=1005;
const int mod=(int)1e9+7;

int r,g;
int f[maxn];
int dp[400001],vis[400001];

int solve(int x, bool &p){
    static int i,j;
    memset(dp,0,sizeof(dp));
    memset(vis,0,sizeof(vis));
    dp[0]=1;
    vis[0]=1;
    for(i=1;i<=x;i++) for(j=r;j>=i;j--) {
        dp[j]+=dp[j-i];
        vis[j]|=vis[j-i];
        if(dp[j]>=mod)
            dp[j]-=mod;
    }
    p=false;
    int ans=0,sum=(1+x)*x/2;
    for(i=0;i<=r;i++){
        if(sum-i>g)
            continue;
        p|=vis[i];
        ans+=dp[i];
        if(ans>=mod)
            ans-=mod;
    }
    return ans;
}

int main(){
    int i,x=-1;
    for(i=0;i<maxn;i++)
        f[i]=i*(i+1)/2;
    cin>>r>>g;
    for(i=0;i<maxn;i++)
        if(f[i]<=r+g)x=i;
    bool p;
    int ans;
    while(x){
        ans=solve(x,p);
        if(p) {
            cout<<ans;
            return 0;
        }
        x--;
    }
}