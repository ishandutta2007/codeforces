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
#include<bitset>
#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'A')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,ll> pii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;
//typedef pair<pii,int> piii;

int t[2][maxn<<2],lazy[2][maxn<<2];

void pushup(int rt)
{
    for(int i=0;i<=1;i++)
    {
        t[i][rt]=t[i][lr]+t[i][rr];
    }
}
int a[maxn];
int b[maxn];

void build(int rt,int l,int r)
{
    t[0][rt]=t[1][rt]=0;
    lazy[0][rt]=lazy[1][rt]=0;
    if(l==r)
    {
        t[b[l]][rt]++;
        return;
    }
    int mid=(l+r)/2;
    build(lr,l,mid);
    build(rr,mid+1,r);
    pushup(rt);
}

void pushdown(int rt)
{
    for(int i=0;i<=1;i++)
    {
        if(lazy[i][rt])
        {
            t[i][lr]+=t[1-i][lr];
            t[1-i][lr]=0;
            t[i][rr]+=t[1-i][rr];
            t[1-i][rr]=0;
            lazy[i][lr]=1;
            lazy[1-i][lr]=0;
            lazy[i][rr]=1;
            lazy[1-i][rr]=0;
            lazy[i][rt]=0;
        }
    }
}

void upd(int rt,int l,int r,int L,int R,int val)
{
    if(r<L)
        return;
    if(l>R)
        return;
    if(L<=l&&r<=R)
    {
        t[val][rt]+=t[1-val][rt];
        t[1-val][rt]=0;
        lazy[val][rt]=1;
        lazy[1-val][rt]=0;
        return;
    }
    pushdown(rt);
    int mid=(l+r)/2;
    upd(lr,l,mid,L,R,val);
    upd(rr,mid+1,r,L,R,val);
    pushup(rt);
}

int qry(int rt,int l,int r,int L,int R)
{
    if(r<L)
        return 0;
    if(l>R)
        return 0;
    if(L<=l&&r<=R)
    {
        return t[1][rt];
    }
    pushdown(rt);
    int mid=(l+r)/2;
    return qry(lr,l,mid,L,R)+qry(rr,mid+1,r,L,R);
}

string s;
struct node
{
    int l,r;
}q[maxn];

int main()
{
    sync;
    int T;
    int n,m;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        cin>>s;
        for(int i=0;i<n;i++)
        {
            a[i+1]=int(s[i]-'0');
        }
        
        cin>>s;
        for(int i=0;i<n;i++)
        {
            b[i+1]=int(s[i]-'0');
        }
        for(int i=1;i<=m;i++)
        {
            cin>>q[i].l>>q[i].r;
        }
        
        build(1,1,n);
        int L,R,sum,seg;
        int f=0;
        for(int i=m;i>=1;i--)
        {
            L=q[i].l;
            R=q[i].r;
            seg=R-L+1;
            sum=qry(1,1,n,L,R);
//            cout<<L<<' '<<R<<' '<<sum<<endl;
            if(sum*2<seg)
                upd(1,1,n,L,R,0);
            else if(2*seg-2*sum<seg)
                upd(1,1,n,L,R,1);
            else
            {
                f=1;
                break;
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=qry(1,1,n,i,i))
            {
                f=1;
                break;
            }
        }
        if(f==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    
    return 0;
}