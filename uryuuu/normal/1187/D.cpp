#include<iostream>
#include<stdio.h>
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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
#define lb(x) (x&(-x));
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=300005;
const ll Mod=1000000007;

int a[maxn],b[maxn],v[maxn],s[maxn<<2];
map<pii,int>mp;
void pushup(int rt)
{
    s[rt]=min(s[lr],s[rr]);
}

void build(int rt,int l,int r)
{
    if(l==r)
    {
        s[rt]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(lr,l,mid);
    build(rr,mid+1,r);
    pushup(rt);
}


int query(int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R)
        return s[rt];
    int mid=(l+r)/2;
    int ss=inf;
    if(mid>=L)
        ss=min(query(lr,l,mid,L,R),ss);
    if(mid+1<=R)
        ss=min(query(rr,mid+1,r,L,R),ss);
    return ss;
}

void update(int rt,int l,int r,int pos,int val)
{
    if(l==r)
    {
        s[rt]=val;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)
        update(lr,l,mid,pos,val);
    else
        update(rr,mid+1,r,pos,val);
    pushup(rt);
}

map<int,int>ma,mb;

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        mp.clear();
        ma.clear();
        mb.clear();
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            v[i]=0;
            s[i]=0;
            cin>>a[i];
            ma[a[i]]++;
        }
        build(1,1,n);
        for(int i=1;i<=n;i++)
        {
            v[a[i]]++;
            mp[make_pair(a[i],v[a[i]])]=i;
        }
        int f=0;
        for(int i=1;i<=n;i++)
        {
            v[i]=0;
            cin>>b[i];
            mb[b[i]]++;
            if(mb[b[i]]>ma[b[i]])
                f=1;
        }
        if(f)
        {
            cout<<"NO"<<endl;
            continue;
        }
        int pos;
        for(int i=1;i<=n;i++)
        {
            v[b[i]]++;
            pos=mp[make_pair(b[i],v[b[i]])];
            if(query(1,1,n,1,pos)!=b[i])
            {
//                cout<<i<<' '<<pos<<' '<<query(1,1,n,1,pos)<<' '<<b[i]<<endl;
                f=1;
                break;
            }
            update(1,1,n,pos,inf);
        }
        if(f)
        {
            cout<<"NO"<<endl;
        }
        else
            cout<<"YES"<<endl;
    }
    return 0;
}