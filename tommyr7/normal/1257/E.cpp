#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int p,q,r;
int a[Maxn],b[Maxn],c[Maxn];
bool flag[Maxn][3];
struct node
{
    int lx,rx;
    int tag,mn;
} tree[Maxn*8];
void build(int node,int lx,int rx)
{
    tree[node].lx=lx,tree[node].rx=rx;
    tree[node].tag=0;
    tree[node].mn=0;
    if (lx==rx) return;
    int mid=(lx+rx)/2;
    build(node*2,lx,mid);
    build(node*2+1,mid+1,rx);
}
void pushdown(int node)
{
    if (!tree[node].tag) return;
    tree[node*2].tag+=tree[node].tag;
    tree[node*2].mn+=tree[node].tag;
    tree[node*2+1].tag+=tree[node].tag;
    tree[node*2+1].mn+=tree[node].tag;
    tree[node].tag=0;
}
void update(int node,int lx,int rx,int val)
{
    if (lx>rx) return;
    pushdown(node);
    if (tree[node].lx>=lx&&tree[node].rx<=rx)
    {
        tree[node].tag+=val;
        tree[node].mn+=val;
        return;
    }
    if (tree[node].lx>rx||tree[node].rx<lx) return;
    update(node*2,lx,rx,val);
    update(node*2+1,lx,rx,val);
    tree[node].mn=min(tree[node*2].mn,tree[node*2+1].mn);
}
int main()
{
    scanf("%d%d%d",&p,&q,&r);
    int n=p+q+r;
    memset(flag,false,sizeof(flag));
    for (int i=1;i<=p;i++)
    {
        scanf("%d",&a[i]);
        flag[a[i]][0]=true;
    }
    for (int i=1;i<=q;i++)
    {
        scanf("%d",&b[i]);
        flag[b[i]][1]=true;
    }
    for (int i=1;i<=r;i++)
    {
        scanf("%d",&c[i]);
        flag[c[i]][2]=true;
    }
    int ans=q+r;
    int tmp=q+r;
    build(1,1,n+1);
    for (int i=n-1;i>=0;i--)
    {
        if (flag[i+1][0]) ++tmp; else --tmp;
        if (flag[i+1][1]) update(1,1,i+1,1);
        if (flag[i+1][2]) update(1,i+2,n+1,1);
        pushdown(1);
        ans=min(ans,tmp+tree[1].mn);
    }
    printf("%d\n",ans);
    return 0;
}