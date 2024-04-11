#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l+r>>1)
#define lo (o<<1)
#define ro (o<<1|1)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<double,double> pii;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=3e5+10;
const ll mod=1e9+7;
const double PI=acos(0)*2;

int inline lb(int x)
{
    return x&(-x);
}
int c[maxn];

vi v[maxn];
int ans,n,arr[maxn],m,mi[maxn<<2],sum[maxn<<2],lazy[maxn<<2];
void add_c(int p)
{
    for(;p<=n;p+=lb(p))
    {
        c[p]++;
    }
}
int query(int p)
{
    int ret=0;
    for(;p;p-=lb(p))
    {
        ret+=c[p];
    }
    return ret;
}
struct A
{
    int l,r,id,ans;
}q[maxn];

void pushdown(int o,int l,int r)
{
    if(!lazy[o])return;
    mi[lo]+=lazy[o];
    mi[ro]+=lazy[o];
    lazy[lo]+=lazy[o];
    lazy[ro]+=lazy[o];
    lazy[o]=0;
}
void build(int o=1,int l=1,int r=n)
{
    mi[o]=inf;
    if(l==r)
    {
        return;
    }
    build(lo,l,mid);
    build(ro,mid+1,r);
}
void add(int ql,int qr,int v,int o=1,int l=1,int r=n)
{
    if(ql<=l&&r<=qr)
    {
        mi[o]+=v;
        lazy[o]+=v;
        return;
    }
    pushdown(o,l,r);
    if(ql<=mid)add(ql,qr,v,lo,l,mid);
    if(qr>mid)add(ql,qr,v,ro,mid+1,r);
    mi[o]=min(mi[lo],mi[ro]);
}
int pos(int o=1,int l=1,int r=n)
{
    if(l==r)return l;
    pushdown(o,l,r);
    if(mi[lo]<=0)return pos(lo,l,mid);
    else return pos(ro,mid+1,r);
}
int main()
{
//    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",arr+i);
        if(arr[i]>i)arr[i]=inf;
        else arr[i]=i-arr[i];
    }

//    for(int i=1;i<=n;i++)cout<<arr[i]<<' ';
//    cout<<endl;
    build();
    for(int i=1;i<=m;i++)
    {
        int a,b;scanf("%d%d",&a,&b);
        q[i]={a+1,n-b,i};
    }
    sort(q+1,q+m+1,[](A a,A b){
         return a.l>b.l;
    });

    int st=1;
    for(int i=n;i;i--)
    {
        add(i,i,arr[i]-inf);
        while(mi[1]<=0)
        {
            int p=pos();
            add_c(p);
//            cout<<i<<' '<<p<<endl;
            add(p,p,inf);
            if(p!=n)add(p+1,n,-1);
        }
        while(i==q[st].l)
        {
            q[st].ans=query(q[st].r);
            st++;
        }
    }

    sort(q+1,q+m+1,[](A a,A b){return a.id<b.id;});
    for(int i=1;i<=m;i++)
        printf("%d\n",q[i].ans);
    return 0;
}