#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=110;

int dp[N][N*N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int k=0;k<N;k++)
        for(int x=0;x<N*N;x++)
            dp[k][x]=-1e9;
    dp[0][0]=0;
    int s=0;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        s+=b;
        for(int k=i-1;k>=0;k--)
            for(int x=0;x+a<N*N;x++)
                dp[k+1][x+a]=max(dp[k+1][x+a],dp[k][x]+b);
    }
    for(int k=1;k<=n;k++)
    {
        int ans=0;
        for(int x=0;x<N*N;x++)
            ans=max(ans,min(2*x,s+dp[k][x]));
        cout<<ans/2<<"."<<ans%2*5<<" ";
    }
}