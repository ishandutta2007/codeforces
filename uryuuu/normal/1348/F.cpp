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
//#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mkp make_pair
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200010;
const ll Mod=1000000007;
//const ll Mod=998244353;


struct node
{
    int l,r;
    int id;
}a[maxn],b[maxn];


int p[maxn];

int s[maxn<<2];


void build(int rt,int l,int r)
{
    if(l==r)
    {
        s[rt]=a[l].l;
        return;
    }
    int mid=(l+r)/2;
    build(lr,l,mid);
    build(rr,mid+1,r);
    s[rt]=min(s[lr],s[rr]);
    return;
}

int query(int rt,int l,int r,int L,int R)
{
    int zx=inf;
    if(l>=L&&r<=R)
    {
        return s[rt];
    }
    int mid=(l+r)/2;
    if(mid>=L)
        zx=min(zx,query(lr,l,mid,L,R));
    if(mid+1<=R)
        zx=min(zx,query(rr,mid+1,r,L,R));
    return zx;
}

vector<pii>v[maxn];
set<pii>vis;

int main()
{
    sync;
    int n;
    cin>>n;
    rep(i,1,n)
    {
        cin>>a[i].l>>a[i].r;
        a[i].id=i;
        v[a[i].l].push_back(mkp(a[i].r,i));
    }
    rep(i,1,n)
    {
        vis.insert(v[i].begin(),v[i].end());
        int id=(*vis.begin()).second;
        b[i].id=a[id].id;
        b[i].l=a[id].l;
        b[i].r=a[id].r;
        vis.erase(vis.begin());
    }
    rep(i,1,n)
    {
        a[i].id=b[i].id;
        a[i].l=b[i].l;
        a[i].r=b[i].r;
    }
    
    
    
    rep(i,1,n)
    {
        p[a[i].id]=i;
    }
    
    build(1,1,n);
    for(int i=1;i<n;i++)
    {
        if(query(1,1,n,i+1,a[i].r)<=i)
        {
            cout<<"NO"<<endl;
            rep(k,1,n)
            cout<<p[k]<<' ';
            cout<<endl;
            for(int j=i+1;j<=a[i].r;j++)
            {
                if(a[j].l<=i)
                {
                    swap(a[j].id,a[i].id);
                    break;
                }
            }
            rep(k,1,n)
            {
                p[a[k].id]=k;
            }
            rep(k,1,n)
            cout<<p[k]<<' ';
            cout<<endl;
            return 0;
        }
    }
    
    cout<<"YES"<<endl;
    rep(k,1,n)
    cout<<p[k]<<' ';
    cout<<endl;
    
    
    return 0;
}