#include<bits/stdc++.h>
using namespace std;
const int N=200005;
char s[N];
struct tree
{
    int mx,mi,lmx,rmx,sum,ans;
    void init(int x) 
	{
        mx=x,mi=x,lmx=-x,rmx=-x,sum=x,ans=0;
    };
}tr[N<<2];
void pushup(int x) 
{
    tr[x].mx=max(tr[x<<1].mx,tr[x<<1|1].mx+tr[x<<1].sum);
    tr[x].mi=min(tr[x<<1].mi,tr[x<<1|1].mi+tr[x<<1].sum);
    tr[x].lmx=max(tr[x<<1].lmx,tr[x<<1|1].lmx-tr[x<<1].sum);
    tr[x].lmx=max(tr[x].lmx,tr[x<<1].mx-2*(tr[x<<1|1].mi+tr[x<<1].sum));
    tr[x].rmx=max(tr[x<<1].rmx,tr[x<<1|1].rmx-tr[x<<1].sum);
    tr[x].rmx=max(tr[x].rmx,tr[x<<1|1].mx-2*tr[x<<1].mi+tr[x<<1].sum);
    tr[x].sum=tr[x<<1].sum+tr[x<<1|1].sum;
    tr[x].ans=max(tr[x<<1].ans,tr[x<<1|1].ans);
    tr[x].ans=max(tr[x].ans,max(tr[x<<1].lmx+tr[x<<1|1].mx+tr[x<<1].sum,tr[x<<1|1].rmx+tr[x<<1].mx-tr[x<<1].sum));
}
void build(int x,int l,int r)
 {
    if(l==r) 
	{
        tr[x].init(s[l]=='('?1:-1);
        return;
    }
    int mid=l+r>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}
void update(int x,int l,int r,int pos) 
{
    if(l==r) 
	{
        tr[x].init(s[l]=='('?1:-1);
        return;
    }
    int mid=l+r>>1;
    if(pos<=mid) update(x<<1,l,mid,pos);
    else update(x<<1|1,mid+1,r,pos);
    pushup(x);
}
int main() 
{
    int n,t;
    scanf("%d%d",&n,&t);
    n=2*n-2;
    int u,v;
    scanf("%s",s+1);
    build(1,1,n);
    printf("%d\n",tr[1].ans);
    while(t--) 
	{
        scanf("%d%d",&u,&v);
        swap(s[u],s[v]);
        update(1,1,n,u);
        update(1,1,n,v);
        printf("%d\n",tr[1].ans);
    }
    return 0;
}