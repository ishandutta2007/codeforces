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
#define eqs 1e-8
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
const int maxn=300005;
const ll Mod=1000000007;
//const ll Mod=998244353;

ll a[maxn],b[maxn];


struct node
{
    int id;
    ll val;
}s[maxn];

bool cmp(node a,node b)
{
    if(a.val==b.val)
        return a.id<b.id;
    return a.val>b.val;
}

int main()
{
    sync;
    int n;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<0)
        {
            cnt++;
            s[cnt].id=i;
            s[cnt].val=a[i];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=0)
        {
            ans++;
        }
        else
        {
            a[i]=0;
        }
    }
    sort(s+1,s+cnt+1,cmp);
    
    int id;
    ll sum,x,mn;
    int j;
    for(int i=1;i<=cnt;i++)
    {
        x=s[i].val;
        id=s[i].id;
        sum=0ll;
        for(j=1;j<id;j++)
            sum+=a[j];
        x=-x;
//        cout<<id<<' '<<sum<<' '<<x<<endl;
        if(sum<x)
            continue;
        ans++;
        for(j=id-1;j>=1;j--)
        {
            mn=min(a[j],x);
            x-=mn;
            a[j]-=mn;
            if(x==0)
                break;
        }
    }
    cout<<ans<<endl;

    return 0;
}