#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;

ll arr[maxn],dp[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    int c,d,n,m,k;
    cin>>c>>d;
    cin>>n>>m>>k;
    int sum=n*m-k;
    int dp[10010]={0};
    for(int i=1;i<=sum;i++)
    {
        dp[i]=min(dp[max(0,i-n)]+c,dp[i-1]+d);
    }
    if(sum<=0)cout<<0;
    else cout<<dp[sum];
}