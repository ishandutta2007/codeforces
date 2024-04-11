#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200000
#define mod 998244353
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int dp[1<<22];

int main()
{
    int n,x,y; scanf("%d%d%d",&n,&x,&y);
    int p=x+y,m=max(x,y),N=1<<m;
    per(i,0,p-1) per(s,0,N-1) if(i>=p || (s&(1<<i))==0)
    {
        int ns=s;
        if(i-x>=0) ns|=1<<(i-x);
        if(i-y>=0) ns|=1<<(i-y);
        dp[ns]=max(dp[ns],dp[s]+(n-i+p-1)/p);
    }
    int ans=0;
    rep(s,0,N-1) ans=max(ans,dp[s]);
    printf("%d\n",ans);
    return 0;
}