#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 500000
#define mod 998244353
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int l[maxn+5],r[maxn+5],x[maxn+5];

int solve(int n,int layer,int m)
{
    vi cnt(n+2,0);
    rep(i,1,m) if(x[i]&(1<<layer)) cnt[l[i]]++,cnt[r[i]+1]--;
    rep(i,1,n+1) cnt[i]+=cnt[i-1];
    vi prev(n+2,0),dp(n+2,0),ps(n+2,0);
    rep(i,1,m) if((x[i]&(1<<layer))==0) chmax(prev[r[i]+1],l[i]);
    rep(i,1,n+1) chmax(prev[i],prev[i-1]);

    dp[0]=ps[0]=1;
    rep(i,1,n+1)
    {
        if(cnt[i]==0) 
        {
            if(prev[i]==0) dp[i]=ps[i-1];
            else dp[i]=(ps[i-1]-ps[prev[i]-1]+mod)%mod;
        }
        ps[i]=(ps[i-1]+dp[i])%mod;
    }
    return dp[n+1];
}

int main()
{
    int n,k,m; scanf("%d%d%d",&n,&k,&m);
    rep(i,1,m) scanf("%d%d%d",&l[i],&r[i],&x[i]);
    ll ans=1;
    rep(i,0,k-1) ans=ans*solve(n,i,m)%mod;
    printf("%lld\n",ans);
    return 0;
}