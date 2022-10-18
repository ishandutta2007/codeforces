#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int L=35;

int dp[L][L];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int d,m;
        cin>>d>>m;
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=1;i<L;i++)
            for(int j=0;(1<<j)<=d;j++)
            {
                if(i==1)
                    dp[i][j]=1;
                else
                    for(int k=0;k<j;k++)
                        dp[i][j]+=dp[i-1][k];
                dp[i][j]%=m;
                if((1<<(j+1))-1>=d)
                    dp[i][j]*=d-(1<<j)+1;
                else
                    dp[i][j]*=1<<j;
                dp[i][j]%=m;
                ans+=dp[i][j];
            }
        cout<<ans%m<<"\n";
    }
}