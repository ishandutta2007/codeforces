#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
int n,ma=0,st,qr,ql,qv;
int mi[maxn<<2],ans[maxn],arr[maxn];

void build(int o=1,int l=1,int r=n)
{
    if(l==r)
    {
        mi[o]=arr[l];
        if(mi[o]>ma)
        {
            ma=mi[o];
            st=l;
        }
        return;
    }

    int lo=o<<1,ro=o<<1|1,mid=(l+r)>>1;
    build(lo,l,mid);
    build(ro,mid+1,r);
    mi[o]=min(mi[lo],mi[ro]);
}

int query(int o=1,int l=1,int r=n)
{
    if(mi[o]>qv)return 0;
    if(l==r)return l;
    int lo=o<<1,ro=o<<1|1,mid=(l+r)>>1;
    if(ql<=mid)
    {
        int v=query(lo,l,mid);
        if(v)return v;
    }
    return query(ro,mid+1,r);
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    build();

    ql=st+1,qv=(ma-1)/2;
    if(mi[1]>qv)
    {
        for(int i=0;i<n;i++)printf("-1 ");
        return 0;
    }

    int v=query();
    if(v)ans[st]=v-st;
    else
    {
        ql=1;
        ans[st]=query()+n-st;
    }

    for(int i=st-1;;i--)
    {
        if(!i)i=n;
        if(i==st)break;

        ql=i,qv=(arr[i]-1)/2;
        v=query();
        if(!v)
        {
            ql=1;
            v=query();
        }
        if(i==n)ans[i]=ans[1]+1;
        else ans[i]=ans[i+1]+1;
        if(v)ans[i]=min(ans[i],(v-i+n)%n);
    }

    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    return 0;
}