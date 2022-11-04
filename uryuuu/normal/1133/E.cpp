#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#define ll long long
int inf=0x3f3f3f3f;
using namespace std;
int a[200010];
int dp[5005][5005];
int main()
{
    memset(dp,0,sizeof(dp));
    int n,k;
    int zd=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    int l=1,r=1;
    for(r=1;r<=n;r++)
    {
      while(a[r]-a[l]>5&&l<r)
          l++;
        for(int i=1;i<=k;i++)
        {
            dp[r][i]=max(dp[r-1][i],dp[l-1][i-1]+r-l+1);
        }
    }
    for(int i=1;i<=k;i++)
    {
        zd=max(dp[n][i],zd);
    }
    cout<<zd<<endl;
    return 0;
}