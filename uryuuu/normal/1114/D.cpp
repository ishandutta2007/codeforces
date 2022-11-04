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
int inf=0x3f3f3f3f;
using namespace std;
int a[5010],b[5010];
int dp[5010][5010];
int main()
{
    int nn,aa,bb=-6000;
    while(cin>>nn)
    {
        int n=1;
        while(nn--)
        {
            cin>>aa;
            if(aa!=bb)
                a[n++]=aa;
            bb=aa;
        }
        for(int i=1;i<=n;i++)
        {
            b[i]=a[i];
        }
        reverse(b+1,b+n+1);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i]==b[j])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int s=n-2-(dp[n][n]/2);
        cout<<s<<endl;
    }
    return 0;
}