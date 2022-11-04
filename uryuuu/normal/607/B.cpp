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
using namespace std;
const int maxn=200005;

int a[505],dp[505][505];
int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        memset(dp,inf,sizeof(dp));
        for(int i=0;i<=n;i++)
            dp[i][i]=1;
        for(int l=2;l<=n;l++)
        {
            for(int i=0;i+l-1<n;i++)
            {
                int j=i+l-1;
                if(a[i]==a[j]&&l>2)
                    dp[i][j]=dp[i+1][j-1];
                else if(a[i]==a[j])
                    dp[i][j]=1;
                for(int k=i;k<j;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
            }
        }
        cout<<dp[0][n-1]<<endl;
    }
    return 0;
}