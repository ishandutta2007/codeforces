#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 100000
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int cnt[maxn+5];
vi fac[maxn+5];

ll qp(ll a,int k)
{
    assert(k>=0);
    ll res=1;
    while(k)
    {
        if(k&1) res=res*a%mod;
        a=a*a%mod;
        k>>=1;
    }
    return res;
}


int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n)
    {
        int x; scanf("%d",&x);
        cnt[x]++;
    }
    rep(i,1,maxn) cnt[i]+=cnt[i-1];
    rep(i,1,maxn) for(int j=i;j<=maxn;j+=i) fac[j].pb(i);
    ll ans=0;
    rep(x,1,maxn)
    {
        int l=fac[x].size();
        if(cnt[fac[x][0]-1]) continue;
        if(cnt[maxn]-cnt[fac[x].back()-1]==0) continue;
        ll tmp=cnt[maxn]-cnt[fac[x].back()-1];
        tmp=(qp(l,tmp)-qp(l-1,tmp)+mod)%mod;
        rep(i,1,l-1)
        {
            tmp=tmp*(qp(i,cnt[fac[x][i]-1]-cnt[fac[x][i-1]-1]))%mod;
        }
        ans+=tmp;
    }
    printf("%I64d\n",ans%mod);
    return 0;
}