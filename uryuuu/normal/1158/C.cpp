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
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define flush fflush(stdout)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=500010;
const ll Mod=1000000007;
//const ll Mod = 998244353;


int c[maxn];
struct node
{
    int id,pos;
}e[maxn];

bool cmp(node a,node b)
{
    if(a.id==b.id)
    {
        return a.pos<b.pos;
    }
    return a.id>b.id;
}

int ans[maxn];
int a[maxn<<2];

void pushup(int rt)
{
    a[rt]=max(a[lr],a[rr]);
}

void build(int rt,int l,int r)//1,n,
{
    if(l==r)
    {
        a[rt]=ans[l];
        return;
    }
    int mid=(l+r)/2;
    build(lr,l,mid);
    build(rr,mid+1,r);
    pushup(rt);
}


ll query(int rt,int l,int r,int L,int R)
{
    if(r<L||l>R)
        return 0;
    if(r<=R&&l>=L)
    {
        return a[rt];
    }
    int mid=(l+r)/2;
    return max(query(lr,l,mid,L,R),query(rr,mid+1,r,L,R));
}

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        rep(i,1,n)
        cin>>c[i];
        int mx=0;
        rep(i,1,n)
        {
            if(c[i]==-1)
            {
                if(mx<=i)
                {
                    c[i]=n+1;
                    mx=0;
                }
                else
                    c[i]=i+1;
            }
            else
                mx=max(mx,c[i]);
        }
        
        
        
        mx=0;
        int f=0;
        if(c[n]!=n+1)
        {
            f=1;
        }
        for(int i=1;i<=n;i++)
        {
            if(c[i]==n+1)
            {
                if(mx>i)
                {
                    f=1;
//                    cout<<mx<<' '<<i<<endl;
                }
                mx=0;
            }
            else
                mx=max(c[i],mx);
        }
        
        for(int i=1;i<=n;i++)
        {
            if(c[i]<=i)
            {
                f=1;
            }
        }
        
        if(f)
        {
            cout<<-1<<endl;
            continue;
        }
        int cnt=0;
        
        int mxx=n;
        
        for(int i=1;i<=n;i++)
        {
            e[++cnt].pos=i;
            e[cnt].id=c[i];
            if(c[i]==n+1)
            {
                sort(e+1,e+cnt+1,cmp);
                for(int j=1;j<=cnt;j++)
                {
                    ans[e[j].pos]=mxx--;
                }
                cnt=0;
            }
            
        }
        
//        for(int i=1;i<=n;i++)
//            cout<<c[i]<<' ';
//        cout<<endl;
//        for(int i=1;i<=n;i++)
//            cout<<ans[i]<<' ';
//        cout<<endl;
//        
        build(1,1,n);
        for(int i=1;i<n;i++)
        {
            int L=i;
            int R=c[i]-1;
            if(query(1,1,n,L,R)>ans[i])
            {
                f=1;
            }
        }
    
        if(f)
        {
            cout<<-1<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<' ';
        cout<<endl;
    
    }
    return 0;
}