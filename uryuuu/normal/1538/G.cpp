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
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=50005;
//const ll Mod=1000000007;
const ll Mod=998244353;

ll x,y,a,b;

ll f(ll s)
{
    ll n,m;
    n=min(x/a,y/b);
    n=min(n,s);
    m=min((x-a*n),(y-b*n))/(a+b);
    m=2ll*m;
    return n+m;
}

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        ll mx=0ll;
        cin>>x>>y>>a>>b;
        if(x>y)
            swap(x,y);
        if(a>b)
            swap(a,b);
        
        if(a==b)
        {
            cout<<x/a<<endl;
            continue;
        }
        

        ll d=y-x;
        d=d/(b-a);
        
        for(ll i=max(0ll,d-100ll);i<=d+100ll;i++)
        {
            mx=max(mx,f(i));
        }

        cout<<mx<<endl;
    }
    return 0;
}