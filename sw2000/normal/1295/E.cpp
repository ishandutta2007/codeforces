#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l + r >> 1)
#define lo (o << 1)
#define ro (lo | 1)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};
 
int n,arr[maxn],brr[maxn];
ll pre[maxn],mi[maxn<<2],lazy[maxn<<2];

void build(int o=1,int l=1,int r=n)
{
    if(l==r)
    {
        mi[o]=pre[l];
        return;
    }
    build(lo,l,mid);
    build(ro,mid+1,r);
    mi[o]=min(mi[lo],mi[ro]);
}

void pushdown(int o,int l,int r)
{
    if(!lazy[o])return;
    lazy[lo]+=lazy[o];lazy[ro]+=lazy[o];
    mi[lo]+=lazy[o];mi[ro]+=lazy[o];
    lazy[o]=0;
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

int main()
{
    // freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",arr+i);
    for(int i=1;i<=n;i++)scanf("%d",brr+i);
    for(int i=1;i<=n;i++)
    {
        pre[arr[i]]=brr[i];
    }
    for(int i=1;i<=n;i++)pre[i]+=pre[i-1];
    build();
    ll ans=brr[1];
    for(int i=1;i<n;i++)
    {
        if(arr[i]!=1)add(1,arr[i]-1,brr[i]);
        add(arr[i],n,-brr[i]);
        ans=min(ans,mi[1]);
    }
    printf("%lld",ans);
    return 0;
}