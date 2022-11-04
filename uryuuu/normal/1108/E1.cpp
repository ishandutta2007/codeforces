//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=100005;

int father[30010];
int size[30010];

int getf(int x)
{
    if(x==father[x])
        return x;
    return father[x]=getf(father[x]);
}
void jihe(int x,int y)
{
    x=getf(x);
    y=getf(y);
    father[y]=father[x];
}


struct node
{
    int l,r,id;
}b[305];
int vis[100005];

struct Node
{
    int mx,mi,lazy;
}s[maxn<<2];

int d;

void pushdown(int rt)
{
    if(s[rt].lazy)
    {
        s[lr].mi+=s[rt].lazy;
        s[lr].mx+=s[rt].lazy;
        s[lr].lazy+=s[rt].lazy;
        s[rr].mi+=s[rt].lazy;
        s[rr].mx+=s[rt].lazy;
        s[rr].lazy+=s[rt].lazy;
        s[rt].lazy=0;
    }
}

void pushup(int rt)
{
    s[rt].mx=max(s[lr].mx,s[rr].mx);
    s[rt].mi=min(s[lr].mi,s[rr].mi);
}

void build(int rt,int l,int r)
{
    s[rt].lazy=0;
    if(l==r)
    {
        cin>>d;
        s[rt].mi=s[rt].mx=d;
        return;
    }
    int mid=(l+r)/2;
    build(lr,l,mid);
    build(rr,mid+1,r);
    pushup(rt);
}

void update(int rt,int l,int r,int L,int R,int x)
{
    if(l>=L&&R>=r)
    {
        s[rt].mi+=x;
        s[rt].mx+=x;
        s[rt].lazy+=x;
//        cout<<l<<' '<<r<<' ';
        return;
    }
    pushdown(rt);
    int mid=(l+r)/2;
    if(mid>=L)
        update(lr,l,mid,L,R,x);
    if(mid<R)
        update(rr,mid+1,r,L,R,x);
    pushup(rt);
}

bool cmp(node a,node b)
{
    if(a.l==b.l)
        return a.r<b.r;
    return a.l<b.l;
}


int c[305];

vector<int>ans;

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    build(1,1,n);
//    cout<<"HDa"<<endl;
    for(int i=0;i<m;i++)
    {
        cin>>b[i].l>>b[i].r;
        b[i].id=i+1;
    }
    int zx=s[1].mx-s[1].mi;
    sort(b,b+m,cmp);
//    cout<<"fuck"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(b[j].l<=i&&b[j].r>=i)
            {
                if(vis[j]==0)
                {
                    update(1,1,n,b[j].l,b[j].r,-1);
                    vis[j]=1;
                }
            }
            else
            {
                if(vis[j]==1)
                {
                    update(1,1,n,b[j].l,b[j].r,1);
                    vis[j]=0;
                }
            }
        }
        if(s[1].mx-s[1].mi>zx)
        {
            zx=s[1].mx-s[1].mi;
            ans.clear();
//            cout<<endl;
            for(int j=0;j<m;j++)
            {
                if(vis[j]==1)
                    ans.push_back(b[j].id);
//                cout<<vis[j]<<' ';
            }
//            cout<<endl<<"djkf"<<zx<<' '<<ans.size()<<endl;
//            for(auto it :ans)
//            {
//                cout<<it<<' ';
//            }
        }
    }
    cout<<zx<<endl;
    cout<<ans.size()<<endl;
    for(auto it :ans)
    {
        cout<<it<<' ';
    }
    cout<<endl;
    return 0;
}