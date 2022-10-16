#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 2000
#define mod 998244353
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int l[maxn+5],r[maxn+5],a[maxn+5];
ll dp[maxn+5][2];

int main()
{
    int n,k; scanf("%d%d",&n,&k);
    rep(i,1,n) scanf("%d%d%d",&l[i],&r[i],&a[i]);
    l[n+1]=inf;

    rep(i,0,n) dp[i][0]=dp[i][1]=1ll<<60;
    dp[0][0]=0;

    rep(i,0,n-1) if(dp[i][0]<1ll<<60)
    {
        ll tmp=dp[i][0]+k,rem=k;
        rep(j,i+1,n)
        {
            ll x=(a[j]-rem+k-1)/k;
            if(x>r[j]-l[j]) break;
            tmp+=x*k;
            rem+=x*k-a[j];
            if(x<r[j]-l[j] || l[j+1]>r[j]) dp[j][0]=min(dp[j][0],tmp);
            dp[j][1]=min(dp[j][1],tmp-rem);
        }
    }
    if(dp[n][1]==1ll<<60) puts("-1");
    else printf("%lld\n",dp[n][1]);
    return 0;
}