#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[maxn+5];
vi vec;

struct treearr
{
    int a[maxn+5];
    void add(int x,int v)
    {
        for(;x<=maxn;x+=x&-x) a[x]+=v;
    }
    int ask(int x)
    {
        int res=0;
        for(;x;x-=x&-x) res+=a[x];
        return res;
    }
}tb,te;

int main()
{
    int n; ll k; scanf("%d%I64d",&n,&k);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n) vec.pb(a[i]);
    sort(vec.begin(),vec.end()); vec.erase(unique(vec.begin(),vec.end()),vec.end());
    rep(i,1,n) a[i]=lower_bound(vec.begin(),vec.end(),a[i])-vec.begin()+1;
    ll sum=0;
    per(i,2,n) sum+=te.ask(a[i]-1),te.add(a[i],1);
    sum+=te.ask(a[1]-1),tb.add(a[1],1);
    if(sum<=k) printf("%I64d\n",1ll*n*(n-1)/2);
    else
    {
        int ptr=2;
        ll ans=0;
        rep(i,1,n)
        {
            while(ptr<=n && sum>k)
            {
                sum-=i-tb.ask(a[ptr])+te.ask(a[ptr]-1);
                te.add(a[ptr++],-1);
            }
            ans+=n-ptr+1;
            if(i<n) sum+=i-tb.ask(a[i+1])+te.ask(a[i+1]-1),tb.add(a[i+1],1);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}