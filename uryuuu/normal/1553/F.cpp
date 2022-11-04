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
const int maxn=500005;
//const ll Mod=1000000007;
const ll Mod=998244353;


ll a[maxn];
ll ans[maxn];

struct node
{
    ll b[maxn];
    void upd(int x,ll val)
    {
        while(x<maxn)
        {
            b[x]+=val;
            x+=lb(x);
        }
    }
    
    ll qry(int x)
    {
        if(x<=0)
            return 0;
        ll ans=0;
        while(x>0)
        {
            ans+=b[x];
            x-=lb(x);
        }
        return ans;
    }
    
    ll Qry(int l,int r)
    {
        return qry(r)-qry(l-1);
    }
}s[2];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    int j;
    ll x;
    ll L,R;
    ll pre=0ll;
    for(int i=1;i<=n;i++)
    {
        x=a[i];
        ans[i]=ans[i-1];
        for(j=0;x*j<300005;j++)
        {
            L=x*j;
            R=min(x*(j+1)-1,300005ll);
            ans[i]-=1ll*j*x*s[0].Qry(L,R);
        }
        ans[i]+=pre;
        pre+=x;
        ans[i]+=1ll*(i-1)*x;
        ans[i]-=s[1].qry(x);
        s[0].upd(x,1);
        for(j=x;j<=300005;j+=x)
            s[1].upd(j,x);
    }
    
    
    for(int i=1;i<=n;i++)
    {
        printf("%lld ",ans[i]);
    }
    puts("");
    return 0;
}