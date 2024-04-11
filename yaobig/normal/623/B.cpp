#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 1000000
#define mod 1000000007
#define inf (1ll<<60)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll ans=inf;
ll dp[maxn+5][3];
int a[maxn+5];
int n,A,B;

void solve(int p)
{
    rep(i,1,n)
    {
        ll cost=a[i]%p==0?0:(a[i]-1)%p==0 || (a[i]+1)%p==0?B:inf;
        dp[i][0]=dp[i-1][0]+cost;
        dp[i][1]=min(dp[i-1][0],dp[i-1][1])+A;
        dp[i][2]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+cost;
        rep(j,0,2) dp[i][j]=min(dp[i][j],inf);
    }
}

void cal(int x)
{
    vi p;
    for(int i=2;1ll*i*i<=x;i++)
    {
        if(x%i==0)
        {
            p.pb(i);
            while(x%i==0) x/=i;
        }
    }
    if(x>1) p.pb(x);
    for(auto pp: p)
    {
        solve(pp);
        rep(i,0,2) ans=min(ans,dp[n][i]);
    }
}

int main()
{
    scanf("%d%d%d",&n,&A,&B);
    rep(i,1,n) scanf("%d",&a[i]);
    cal(a[1]-1);
    cal(a[1]);
    cal(a[1]+1);
    cal(a[n]-1);
    cal(a[n]);
    cal(a[n]+1);
    printf("%I64d\n",ans);
    return 0;
}