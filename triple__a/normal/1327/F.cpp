#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
const int maxn=500007;

int n,m,k,l[maxn],r[maxn],x[maxn];

int add(int u,int v){
    return ((u+v)%mod+mod)%mod;
}

int solve(int u){
    vector<int> f,g,dp;
    f.resize(n+7,0), g.resize(n+7,0),dp.resize(n+7,0);
    for (int i=1;i<=m;++i){
        if (x[i]>>u&1){
            f[l[i]]++, f[r[i]+1]--;
        }
        else{
            g[r[i]]=max(g[r[i]],l[i]);
        }
    }
    dp[0]=1;
    int p=0;
    for (int i=1;i<=n;++i){
        if (f[i]>0){
            dp[i]=dp[i-1];
        }
        else{
            dp[i]=add(dp[i-1],p?dp[i-1]-dp[p-1]:dp[i-1]);  
        }
        f[i+1]+=f[i];
        p=max(p,g[i]);
    }
    return add(dp[n],p?-dp[p-1]:0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>k>>m;
    for (int i=1;i<=m;++i){
        cin>>l[i]>>r[i]>>x[i];
    }
    int ret=1;
    for (int i=0;i<k;++i){
        ret=1ll*ret*solve(i)%mod;
    }    
    cout<<ret;
    return 0;
}