#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100,Z=7,INF=1e18;

int a[N];
int dp[N][Z][2];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k,z;
        cin>>n>>k>>z;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            for(int j=0;j<=z;j++)
                for(int q=0;q<=1;q++)
                    dp[i][j][q]=-INF;
        dp[1][0][0]=a[1];
        for(int _=0;_<=Z;_++)
            for(int i=1;i<=n;i++)
                for(int j=0;j<=z;j++)
                    for(int q=0;q<=1;q++)
                    {
//                        cout<<i<<" "<<j<<" "<<q<<" -> "<<dp[i][j][q]<<"\n";
                        if(i<n)
                            dp[i+1][j][0]=max(dp[i+1][j][0],dp[i][j][q]+a[i+1]);
                        if(i>1&&j<z&&!q)
                            dp[i-1][j+1][1]=max(dp[i-1][j+1][1],dp[i][j][0]+a[i-1]);
                    }
        int ans=-INF;
        for(int j=0;j<=z;j++)
            for(int q=0;q<=1;q++)
            {
                int i=1+(k-j)-j;
                if(1<=i&&i<=n)
                    ans=max(ans,dp[i][j][q]);
            }
        cout<<ans<<"\n";
    }
}