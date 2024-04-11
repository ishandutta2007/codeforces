#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
long long h[100005];
int c[100005];
bool visit[100005];
struct node
{
    int val;
    int id;
    node * child;
    node * left;
    node * right;
};
node * root;
node * d[100005];
node * new_node(int x,int y)
{
    static node a[200005];
    static int top=0;
    a[top].val=x;
    a[top].id=y;
    a[top].child=0;
    a[top].left=0;
    a[top].right=0;
    return &a[top++];
}
node * join(node * x,node * y)
{
    if (x==0) return y;
    if (y==0) return x;
    if ((x->val<y->val)||((x->val==y->val)&&(x->id>y->id)))
    {
        swap(x,y);
    }
    y->left=x;
    y->right=x->child;
    if (x->child!=0) x->child->left=y; 
    x->child=y;
    return x;
}
node * u(node * x)
{
    if (x==0) return x;
    x->left=0;
    node * y=x->right;
    x->right=0;
    if (y==0) return x;
    y->left=0;
    node * z=y->right;
    y->right=0;
    return join(u(z),join(x,y));
}
void delete_node(node * &x)
{
    if (x==root)
    {
        x=u(x->child);
        return;
    }
    else
    {
        if (x->left->child==x)
        {
            x->left->child=x->right;
        }
        else
        {
            x->left->right=x->right;
        }
        if (x->right!=0) x->right->left=x->left;
    }
    root=join(root,u(x->child));
}
void change_val(node * x)
{
    node * t=u(x->child);
    x->child=0;
    if (x==root)
    {
        root=join(t,x);
        return;
    }
    else
    {
        if (x->left->child==x)
        {
            x->left->child=x->right;
        }
        else
        {
            x->left->right=x->right;
        }
        if (x->right!=0) x->right->left=x->left;
        x->left=0;
        x->right=0;
    }
    root=join(x,join(root,t));
}
long long t[10005];
bool temp[10005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    long long maxh;
    int n,m;
    ios::sync_with_stdio(false);
    cin>>maxh>>n>>m;
    memset(visit,false,sizeof(visit));
    int k;
    cin>>k;
    int i;
    for (i=0;i<n;i++)
    {
        cin>>h[i]>>c[i];
        h[i]--;
    }
    for (i=0;i<k;i++)
    {
        t[i]=7199999999999999999ll;
    }
    t[0]=0;
    root=0;
    for (i=0;i<n;i++)
    {
        d[i]=new_node(c[i],i);
        if (h[i]%k==0)
        {
            root=join(root,d[i]);
            visit[i]=true;
        }
    }
    for (i=0;i<m;i++)
    {
        int oper;
        cin>>oper;
        if (oper==1)
        {
            long long x;
            cin>>x;
            int i;
            long long now=0;
            for (i=0;i<k;i++)
            {
                temp[i]=true;
            }
            for (i=0;i<k;i++)
            {
                t[(now+x)%k]=min(t[(now+x)%k],t[now]+x);
                now+=x;
                now%=k;
                temp[now]=false;
            }
            for (i=0;i<k;i++)
            {
                if (temp[i])
                {
                    now=i;
                    int j;
                    for (j=0;;j++)
                    {
                        t[(now+x)%k]=min(t[(now+x)%k],t[now]+x);
                        now+=x;
                        now%=k;
                        if (!temp[now]) break;
                        temp[now]=false;
                    }
                    int temp=j;
                    for (j=0;j<temp;j++)
                    {
                        t[(now+x)%k]=min(t[(now+x)%k],t[now]+x);
                        now+=x;
                        now%=k;
                    }
                }
            }
            for (i=0;i<n;i++)
            {
                if (visit[i]) continue;
                if (h[i]>=t[h[i]%k])
                {
                    root=join(root,d[i]);
                    visit[i]=true;
                }
            }
        }
        else if (oper==2)
        {
            int x;
            long long y;
            cin>>x>>y;
            x--;
            c[x]-=y;
            d[x]->val-=y;
            if (visit[x]) change_val(d[x]);
        }
        else
        {
            if (root==0)
            {
                cout<<"0\n";
                continue;
            }
            cout<<root->val<<'\n';
            delete_node(root);
        }
    }
    return 0;
}