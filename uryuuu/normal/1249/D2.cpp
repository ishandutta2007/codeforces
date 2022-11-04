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
#include<unordered_map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define pii pair<int,int>
using namespace std;
const ll Mod=1e9+7;
const int maxn=200010;
int n,k;
struct node
{
    int l,r,id;
}p[maxn];

int lazy[maxn<<2],s[maxn<<2],cc[maxn];
void pushdown(int rt)
{
    s[lr]+=lazy[rt];
    s[rr]+=lazy[rt];
    lazy[lr]+=lazy[rt];
    lazy[rr]+=lazy[rt];
    lazy[rt]=0;
}
void update(int rt,int l,int r,int L,int R,int x)
{
    if(L<=l&&r<=R)
    {
        s[rt]+=x;
        lazy[rt]+=x;
        return;
    }
    if(lazy[rt])
        pushdown(rt);
    int mid=(l+r)/2;
    if(L<=mid)
        update(lr,l,mid,L,R,x);
    if(R>mid)
        update(rr,mid+1,r,L,R,x);
    s[rt]=max(s[lr],s[rr]);
    return ;
}

int query(int rt,int l,int r,int L,int R)
{
    
    if(L<=l&&r<=R)
    {
        return s[rt];
    }
    if(lazy[rt])
        pushdown(rt);
    int mid=(l+r)/2;
    int ss=0;
    if(L<=mid)
        ss=max(ss,query(lr,l,mid,L,R));
    if(R>mid)
        ss=max(ss,query(rr,mid+1,r,L,R));
    return ss;
}

bool cmp(node a,node b)
{
    return a.r<b.r||(a.r==b.r&&a.l<b.l);
}
int main()
{
    sync;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].l>>p[i].r;
        p[i].id=i;
    }
    sort(p+1,p+n+1,cmp);
    mm(lazy);
    mm(s);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
//        cout<<p[i].l<<' '<<p[i].r<<' '<<query(1,1,maxn,p[i].l,p[i].r)<<endl;
        if(query(1,1,maxn,p[i].l,p[i].r)<k)
            update(1,1,maxn,p[i].l,p[i].r,1);
        else
            cc[cnt++]=p[i].id;
    }
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++)
        cout<<cc[i]<<' ';
    cout<<endl;
    
}