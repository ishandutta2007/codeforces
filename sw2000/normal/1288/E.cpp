#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=3e5+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const ll linf=0x3f3f3f3f3f3f3f3f;

int n,m,sum[maxn<<3],pos[maxn],ans0[maxn],ans[maxn];

void build(int o=1,int l=1,int r=n+m)
{
    if(l==r)
    {
        if(l>m)sum[o]=1;
        else
        {
            sum[o]=0;
        }
        return;
    }
    int mid=l+r>>1,lo=o<<1,ro=lo|1;
    build(lo,l,mid);
    build(ro,mid+1,r);
    sum[o]=sum[lo]+sum[ro];
}

void add(int p,int v,int o=1,int l=1,int r=n+m)
{
    if(l==r)
    {
        sum[o]+=v;
        return;
    }

    int mid=l+r>>1,lo=o<<1,ro=lo|1;
    if(p<=mid)add(p,v,lo,l,mid);
    else add(p,v,ro,mid+1,r);
    sum[o]=sum[lo]+sum[ro];
}

int query(int ql,int qr,int o=1,int l=1,int r=n+m)
{
    if(ql<=l&&r<=qr)
    {
        return sum[o];
    }
    int mid=l+r>>1,lo=o<<1,ro=lo|1;
    int ret=0;
    if(mid>=ql)ret+=query(ql,qr,lo,l,mid);
    if(mid<qr)ret+=query(ql,qr,ro,mid+1,r);
    return ret;
}
int main()
{
//    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        pos[i]=i+m;
        ans0[i]=i;
        ans[i]=i;
    }
    build();
    for(int i=0;i<m;i++)
    {
        int a;scanf("%d",&a);
        ans[a]=1;

        add(pos[a],-1);
        ans0[a]=max(ans0[a],n-query(pos[a],n+m));
        pos[a]=m-i;
        add(pos[a],1);
    }

    for(int i=1;i<=n;i++)
    {
        ans0[i]=max(ans0[i],n+ 1-query(pos[i],n+m));
    }


    for(int i=1;i<=n;i++)
    {
        printf("%d %d\n",ans[i],ans0[i]);
    }
    return 0;
}