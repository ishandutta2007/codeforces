#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 5e3 + 10;
const ll mod = 1e9 + 7;
ll dp[N][N],sum[N],arr[N];
int n,k,q;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    for(int i=1;i<=n;i++)
    {
        dp[0][i]=1;
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
            dp[i][j]%=mod;
        }
    }
    for(int i=0;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            sum[j]+=dp[i][j]*dp[k-i][j]%mod;
            sum[j]%=mod;
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
        ans+=arr[i]*sum[i]%mod;
    while(q--)
    {
        int i,x;
        cin>>i>>x;
        ans+=(x-arr[i])*sum[i]%mod;
        ans%=mod;
        arr[i]=x;
        if(ans<0)ans+=mod;
        cout<<ans<<endl;
    }
    return 0;
}