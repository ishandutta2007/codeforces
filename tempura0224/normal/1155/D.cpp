#include<iostream>
using namespace std;
using ll = long long;


ll dp[303030][5];
int main(){
    int n;cin>>n;
    ll x;cin>>x;
    ll a[n];
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i){
        dp[i+1][0]=0;
        dp[i+1][1]=max(dp[i][1]+a[i],dp[i+1][0]);
        dp[i+1][2]=max(dp[i][2]+x*a[i],dp[i+1][1]);
        dp[i+1][3]=max(dp[i][3]+a[i],dp[i+1][2]);
        dp[i+1][4]=max(dp[i][4],dp[i+1][3]);
    }
    cout<<dp[n][4]<<endl;
    return 0;
}