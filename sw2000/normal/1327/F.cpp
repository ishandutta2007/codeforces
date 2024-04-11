#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
const int inf=0x3f3f3f3f;
const int mod=998244353;

int n,k,m,l[N],r[N],x[N];
ll dp[N];
int fg[N],lst[N];
int solve()
{
    int id=0;
    for(int i=1;i<=n;i++)
    {
        if(fg[i])dp[i]=0;
        else
        {
            dp[i]=dp[i-1]-(id?dp[id-1]:0);
        }
        dp[i]=(dp[i]+dp[i-1]+mod)%mod;
        id=max(id,lst[i]);
    }
    return (dp[n]-(id?dp[id-1]:0)+mod)%mod;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    cin>>n>>k>>m;
    for(int i=0;i<m;i++)
    {
        cin>>l[i]>>r[i]>>x[i];
    }
    ll ans=1;
    for(int i=0;i<k;i++)
    {
        memset(dp,0,sizeof(dp));
        memset(fg,0,sizeof(fg));
        memset(lst,0,sizeof(lst));
        dp[0]=1;

        for(int j=0;j<m;j++)
        {
            if(x[j]&1<<i)
            {
                fg[l[j]]++;
                fg[r[j]+1]--;
            }
            else
            {
                lst[r[j]]=max(lst[r[j]],l[j]);
            }
        }
        for(int i=1;i<=n;i++)
        {
            fg[i]+=fg[i-1];
        }
        ans=(ans*solve())%mod;
    }
    cout<<ans;
	return 0;
}