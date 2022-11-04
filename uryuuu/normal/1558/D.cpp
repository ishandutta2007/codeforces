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
const int maxn=400005;
//const ll Mod=1000000007;
const ll Mod=998244353;

ll p[maxn],inv[maxn];
//inv[0]=inv[1]=1;
//inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;          // 
//S(n,m)=S(n,m1)+C(n m),S(n,m)=2S(n1,m)C(n1 m)
ll ksm(ll x,ll y)
{
    ll res=1;
    while(y)
    {
        if(y&1)
        {
            res=res*x%Mod;
        }
        x=x*x%Mod;
        y/=2;
    }
    return res%Mod;
}
 
ll C(int n,int m)
{
    return p[n]*inv[m]%Mod*inv[n-m]%Mod;
}

int b[maxn];
int qry(int x)
{
    int sum=0;
    while(x)
    {
        sum+=b[x];
        x-=lb(x);
    }
    return sum;
}

void upd(int x,int val)
{
    while(x<maxn)
    {
        b[x]+=val;
        x+=lb(x);
    }
}

int pos[maxn];
vector<pii>g;
int x[maxn],y[maxn];

int main()
{
    p[0]=inv[0]=1;
    for(int i=1;i<=maxn-2;i++)
    {
        p[i]=p[i-1]*i%Mod;

    }
    inv[maxn-2]=ksm(p[maxn-2],Mod-2);     //
    for(int i=maxn-3;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%Mod;
    
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        g.clear();
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            cin>>x[i]>>y[i];
        }
        int l,r,mid;
        for(int i=m;i>=1;i--)
        {
            l=0,r=n;
            while(l<r)
            {
                mid=(l+r)/2;
                if(qry(mid)+y[i]<=mid)
                {
                    r=mid;
                }
                else
                    l=mid+1;
            }
            pos[i]=l;
            upd(pos[i],1);
            g.push_back(mkp(pos[i],i));
        }
        sort(g.begin(),g.end());
        int k=g.size();
        for(int i=0;i<int(g.size())-1;i++)
        {
            if(g[i].first==g[i+1].first-1&&g[i].second<g[i+1].second)
                k--;
        }
        cout<<(C(2*n-k-1,n)%Mod+Mod)%Mod<<endl;
//        cout<<2*n-k-1<<' '<<n<<endl;
        for(int i=0;i<g.size();i++)
        {
            upd(g[i].first,-1);
        }
    }
    
    return 0;
}