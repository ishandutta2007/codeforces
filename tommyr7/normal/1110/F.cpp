#include <bits/stdc++.h>
#define Maxn 2000007
#define inf 10000000000000000LL
using namespace std;
int n,q;
int p[Maxn],w[Maxn],dfn[Maxn];
long long dis[Maxn];
pair<pair<int,int>,pair<int,int> >que[Maxn];
long long ans[Maxn];
int last[Maxn],pre[Maxn],other[Maxn],cnt=0;
bool flag[Maxn];
void insert(int u,int v)
{
    other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
}
void dfs(int u,int fa)
{
    dfn[u]=1;
    for (int q=last[u];q;q=pre[q])
    {
        int v=other[q];
        if (v!=fa)
        {
            dfs(v,u);
            dfn[u]+=dfn[v];
        }
    }
}
struct node
{
    int l,r;
    long long mn,tag;
} tree[Maxn];
void build(int node,int lx,int rx)
{
    tree[node].l=lx,tree[node].r=rx;
    tree[node].tag=0LL;
    if (lx==rx)
    {
        if (flag[lx]) tree[node].mn=dis[lx]; else tree[node].mn=inf;
        return;
    }
    int mid=(lx+rx)/2;
    build(node*2,lx,mid);
    build(node*2+1,mid+1,rx);
    tree[node].mn=min(tree[node*2].mn,tree[node*2+1].mn);
}
void push_down(int node)
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
    if (tree[node].l>rx) return;
    if (tree[node].r<lx) return;
    if (tree[node].l>=lx&&tree[node].r<=rx)
    {
        tree[node].mn+=val;
        tree[node].tag+=val;
        return;
    }
    push_down(node);
    update(node*2,lx,rx,val);
    update(node*2+1,lx,rx,val);
    tree[node].mn=min(tree[node*2].mn,tree[node*2+1].mn);
}
long long query(int node,int lx,int rx)
{
    push_down(node);
    if (tree[node].l>rx) return inf;
    if (tree[node].r<lx) return inf;
    if (tree[node].l>=lx&&tree[node].r<=rx) return tree[node].mn;
    return min(query(node*2,lx,rx),query(node*2+1,lx,rx));
}
int main()
{
    scanf("%d%d",&n,&q);
    for (int i=2;i<=n;i++)
    {
        scanf("%d%d",&p[i],&w[i]);
        dis[i]=dis[p[i]]+w[i];
        insert(p[i],i);
    }
    dfs(1,-1);
    for (int i=1;i<=n;i++)
    {
        if (dfn[i]==1) flag[i]=true;
        dfn[i]+=i-1;
    }
    for (int i=1;i<=q;i++)
    {
        scanf("%d%d%d",&que[i].first.first,&que[i].first.second,&que[i].second.first);
        que[i].second.second=i;
    }
    sort(que+1,que+q+1);
    build(1,1,n);
    int s=1;
    for (int i=1;i<=n;i++)
    {
        while (s<=q&&que[s].first.first==i)
        {
            ans[que[s].second.second]=query(1,que[s].first.second,que[s].second.first);
            ++s;
        }
        if (i!=n)
        {
            int now=i;
            while (now!=p[i+1])
            {
                update(1,1,n,-w[now]);
                update(1,now,dfn[now],2*w[now]);
                now=p[now];
            }
            update(1,1,n,w[i+1]);
            update(1,i+1,dfn[i+1],-2*w[i+1]);
        }
    }
    for (int i=1;i<=q;i++)
        printf("%lld\n",ans[i]);
    return 0;
}