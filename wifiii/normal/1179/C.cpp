
#include <bits/stdc++.h>
typedef long long ll;
//typedef unsigned long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)
const int maxn = 1000000;
int mn[4000005],lz[4000005];
void update(int L,int R,int v,int rt,int l,int r)
{
    if(L<=l && r<=R)
    {
        lz[rt]+=v;
        mn[rt]+=v;
        return;
    }
    if(lz[rt])
    {
        lz[rt<<1]+=lz[rt],lz[rt<<1|1]+=lz[rt],
        mn[rt<<1]+=lz[rt],mn[rt<<1|1]+=lz[rt];
        lz[rt]=0;
    }
    int m=(l+r)/2;
    if(L<=m) update(L,R,v,rt<<1,l,m);
    if(m< R) update(L,R,v,rt<<1|1,m+1,r);
    mn[rt]=min(mn[rt<<1],mn[rt<<1|1]);
}
int query(int rt,int l,int r)
{
    if(l==r) return l;
    int m=(l+r)/2;
    if(lz[rt])
    {
        lz[rt<<1]+=lz[rt],lz[rt<<1|1]+=lz[rt],
        mn[rt<<1]+=lz[rt],mn[rt<<1|1]+=lz[rt];
        lz[rt]=0;
    }
    if(mn[rt<<1|1]<0) return query(rt<<1|1,m+1,r);
    return query(rt<<1,l,m);
}
int a[300005],b[300005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    scanf("%d%d",&n,&m);
    forii
    {
        scanf("%d",a+i);
        update(1,a[i],-1,1,1,maxn);
    }
    forij
    {
        scanf("%d",b+i);
        update(1,b[i],1,1,1,maxn);
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if(x==1)
        {
            update(1,a[y],1,1,1,maxn);
            a[y]=z;
            update(1,a[y],-1,1,1,maxn);
        }
        if(x==2)
        {
            update(1,b[y],-1,1,1,maxn);
            b[y]=z;
            update(1,b[y],1,1,1,maxn);
        }
        if(mn[1]>=0) puts("-1");
        else printf("%d\n",query(1,1,maxn));
    }
}