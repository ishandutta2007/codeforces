#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int K=210,MOD=1e9+7;

int dp[2*K][K],ans[2*K];

int ppow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)
            res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}

int rev(int x)
{
    return ppow(x,MOD-2);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    dp[0][0]=1;
    ans[0]=1;
    for(int i=2;i<=2*k&&i<=n;i++)
        for(int j=1;j<=i/2;j++)
        {
            for(int t=2,A=(n-i+1)*(n-i+2)%MOD;t<=i-2*(j-1);t++,A=A*(n-i+t)%MOD)
//                cout<<i<<" "<<j<<" "<<t<<" -> "<<A*rev(t)%MOD*dp[i-t][j-1]<<"\n",
                dp[i][j]=(dp[i][j]+A*rev(t)%MOD*dp[i-t][j-1])%MOD;
            int temp=dp[i][j];
            for(int t=1;t<=j;t++)
                temp=temp*rev(t)%MOD;
            ans[i-j]=(ans[i-j]+temp)%MOD;
        }
    for(int i=2;i<=k;i++)
        ans[i]=(ans[i]+ans[i-2])%MOD;
    for(int i=1;i<=k;i++)
        cout<<ans[i]<<" ";
}