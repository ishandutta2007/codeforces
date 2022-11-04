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
#include <chrono>
#include <random>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216") //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-10
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
#define umap(a) (a).reserve(1024);(a).max_load_factor(0.25);
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=1200005;
//const ll Mod=1000000007;
const ll Mod=998244353;

int a[maxn],n;
int t[maxn<<2],sum[maxn<<2];

void pushup(int rt)
{
    if(t[rt]==0)
    {
//        mn[rt]=mn[rr];
//        mx[rt]=mx[rr];
        sum[rt]=sum[rr];
    }
    else if(t[rt]==1)
    {
//        mn[rt]=mn[lr];
//        mx[rt]=mx[lr];
        sum[rt]=sum[lr];
    }
    else
    {
//        mn[rt]=mn[rr];
//        mx[rt]=mx[lr];
        sum[rt]=sum[rr]+sum[lr];
    }
//    cout<<rt<<' '<<sum[rt]<<endl;
}

void build(int rt,int l,int r)
{
    if(l==r)
    {
//        mn[rt]=mx[rt]=l;
        sum[rt]=1;
        return;
    }
    t[rt]=a[n-rt];
    int mid=(l+r)/2;
    build(rr,l,mid);
    build(lr,mid+1,r);
    pushup(rt);
    return;
}


string s;

int main()
{
    sync;
    int k;
    cin>>k;
    n=1<<k;
    cin>>s;
    for(int i=1;i<n;i++)
    {
        if(s[i-1]=='?')
            a[i]=2;
        else
            a[i]=int(s[i-1]-'0');
    }
    int q;
    cin>>q;
    char op;
    int id,rt;
    build(1,1,n);
    while(q--)
    {
        cin>>id>>op;
        if(op=='?')
            a[id]=2;
        else
            a[id]=int(op-'0');
        
        rt=n-id;
        t[rt]=a[id];
        while(rt)
        {
            pushup(rt);
            rt=rt/2;
        }
        cout<<sum[1]<<endl;
    }
    
    return 0;
}