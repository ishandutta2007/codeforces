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
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define pii pair<int,int>
using namespace std;
const int maxn=1010;

int n,k;
int a[maxn][maxn],b[maxn][maxn],dp[maxn];
int check(int x,int y)
{
    for(int i=2;i<=k;i++)
    {
        if(b[i][x]>b[i][y])
            return 0;
    }
    return 1;
}

int main()
{
    sync;
    cin>>n>>k;
    for(int i=1;i<=k;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            b[i][a[i][j]]=j;
        }
    for(int i=1;i<=n;i++)
    {
        dp[i]=1;
    }
    
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            if(check(a[1][i],a[1][j]))
                dp[j]=max(dp[i]+1,dp[j]);
        }
    
    for(int i=1;i<=n;i++)
        ans=max(ans,dp[i]);
    cout<<ans<<endl;
    return 0;
}