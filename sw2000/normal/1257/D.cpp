#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
const int inf=0x3f3f3f3f;
int n,m,ql,qr;

struct M
{
    int a,b;
    bool operator<(const int x)const
    {
        return a<x;
    }
}arr[maxn];

bool operator<(M a,M b)
{
    return a.a<b.a;
}

int man[maxn<<2],mam[maxn<<2];

void build(int o=1,int l=1,int r=n)
{
    if(l==r)
    {
        scanf("%d",&man[o]);
        return;
    }
    int lo=o<<1,ro=lo|1,mid=l+r>>1;
    build(lo,l,mid);
    build(ro,mid+1,r);
    man[o]=max(man[lo],man[ro]);
}

void buildm(int o=1,int l=1,int r=m)
{
    if(l==r)
    {
        mam[o]=arr[l].b;
        return;
    }
    int lo=o<<1,ro=lo|1,mid=(l+r)>>1;
    buildm(lo,l,mid);
    buildm(ro,mid+1,r);
    mam[o]=max(mam[lo],mam[ro]);
}

int query(int o=1,int l=1,int r=n)
{
    if(ql<=l&&r<=qr)
    {
        return man[o];
    }
    int lo=o<<1,ro=lo|1,mid=(l+r)>>1;
    int a=0,b=0;
    if(ql<=mid)a=query(lo,l,mid);
    if(qr>mid)b=query(ro,mid+1,r);
    return max(a,b);
}

int querym(int o=1,int l=1,int r=m)
{
    if(ql<=l&&r<=qr)
    {
        return mam[o];
    }
    int lo=o<<1,ro=lo|1,mid=(l+r)>>1;
    int a=0,b=0;
    if(ql<=mid)a=querym(lo,l,mid);
    if(qr>mid)b=querym(ro,mid+1,r);
    return max(a,b);
}

bool can(int l,int r)
{
    ql=l,qr=r;
    int ma=query();
    ql=lower_bound(arr+1,arr+m+1,(M){ma,0})-arr;
    qr=m;
    int mm=querym();
    if(mm>=r-l+1)return 1;
    return 0;
}

int main()
{
    //freopen("in.txt","r",stdin);
	int t;
	cin>>t;
	while(t--)
    {
        scanf("%d",&n);
        build();
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&arr[i].a,&arr[i].b);
        }
        sort(arr+1,arr+m+1);
        buildm();
        if(man[1]>arr[m].a)
        {
            puts("-1");
            continue;
        }
        int st=1,ans=0;
        while(st<=n)
        {
            int l=st,r=n+1;
            while(l!=r-1)
            {
                int mid=l+r>>1;
                if(can(st,mid))l=mid;
                else r=mid;
            }
            ans++;
            st=l+1;
        }
        printf("%d\n",ans);
    }
	return 0;
}