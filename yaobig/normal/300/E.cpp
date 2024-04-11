#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxA 10000000
#define maxn 1000000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int p[maxA+5],lp[maxA+5];
ll cnt[maxA+5];

bool check(ll x,int p)
{
    ll res=0;
    while(x) x/=p,res+=x;
    return res>=cnt[p];
}

ll lb(ll l,ll r,int p)
{
    r++;
    while(l<r)
    {
        ll mid=(l+r)>>1;
        if(check(mid,p)) r=mid;
        else l=mid+1;
    }
    return l;
}

int main()
{
    rep(i,2,maxA)
    {
        if(lp[i]) continue;
        for(int j=i;j<=maxA;j+=i) lp[j]=i;
    }
    int n; scanf("%d",&n);
    ll s=0;
    rep(i,1,n)
    {
        int x; scanf("%d",&x); cnt[x]++; s+=x;
    }
    per(i,1,maxA) cnt[i]+=cnt[i+1];
    per(i,2,maxA)
    {
        if(i!=lp[i]) cnt[lp[i]]+=cnt[i];
        cnt[i/lp[i]]+=cnt[i];
    }
    ll ans=1;
    rep(i,2,maxA) if(i==lp[i]) ans=max(ans,lb(1,s,i));
    printf("%I64d\n",ans);
    return 0;
}