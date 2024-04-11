#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,mod=1e9+7;
int n,p,dp[N],a[N];
set<int>st;
int solve(int x){
    if(st.find(x)!=st.end())return 0;
    if(x==0)return 1;
    if((!(x&1))){
        if(!(x&2))return solve(x>>2);
        else return 1;
    }
    else{
        return solve(x>>1);
    }
}
int main(){
    dp[1]=1;
    dp[0]=1;
    for(int i=2;i<N;i++)dp[i]=(dp[i-1]+dp[i-2])%mod;
    for(int i=1;i<N;i++)dp[i]=(dp[i]+dp[i-1])%mod;
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    stable_sort(a+1,a+n+1);
    vector<int>v;
    for(int i=1;i<=n;i++){
        if(solve(a[i]))v.push_back(a[i]),st.insert(a[i]);
    }
    long long ans=0;
    for(int i:v){
        int now=log2(i);
        if(now>=p)continue;
        ans=(ans+dp[p-now-1])%mod;
    }
    printf("%lld\n",ans);
    return  0;
}