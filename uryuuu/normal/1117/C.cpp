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
const int maxn=500005;
//const ll Mod=1000000007;
const ll Mod=998244353;


string s;

ll xpre[maxn],ypre[maxn];
ll dx,dy;
ll n;

bool solve(ll mid)
{
    ll xsum=0ll,ysum=0ll;
    ll m=mid/n;
    ll md=mid%n;
    xsum=m*xpre[n]+xpre[md];
    ysum=m*ypre[n]+ypre[md];
    if(abs(xsum-dx)+abs(ysum-dy)<=mid)
    {
        return 1;
    }
    return 0;
}

int main()
{
    sync;
    ll x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    cin>>n;
    cin>>s;
    dx=x2-x1;
    dy=y2-y1;
    
    for(int i=1;i<=n;i++)
    {
        xpre[i]=xpre[i-1];
        ypre[i]=ypre[i-1];
        if(s[i-1]=='U')
            ypre[i]++;
        else if(s[i-1]=='D')
            ypre[i]--;
        else if(s[i-1]=='L')
            xpre[i]--;
        else
            xpre[i]++;
    }
    
    ll ans=1e15;
    ll l=1ll,r=1e15,mid;
    while(l<r)
    {
        mid=(l+r)/2ll;
        if(solve(mid))
        {
            ans=min(ans,mid);
            r=mid;
        }
        else
            l=mid+1;
    }
    if(solve(l))
        ans=min(ans,l);
    if(ans==1e15)
    {
        cout<<-1<<endl;
    }
    else
        cout<<ans<<endl;
    return 0;
}