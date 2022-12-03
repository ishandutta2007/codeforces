#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<sstream>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct node
{
    int val;
    node * ch[2]; 
};
node * root[100005];
node * new_node()
{
    static node a[2000005];
    static int top=0;
    return &a[top++];
}
struct edge
{
    int y;
    edge * next;
};
edge * li[100005];
edge * new_edge()
{
    static edge a[100005];
    static int top=0;
    return &a[top++];
}
void insert_edge(int x,int y)
{
    edge * t=new_edge();
    t->y=y;
    t->next=li[x];
    li[x]=t;
}
int up[100005];
int vis[100005];
int dfn[100005];
int size[100005];
int depth[100005];
int father[100005];
edge * prefer[100005];
void dfs1(int x)
{
    edge * t;
    int max_val=0;
    size[x]=1;
    for (t=li[x];t!=0;t=t->next)
    {
        depth[t->y]=depth[x]+1;
        dfs1(t->y);
        size[x]+=size[t->y];
        if (size[t->y]>max_val)
        {
            max_val=size[t->y];
            prefer[x]=t; 
        }
    }
}
void dfs2(int x)
{
    static int now=0;
    dfn[x]=now;
    vis[now]=x;
    now++;
    if (prefer[x]==0) return ;
    up[prefer[x]->y]=up[x];
    dfs2(prefer[x]->y);
    edge * t;
    for (t=li[x];t!=0;t=t->next)
    {
        if (prefer[x]==t) continue;
        up[t->y]=t->y;
        dfs2(t->y);
    }
}
void build_tree(node * &x,int l,int r)
{
    x=new_node();
    x->val=0;
    if (l==r-1)
    {
        return;
    }
    int mid=(l+r)/2;
    build_tree(x->ch[0],l,mid);
    build_tree(x->ch[1],mid,r);
}
void change(node * &x,int l,int r,int val)
{
    node * t=x;
    x=new_node();
    (*x)=(*t);
    x->val++;
    if (l==r-1)
    {
        return;
    }
    int mid=(l+r)/2;
    if (val<mid) change(x->ch[0],l,mid,val);
    else change(x->ch[1],mid,r,val);
}
int query(node * &x,int l,int r,int l0,int r0)
{
    if ((l0<=l)&&(r<=r0))
    {
        return x->val;
    }
    int mid=(l+r)/2;
    int ans=0;
    if (l0<mid) ans+=query(x->ch[0],l,mid,l0,r0);
    if (mid<r0) ans+=query(x->ch[1],mid,r,l0,r0);
    return ans;
}
int n;
void check_ans(int l,int r,int k,int i,int yy)
{
    for (;l<=r;)
    {
        int mid=(l+r)/2;
        int t=query(root[i],0,n,l,mid+1);
        t-=query(root[yy],0,n,l,mid+1);
        if ((mid-l+1)-t+k>0)
        {
            r=mid-1;
        }
        else
        {
            k+=(mid-l+1)-t;
            l=mid+1;
        }
    }
    printf("%d\n",vis[l]+1);
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%d",&n);
    int i;
    int center=0;
    for (i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        x--;
        father[i]=x;
        if (x==-1)
        {
            center=i;
            continue;
        }
        insert_edge(x,i);
    }
    depth[center]=0;
    dfs1(center);
    up[center]=center;
    dfs2(center);
    int m;
    scanf("%d",&m);
    build_tree(root[0],0,n);
    for (i=1;i<=m;i++)
    {
        root[i]=root[i-1];
        int oper;
        scanf("%d",&oper);
        if (oper==1)
        {
            int x;
            scanf("%d",&x);
            x--;
            change(root[i],0,n,dfn[x]);
        }
        else
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x--;
            y--;
            int k;
            scanf("%d",&k);
            int yy;
            scanf("%d",&yy);
            int tx=x;
            int ty=y;
            int sum=-1;
            int tot=0;
            k++;
            k-=query(root[i],0,n,dfn[x],dfn[x]+1);
            k+=query(root[yy],0,n,dfn[x],dfn[x]+1);
            tot-=query(root[i],0,n,dfn[y],dfn[y]+1);
            tot+=query(root[yy],0,n,dfn[y],dfn[y]+1);
            for (;;)
            {
                if (up[tx]==up[ty])
                {
                    if (depth[tx]<depth[ty]) swap(tx,ty);
                    sum+=dfn[tx]-dfn[ty]+1;
                    tot+=query(root[i],0,n,dfn[ty],dfn[tx]+1);
                    tot-=query(root[yy],0,n,dfn[ty],dfn[tx]+1);
                    break;
                }
                else
                {
                    if (depth[up[tx]]<depth[up[ty]])
                    {
                        swap(tx,ty);
                    }
                    sum+=dfn[tx]-dfn[up[tx]]+1;
                    tot+=query(root[i],0,n,dfn[up[tx]],dfn[tx]+1);
                    tot-=query(root[yy],0,n,dfn[up[tx]],dfn[tx]+1);
                    tx=father[up[tx]];
                }
            }
            if (sum-tot<k)
            {
                printf("-1\n");
            }
            else
            {
                tot+=query(root[i],0,n,dfn[y],dfn[y]+1);
                tot-=query(root[yy],0,n,dfn[y],dfn[y]+1);
                sum++;
                int top=ty;
                for (;;)
                {
                    if (up[x]==up[top])
                    {
                        int t=query(root[i],0,n,dfn[top],dfn[x]+1);
                        t-=query(root[yy],0,n,dfn[top],dfn[x]+1);
                        sum-=dfn[x]-dfn[top]+1;
                        k-=dfn[x]-dfn[top]+1-t;
                        tot-=t;
                        if (k<=0)
                        {
                            check_ans(dfn[top],dfn[x],k,i,yy);
                            break;
                        }
                        sum++;
                        t=query(root[i],0,n,dfn[top],dfn[top]+1);
                        t-=query(root[yy],0,n,dfn[top],dfn[top]+1);
                        k+=1-t;
                        tot+=t;
                        for (;;)
                        {
                            if (up[y]==up[top])
                            {
                                int t=query(root[i],0,n,dfn[top],dfn[y]+1);
                                t-=query(root[yy],0,n,dfn[top],dfn[y]+1);
                                sum-=dfn[y]-dfn[top]+1;
                                tot-=t;
                                if (sum-tot<k)
                                {
                                    /*
                                    sum+=dfn[y]-dfn[top]+1;
                                    tot+=t;
                                    */
                                    check_ans(dfn[top],dfn[y],(sum-tot)-k+1,i,yy);
                                    break;
                                }
                            }
                            else
                            {
                                int t=query(root[i],0,n,dfn[up[y]],dfn[y]+1);
                                t-=query(root[yy],0,n,dfn[up[y]],dfn[y]+1);
                                sum-=dfn[y]-dfn[up[y]]+1;
                                tot-=t;
                                if (sum-tot<k)
                                {
                                    /*
                                    sum+=dfn[y]-dfn[up[y]]+1;
                                    tot+=t;
                                    */
                                    check_ans(dfn[up[y]],dfn[y],(sum-tot)-k+1,i,yy);
                                    break;
                                }
                                y=father[up[y]];
                            }
                        }
                        break;
                    }
                    else
                    {
                        int t=query(root[i],0,n,dfn[up[x]],dfn[x]+1);
                        t-=query(root[yy],0,n,dfn[up[x]],dfn[x]+1);
                        sum-=dfn[x]-dfn[up[x]]+1;
                        k-=dfn[x]-dfn[up[x]]+1-t;
                        tot-=t;
                        if (k<=0)
                        {
                            check_ans(dfn[up[x]],dfn[x],k,i,yy);
                            break;
                        }
                        x=father[up[x]];
                    }
                }
            }
        }
    }
    return 0;
}