#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const ll linf=0x3f3f3f3f3f3f3f3f;

ll dp[maxn],mi[maxn<<2],qv,qp,ql,qr;
int n,k;
string s;

void build(int o=1,int l=1,int r=n)
{
    mi[o]=linf;
    if(l==r)return;
    int mid=(l+r)>>1,lo=o<<1,ro=o<<1|1;
    build(lo,l,mid);
    build(ro,mid+1,r);
}

void add(int o=1,int l=1,int r=n)
{
    if(l==r)
    {
        mi[o]=qv;
        return;
    }
    int mid=(l+r)>>1,lo=o<<1,ro=o<<1|1;
    if(qp<=mid)add(lo,l,mid);
    else add(ro,mid+1,r);

    mi[o]=min(mi[lo],mi[ro]);
}

ll query(int o=1,int l=1,int r=n)
{
    if(ql<=l&&r<=qr)
    {
        return mi[o];
    }
    int mid=(l+r)>>1,lo=o<<1,ro=o<<1|1;
    ll ret=linf;
    if(mid>=ql)ret=min(ret,query(lo,l,mid));
    if(mid<qr)ret=min(ret,query(ro,mid+1,r));
    return ret;
}

int main()
{
    scanf("%d%d",&n,&k);
    cin>>s;
    build();
    for(int i=1;i<=n;i++)
    {
        ql=max(1,i-k);
        qr=max(1,i-1);
        if(s[i-1]=='0')
        {
            dp[i]=dp[i-1]+i;
        }
        else
        {
            dp[i]=dp[max(0,i-k-1)]+i;
            qv=min(dp[i],query()+i);
            qp=i;
            add();
        }
        dp[i]=min(dp[i],query());
    }
    printf("%lld",dp[n]);
	return 0;
}