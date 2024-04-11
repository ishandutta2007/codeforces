#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 200000
#define inf 0x3f3f3f3f
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int lowbit(int x) {return x&-x;}
int a[maxn+5];
int w[maxn+5],wa[maxn+5];
ll t[maxn+5],ta[maxn+5];

void add(ll a[],int x,int v)
{
    for(;x<=maxn;x+=lowbit(x)) a[x]+=v;
}
ll ask(ll a[],int x)
{
    ll res=0;
    for(;x;x-=lowbit(x)) res+=a[x];
    return res;
}

int findp(int l,int r)
{
    ll S0=ask(t,l-1);
    ll S=ask(t,r)-S0;
    r++;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if((ask(t,mid)-S0)*2>=S) r=mid;
        else l=mid+1;
    }
    return l;
}


int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n) scanf("%d",&w[i]);
    rep(i,1,n) wa[i]=1ll*w[i]*(a[i]-i)%mod;
    rep(i,1,n) add(t,i,w[i]);
    rep(i,1,n) add(ta,i,wa[i]);

    while(m--)
    {
        int x,y; scanf("%d%d",&x,&y);
        if(x<0)
        {
            int id=-x,nw=y,nwa=1ll*nw*(a[id]-id)%mod;
            add(t,id,nw-w[id]);
            add(ta,id,nwa-wa[id]);
            w[id]=nw;
            wa[id]=nwa;
        }
        else
        {
            int l=x,r=y;
            int p=findp(l,r);
            ll S1=(ask(t,p)-ask(t,l-1))%mod;
            ll S2=(ask(t,r)-ask(t,p))%mod;
            ll Sa1=(ask(ta,p)-ask(ta,l-1))%mod;
            ll Sa2=(ask(ta,r)-ask(ta,p))%mod;
            ll ans=(S1*(a[p]-p)-Sa1+Sa2-S2*(a[p]-p))%mod;
            ans=(ans+mod)%mod;
            printf("%I64d\n",ans);
        }
    }
    return 0;
}