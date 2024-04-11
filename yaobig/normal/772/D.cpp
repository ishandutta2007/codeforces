#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 1000000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

void add(int &x,int y) {x=x+y<mod?x+y:x+y-mod;}

int sum[maxn],sum2[maxn],cnt[maxn],pw2[maxn+5];

int main()
{
    pw2[0]=1;
    rep(i,1,maxn) pw2[i]=2ll*pw2[i-1]%mod;

    int n; scanf("%d",&n);
    rep(i,1,n)
    {
        int x; scanf("%d",&x); 
        add(sum[x],x);
        add(sum2[x],1ll*x*x%mod);
        cnt[x]++; 
    }
    int pw10=1;
    rep(d,0,5)
    {
        per(i,0,maxn-1) if(i/pw10%10) 
        {
            add(sum[i-pw10],sum[i]);
            add(sum2[i-pw10],sum2[i]);
            cnt[i-pw10]+=cnt[i];
        }
        pw10*=10;
    }
    rep(i,0,maxn-1)
    {
        if(cnt[i]>=2) sum[i]=(1ll*sum[i]*sum[i]%mod*pw2[cnt[i]-2]+1ll*sum2[i]*pw2[cnt[i]-2])%mod;
        else sum[i]=1ll*sum[i]*sum[i]%mod;
    }
    pw10=1;
    rep(d,0,5)
    {
        rep(i,0,maxn-1) if(i/pw10%10) add(sum[i-pw10],mod-sum[i]);
        pw10*=10;
    }
    //printf("? %d\n",sum[121]);
    ll ans=0;
    rep(i,0,maxn-1) ans^=1ll*sum[i]*i;
    printf("%lld\n",ans);
    return 0;
}