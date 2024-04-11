#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 998244353
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

ll dp[5];
char s[maxn+5];
int a[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    scanf("%s",s+1);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n)
    {
        if(s[i]=='h')
        {
            dp[1]=min(dp[1],dp[0]);
            dp[0]=dp[0]+a[i];
        }
        if(s[i]=='a')
        {
            dp[2]=min(dp[2],dp[1]);
            dp[1]=dp[1]+a[i];
        }
        if(s[i]=='r')
        {
            dp[3]=min(dp[3],dp[2]);
            dp[2]=dp[2]+a[i];
        }
        if(s[i]=='d')
        {
            dp[3]=dp[3]+a[i];
        }
    }
    ll ans=1ll<<60;
    rep(i,0,3) ans=min(ans,dp[i]);
    printf("%I64d\n",ans);
    return 0;
}