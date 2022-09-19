#include <bits/stdc++.h>

using namespace std;
#define int int16_t
int min(int x,int y)
{
    if(x>=y) return y;
    else return x;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <int> v;
    int a[n];
    for(int i=0;i<n;++i) {cin>>a[i];if(a[i]==1) v.push_back(i);}
    if(v.size()==0) {for(int i=0;i<=n*(n-1)/2;++i) cout<<0<<' ';return 0;}
    int dp[n+1][n*(n+1)/6+10][v.size()+1]; // (length,maxpermissionmoves,1count,lastcount0) // 5 stepen
    for(int i=0;i<=n;++i) for(int j=0;j<=n*(n+1)/6+9;++j) for(int l1=0;l1<=v.size();++l1)  dp[i][j][l1]=5000;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=n*(n+1)/6+9;++j)
        {
            for(int k=0;k<=v.size();++k)
            {
                if(k==1)
                {
                    if(j>=abs(i-1-v[0]))
                    dp[i][j][k]=((i-1)*(i-2))/2;
                    else {}
                    continue;
                }
                for(int t=0;t<i;++t)
                {
                     if(j>=abs(i-1-v[k-1]))
                     dp[i][j][k]=min(dp[i][j][k],dp[t][j-abs(i-1-v[k-1])][k-1]+(i-t-1)*(i-t-2)/2);
                }
            }
        }
    }
    //cout<<dp[2][1][1]<<endl;
    for(int j=0;j<=n*(n-1)/2;++j){
    int i=min(j,n*(n+1)/6+9);
    int ans1=5000;
    for(int l1=0;l1<=n;++l1)
    {
        ans1=min(ans1,dp[l1][i][v.size()]+((n-l1)*(n-l1-1))/2);
    }
    cout<<(int) ((n-v.size())*(n-v.size()-1))/2-ans1<<' ';
    }
    return 0;
}