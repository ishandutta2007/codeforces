#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PLL;
typedef pair<PLL,ll> PL3;
#define mp make_pair
#define fi first
#define se second
#define N 200010
int n,m,a[N],p[N],L,p0[N],p1[N],p2[N];
ll f[N*4],g[N*4],h[N*4];
void add(int p,int l,int r,int x,int y,int z)
{
    if(l==r-1)
    {
        g[p]+=y,f[p]+=0,h[p]+=z;
        return;
    }
    int mid=(l+r)/2;
    if(x<mid)add(p*2+1,l,mid,x,y,z);
    else add(p*2+2,mid,r,x,y,z);
    f[p]=f[p*2+1]+f[p*2+2]+h[p*2+1]*g[p*2+2];
    g[p]=g[p*2+1]+g[p*2+2];
    h[p]=h[p*2+1]+h[p*2+2];
}
PL3 ask(int p,int l,int r,int L,int R)
{
    if(L<=l&&r<=R)return mp(mp(f[p],g[p]),h[p]);
    int mid=(l+r)/2;
    if(mid<=L)return ask(p*2+2,mid,r,L,R);
    if(R<=mid)return ask(p*2+1,l,mid,L,R);
    PL3 pl=ask(p*2+1,l,mid,L,R),pr=ask(p*2+2,mid,r,L,R);
    return mp(mp(pl.fi.fi+pr.fi.fi+pr.fi.se*pl.se,pl.fi.se+pr.fi.se),pl.se+pr.se);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",a+i),p[L++]=a[i];
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",p0+i,p1+i,p2+i);
        if(p0[i]==1)a[p1[i]-1]+=p2[i],p[L++]=a[p1[i]-1];
    }
    for(int i=m-1;i>=0;i--)
        if(p0[i]==1)a[p1[i]-1]-=p2[i];
    sort(p,p+L),L=unique(p,p+L)-p;
    for(int i=0;i<n;i++)
        add(0,0,L,lower_bound(p,p+L,a[i])-p,a[i],1);
    for(int i=0;i<m;i++)
    {
        int x=p1[i],y=p2[i];
        if(p0[i]==1)
        {
            x--;
            add(0,0,L,lower_bound(p,p+L,a[x])-p,-a[x],-1);
            a[x]+=y;
            add(0,0,L,lower_bound(p,p+L,a[x])-p,a[x],1);
        }else
        {
            int pl=lower_bound(p,p+L,x)-p,pr=lower_bound(p,p+L,y+1)-p;
            if(pl>=pr){puts("0");continue;}
            PL3 S=ask(0,0,L,pl,pr);
            printf("%I64d\n",S.fi.fi*2-(S.se-1)*S.fi.se);
        }
    }
    return 0;
}