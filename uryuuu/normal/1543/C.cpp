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


double vv;
int sum;
long double ans;

ll v;

void dfs(ll a,ll b,ll c,long double pre,int rd)
{
//    cout<<a<<' '<<b<<' '<<c<<' '<<pre<<' '<<rd<<endl;
    ans+=pre*((long double)0.000000000001*c)*rd;
    ll na,nb,nc;
    if(a>=-1)
    {
        if(a>v)
        {
            na=a-v;
            if(b>=-1)
            {
                nb=b+v/2;
                nc=c+v/2;
                dfs(na,nb,nc,pre*((long double)0.000000000001*a),rd+1);
            }
            else
            {
                nb=b;
                nc=c+v;
                dfs(na,nb,nc,pre*((long double)0.000000000001*a),rd+1);
            }
        }
        else
        {
            if(b>=-1)
            {
                nb=b+a/2;
                nc=c+a/2;
                dfs(-5,nb,nc,pre*((long double)0.000000000001*a),rd+1);
            }
            else
            {
                nb=b;
                nc=c+a;
                dfs(-5,b,nc,pre*((long double)0.000000000001*a),rd+1);
            }
        }
    }
    
    if(b>=-1)
    {
        if(b>v)
        {
            nb=b-v;
            if(a>=-1)
            {
                na=a+v/2;
                nc=c+v/2;
                dfs(na,nb,nc,pre*((long double)0.000000000001*b),rd+1);
            }
            else
            {
                na=a;
                nc=c+v;
                dfs(na,nb,nc,pre*((long double)0.000000000001*b),rd+1);
            }
        }
        else
        {
            if(a>=-1)
            {
                na=a+b/2;
                nc=c+b/2;
                dfs(na,-5,nc,pre*((long double)0.000000000001*b),rd+1);
            }
            else
            {
                na=a;
                nc=c+b;
                dfs(na,-5,nc,pre*((long double)0.000000000001*b),rd+1);
            }
        }
    }
    
}

string a,b,c,vvv;

ll solve(string a)
{
    int len=a.length();
    a+='0';
    a+='0';
    a+='0';
    a+='0';
    ll ans=0ll;
    ans+=1000*ll(a[2]-'0')+100*ll(a[3]-'0')+10*ll(a[4]-'0')+ll(a[5]-'0');
    return ans;
}

int main()
{
//    sync;
    int t;
    int n;
    scanf("%d",&t);
    while(t--)
    {
//        double a,b,c;
//        scanf("%lf%lf%lf%lf",&a,&b,&c,&vv);
        cin>>a>>b>>c>>vvv;
        ll aa=100000000ll*solve(a);
        ll bb=100000000ll*solve(b);
        ll cc=100000000ll*solve(c);
        v=100000000ll*solve(vvv);
        ans=0;
//        ll aa=100000000ll*ll(10000*a);
//        ll bb=100000000ll*ll(10000*b);
//        ll cc=100000000ll*ll(10000*c);
//        v=100000000ll*ll(10000*vv);
        dfs(aa,bb,cc,1.0,1);
        double ss=double(ans);
        printf("%.8f\n",ss);
    }
    
    return 0;
}