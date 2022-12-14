#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int dp[maxn],cnt[100][maxn],n,m;
bool vis[maxn];

struct A
{
    int a,b;
}arr[100];

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].a>>arr[i].b;
    }
    sort(arr,arr+n,[](A a,A b){return a.a<b.a;});

    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>=arr[j].a-arr[j].b&&i<=arr[j].a+arr[j].b)
            {
                vis[i]=1;
                break;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        int a=arr[i].a,b=arr[i].b;
        for(int j=a+b+1;j<=m;j++)
        {
            cnt[i][j]=j-b-a;
        }
    }

    for(int i=1;i<=m;i++)
    {
        dp[i]=dp[i-1];
        if(vis[i])
        {
            continue;
        }
        dp[i]++;
        for(int j=0;arr[j].a<i&&j<n;j++)
        {
            dp[i]=min(dp[i],cnt[j][i]+dp[max(0,2*arr[j].a-i-1)]);
        }
    }
    printf("%d",dp[m]);
    return 0;
}