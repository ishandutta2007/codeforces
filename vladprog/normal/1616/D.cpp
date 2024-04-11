#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=5e4+100,INF=1e18;

int a[N],dp[N][2][2];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int x;
        cin>>x;
        for(int i=1;i<=n;i++)
            a[i]-=x;
        a[0]=-INF;
        dp[1][0][0]=dp[1][0][1]=0;
        dp[1][1][0]=dp[1][1][1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i][0][0]=max(dp[i-1][0][0],dp[i-1][0][1]);
            dp[i][0][1]=max(dp[i-1][1][0],dp[i-1][1][1]);
            dp[i][1][0]=max(dp[i-1][0][0],dp[i-1][0][1])+1;
            bool two=a[i]+a[i-1]>=0;
            bool three=a[i]+a[i-1]+a[i-2]>=0;
            if(two&&three)
                dp[i][1][1]=max(dp[i-1][1][0],dp[i-1][1][1])+1;
            else if(two)
                dp[i][1][1]=dp[i-1][1][0]+1;
            else
                dp[i][1][1]=-INF;
        }
        cout<<max({dp[n][0][0],dp[n][0][1],dp[n][1][0],dp[n][1][1]})<<"\n";
    }
}