#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 1000000
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int a[maxn+5];
vi f[maxn+5];
ll dp[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n)
    {
        for(int j=i;j<=maxn;j+=i) f[j].pb(i);
    }
    ll ans=0;
    dp[0]=1;
    rep(i,1,n)
    {
        int x=a[i],l=f[x].size();
        per(j,0,l-1)
        {
            int v=f[x][j];
            ans=(ans+dp[v-1])%mod;
            dp[v]=(dp[v]+dp[v-1])%mod;
        }
    }
    printf("%I64d\n",ans);
    return 0;
}