#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int M=2e5+100,MOD=1e9+7;

int dp[M][10];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int d=0;d<10;d++)
        dp[0][d]=1;
    for(int k=1;k<M;k++)
    {
        for(int d=0;d<9;d++)
            dp[k][d]=dp[k-1][d+1];
        dp[k][9]=(dp[k-1][1]+dp[k-1][0])%MOD;
    }

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int ans=0;
        while(n)
            ans+=dp[m][n%10],
            n/=10;
        cout<<ans%MOD<<"\n";
    }
}