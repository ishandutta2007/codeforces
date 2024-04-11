#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 400005
#define MAXM 1200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,tot,sz,a[MAXN];
int type[MAXN],x[MAXN],y[MAXN],l[MAXN],r[MAXN];
P points[MAXM];
int nxt[21][MAXM];
int st[MAXN];
struct segtree
{
    int mini[4*MAXM];
    int lazy[4*MAXM];
    void pushup(int k)
    {
        mini[k]=min(mini[k*2],mini[k*2+1]);
    }
    void apply(int k,int p)
    {
        mini[k]=lazy[k]=p;
    }
    void pushdown(int k)
    {
        if(lazy[k]==-1) return;
        for(int i=k*2;i<=k*2+1;i++) apply(i,lazy[k]);
        lazy[k]=-1;
    }
    void build(int k,int l,int r)
    {
        lazy[k]=-1;
        if(l==r) {mini[k]=tot+1; return;}
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y,int p)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y) {apply(k,p); return;}
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,p); update(k*2+1,mid+1,r,x,y,p);
        pushup(k);
    }
    int query(int k,int l,int r,int pos)
    {
        if(l==r) return mini[k];
        int mid=(l+r)/2;
        pushdown(k);
        if(pos<=mid) return query(k*2,l,mid,pos); else return query(k*2+1,mid+1,r,pos);
    }
}seg;
void build()
{
    nxt[0][tot+1]=tot+1;
    for(int i=0;i<20;i++)
        for(int j=1;j<=tot+1;j++)
            nxt[i+1][j]=nxt[i][nxt[i][j]];
}
int solve(int state,int qt)
{
    //printf("istate=%d qt=%d\n",state,qt);
    for(int i=20;i>=0;i--)
        if(points[nxt[i][state]].F<=qt)
            state=nxt[i][state];
    //printf("estate=%d\n",state);
    return points[state].S;
}
vector<int> dis;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        dis.push_back(a[i]); points[++tot]=P(0,a[i]);
    }
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        scanf("%d",&type[i]);
        if(type[i]==1)
        {
            scanf("%d%d",&x[i],&y[i]);
            dis.push_back(y[i]); l[i]=r[i]=tot+1;
            points[++tot]=P(i,y[i]);
        }
        else if(type[i]==2) scanf("%d",&x[i]);
        else 
        {
            scanf("%d%d",&x[i],&y[i]);
            l[i]=tot+1; r[i]=tot+2;
            points[++tot]=P(i,x[i]-1); points[++tot]=P(i,y[i]+1);
            dis.push_back(x[i]-1); dis.push_back(y[i]+1);
        }
    }
    points[tot+1]=P(q+1,0);
    sort(dis.begin(),dis.end());
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    sz=(int)dis.size();
    seg.build(1,1,sz);
    for(int i=q;i>=1;i--)
    {
        if(type[i]==1)
        {
            int id=lower_bound(dis.begin(),dis.end(),y[i])-dis.begin()+1;
            int pos=l[i];
            nxt[0][pos]=seg.query(1,1,sz,id);
        }
        else if(type[i]==3)
        {
            int len=(y[i]-x[i])/2;
            int id=lower_bound(dis.begin(),dis.end(),x[i]-1)-dis.begin()+1;
            nxt[0][l[i]]=seg.query(1,1,sz,id);
            id=lower_bound(dis.begin(),dis.end(),y[i]+1)-dis.begin()+1;
            nxt[0][r[i]]=seg.query(1,1,sz,id);
            int lid=lower_bound(dis.begin(),dis.end(),x[i])-dis.begin()+1;
            int rid=upper_bound(dis.begin(),dis.end(),x[i]+len)-dis.begin();
            //printf("i=%d lid=%d rid=%d to=%d\n",i,lid,rid,l[i]);
            seg.update(1,1,sz,lid,rid,l[i]);
            lid=lower_bound(dis.begin(),dis.end(),y[i]-len)-dis.begin()+1;
            rid=upper_bound(dis.begin(),dis.end(),y[i])-dis.begin();
            //printf("i=%d lid=%d rid=%d to=%d\n",i,lid,rid,r[i]);
            seg.update(1,1,sz,lid,rid,r[i]);
        }
    }
    for(int i=1;i<=n;i++) 
    {
        int id=lower_bound(dis.begin(),dis.end(),a[i])-dis.begin()+1;
        //printf("i=%d id=%d\n",i,id);
        nxt[0][i]=seg.query(1,1,sz,id);
    }
    //for(int i=1;i<=tot+1;i++) printf("i=%d F=%d S=%d nxt=%d\n",i,points[i].F,points[i].S,nxt[0][i]);
    //printf("tot=%d\n",tot);
    build();
    for(int i=1;i<=n;i++) st[i]=i;
    for(int i=1;i<=q;i++)
    {
        if(type[i]==1) st[x[i]]=l[i];
        else if(type[i]==2)
            printf("%d\n",solve(st[x[i]],i));
    }
    return 0;
}