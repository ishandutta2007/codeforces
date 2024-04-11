#include <bits/stdc++.h>
#define Maxn 4000007
#define modp 1000000007
struct node1
{
    int l,r;
    int tag,res;
} tree1[Maxn];
struct node2
{
    int l,r;
    long long tag,res;
} tree2[Maxn];
int n,q;
int a[Maxn];
int prime[Maxn],tmp[Maxn],m=0;
int power(int a,int b)
{
    int res=1,now=a,left=b;
    while (left>0)
    {
        if (left%2==1) res=(1LL*res*now)%modp;
        left/=2;
        now=(1LL*now*now)%modp;
    }
    return res;
}
bool check_prime(int x)
{
    for (int i=2;i*i<=x;i++)
        if (x%i==0) return false;
    return true;
}
void build1(int node,int lx,int rx)
{
    tree1[node].l=lx,tree1[node].r=rx;
    tree1[node].tag=1;
    if (lx==rx)
    {
        tree1[node].res=a[lx];
        return;
    }
    int mid=(lx+rx)/2;
    build1(node*2,lx,mid);
    build1(node*2+1,mid+1,rx);
    tree1[node].res=(1LL*tree1[node*2].res*tree1[node*2+1].res)%modp;
}
void push_down1(int node)
{
    if (tree1[node].tag==1) return;
    tree1[node*2].tag=(1LL*tree1[node*2].tag*tree1[node].tag)%modp;
    tree1[node*2].res=(1LL*tree1[node*2].res*power(tree1[node].tag,tree1[node*2].r-tree1[node*2].l+1))%modp;
    tree1[node*2+1].tag=(1LL*tree1[node*2+1].tag*tree1[node].tag)%modp;
    tree1[node*2+1].res=(1LL*tree1[node*2+1].res*power(tree1[node].tag,tree1[node*2+1].r-tree1[node*2+1].l+1))%modp;
    tree1[node].tag=1;
}
void update1(int node,int lx,int rx,int val)
{
    if (tree1[node].l>rx) return;
    if (tree1[node].r<lx) return;
    push_down1(node);
    if (tree1[node].l>=lx&&tree1[node].r<=rx)
    {
        tree1[node].tag=(1LL*tree1[node].tag*val)%modp;
        tree1[node].res=(1LL*tree1[node].res*power(val,tree1[node].r-tree1[node].l+1))%modp;
        return;
    }
    update1(node*2,lx,rx,val);
    update1(node*2+1,lx,rx,val);
    tree1[node].res=(1LL*tree1[node*2].res*tree1[node*2+1].res)%modp;
}
int query1(int node,int lx,int rx)
{
    if (tree1[node].l>rx) return 1;
    if (tree1[node].r<lx) return 1;
    push_down1(node);
    if (tree1[node].l>=lx&&tree1[node].r<=rx) return tree1[node].res;
    return (1LL*query1(node*2,lx,rx)*query1(node*2+1,lx,rx))%modp;
}
void build2(int node,int lx,int rx)
{
    tree2[node].l=lx,tree2[node].r=rx;
    tree2[node].tag=0LL;
    if (lx==rx)
    {
        tree2[node].res=0LL;
        for (int i=1;i<=m;i++)
            if (a[lx]%prime[i]==0) tree2[node].res|=(1LL<<(i-1));
        return;
    }
    int mid=(lx+rx)/2;
    build2(node*2,lx,mid);
    build2(node*2+1,mid+1,rx);
    tree2[node].res=(tree2[node*2].res|tree2[node*2+1].res);
}
void push_down2(int node)
{
    if (tree2[node].tag==0LL) return;
    tree2[node*2].tag|=tree2[node].tag;
    tree2[node*2].res|=tree2[node].tag;
    tree2[node*2+1].tag|=tree2[node].tag;
    tree2[node*2+1].res|=tree2[node].tag;
    tree2[node].tag=0LL;
}
void update2(int node,int lx,int rx,long long val)
{
    if (tree2[node].l>rx) return;
    if (tree2[node].r<lx) return;
    push_down2(node);
    if (tree2[node].l>=lx&&tree2[node].r<=rx)
    {
        tree2[node].tag|=val;
        tree2[node].res|=val;
        return;
    }
    update2(node*2,lx,rx,val);
    update2(node*2+1,lx,rx,val);
    tree2[node].res=(tree2[node*2].res|tree2[node*2+1].res);
}
long long query2(int node,int lx,int rx)
{
    if (tree2[node].l>rx) return 0LL;
    if (tree2[node].r<lx) return 0LL;
    push_down2(node);
    if (tree2[node].l>=lx&&tree2[node].r<=rx) return tree2[node].res;
    return (query2(node*2,lx,rx)|query2(node*2+1,lx,rx));
}
int main()
{
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=2;i<=300;i++)
        if (check_prime(i)) 
        {
            prime[++m]=i;
            tmp[m]=(1LL*(i-1)*power(i,modp-2))%modp;
        }
    build1(1,1,n);
    build2(1,1,n);
    while (q--)
    {
        char ch=getchar();
        while (ch!='M'&&ch!='T') ch=getchar();
        int op;
        if (ch=='M') op=1; else op=2;
        while (ch!=' ') ch=getchar();
        if (op==1)
        {
            int lx,rx,x;
            scanf("%d%d%d",&lx,&rx,&x);
            long long now=0;
            for (int i=1;i<=m;i++)
                if (x%prime[i]==0) now|=(1LL<<(i-1));
            update1(1,lx,rx,x);
            update2(1,lx,rx,now);
        } else
        {
            int lx,rx;
            scanf("%d%d",&lx,&rx);
            int ans=query1(1,lx,rx);
            long long now=query2(1,lx,rx);
            for (int i=1;i<=m;i++)
                if (now&(1LL<<(i-1))) ans=(1LL*ans*tmp[i])%modp;
            printf("%d\n",ans);
        }
    }
    return 0;
}