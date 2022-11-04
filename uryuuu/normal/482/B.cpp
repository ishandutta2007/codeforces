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
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define pii pair<int,int>
using namespace std;
const int maxn=101000;

int n,m,mid,ss;

int sum[maxn<<2],lazy[maxn<<2];
void build(int l,int r,int rt)
{
    lazy[rt]=0;
    if(l==r)
    {
        sum[rt]=0;
        return;
    }
    mid=(l+r)/2;
    build(l,mid,lr);
    build(mid+1,r,rr);
    return ;
}

void pushdown(int rt)
{
    if(lazy[rt])
    {
        sum[lr]|=lazy[rt];
        sum[rr]|=lazy[rt];
        lazy[lr]|=lazy[rt];
        lazy[rr]|=lazy[rt];
        lazy[rt]=0;
    }
}

void update(int rt,int l,int r,int L,int R,int s)
{
    if(L<=l&&r<=R)
    {
        lazy[rt]|=s;
        sum[rt]|=s;
        return;
    }
    pushdown(rt);
    int mid=(l+r)/2;
    if(L<=mid)
        update(lr,l,mid,L,R,s);
    if(R>mid)
        update(rr,mid+1,r,L,R,s);
    return;
}

void query(int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R)
    {
        ss&=sum[rt];
        return ;
    }
    pushdown(rt);
    int mid=(l+r)/2;
    if(L<=mid)
        query(lr,l,mid,L,R);
    if(R>mid)
        query(rr,mid+1,r,L,R);
    sum[rt]=sum[lr]&sum[rr];
    return;
}


int l[maxn],r[maxn],d[maxn];

int main()
{
    sync;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>l[i]>>r[i]>>d[i];
        update(1,1,n,l[i],r[i],d[i]);
    }
    for(int i=0;i<m;i++)
    {
        ss=(1<<30)-1;
        query(1,1,n,l[i],r[i]);
        if(ss!=d[i])
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++)
    {
        ss=(1<<30)-1;
        query(1,1,n,i,i);
        cout<<ss<<' ';
    }
    cout<<endl;
    return 0;
}