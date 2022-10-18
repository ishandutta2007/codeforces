#include<bits/stdc++.h>

typedef long long ll;
#define int ll

using namespace std;

const int N=2e5+100,MOD=998244353;

int ppow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)
            res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}

int rev(int x)
{
    return ppow(x,MOD-2);
}

int mod(int x)
{
    x%=MOD;
    if(x<MOD)
        x+=MOD;
    x%=MOD;
    return x;
}

int suff_prod[N],suff_sum[N];

const int C=4;

#define fun(name,code) \
int get_##name(int l,int r) \
{ \
    int name=code; \
    return name; \
}
//    cout<<#name<<"("<<l<<","<<r<<")="<<name*C%MOD<<"/"<<C<<"\n"; \

fun(prod,suff_prod[l]*rev(suff_prod[r+1])%MOD)

fun(sum,mod(suff_sum[l]-get_prod(l,r)*(suff_sum[r+1]-1)))

fun(ans,mod(get_sum(l,r)*rev(get_prod(l,r))-1))

int p[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,q;
    cin>>n>>q;
    int rev100=rev(100);
    for(int i=1;i<=n;i++)
        cin>>p[i],p[i]=p[i]*rev100%MOD;
    suff_prod[n+1]=1;
    for(int i=n;i>=1;i--)
        suff_prod[i]=suff_prod[i+1]*p[i]%MOD;
    suff_sum[n+1]=1;
    for(int i=n;i>=1;i--)
        suff_sum[i]=(p[i]*suff_sum[i+1]+1)%MOD;
    set<int> s{1,n+1};
    int ans=get_ans(1,n);
    while(q--)
    {
        int u;
        cin>>u;
        if(s.count(u))
        {
            s.erase(u);
            int l=*prev(s.upper_bound(u)),
                r=*s.upper_bound(u);
            ans+=get_ans(l,r-1);
            ans-=get_ans(l,u-1);
            ans-=get_ans(u,r-1);
        }
        else
        {
            int l=*prev(s.upper_bound(u)),
                r=*s.upper_bound(u);
            s.insert(u);
            ans-=get_ans(l,r-1);
            ans+=get_ans(l,u-1);
            ans+=get_ans(u,r-1);
        }
        ans=mod(ans);
        cout<<ans<<"\n";
    }
}