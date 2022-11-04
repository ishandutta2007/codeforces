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
const int maxn=500005;
//const ll Mod=1000000007;
const ll Mod=998244353;


ll a[maxn];
ll b[maxn];

int main()
{
    sync;

    ll sum=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=2;i<=n;i++)
    {
        if(a[i]>a[i-1])
            sum+=a[i]-a[i-1];
        b[i]=a[i]-a[i-1];
    }
    ll L,R;
    R=a[n];
    L=a[1]-(a[n]-sum);
    if(L+R>=0)
    {
        cout<<(L+R+1ll)/2ll<<endl;
    }
    else
        cout<<(L+R)/2ll<<endl;
    int q;
    cin>>q;
    int l,r;
    ll x;
    int f=0;
    while(q--)
    {
        cin>>l>>r>>x;
        f=0;
        if(r<n)
        {
            sum-=max(0ll,b[r+1])-max(0ll,b[r+1]-x);
            b[r+1]-=x;
            f=1;
        }
        else
            a[r]+=x;
        if(l>1)
        {
            sum+=max(0ll,b[l]+x)-max(0ll,b[l]);
            b[l]+=x;
        }
        else
        {
            if(l!=r||f)
                a[l]+=x;
        }
        
        R=a[n];
        L=a[1]-(a[n]-sum);
//        cout<<L<<' '<<R<<' '<<a[n]<<' '<<sum<<endl;
        if(L+R>=0)
        {
            cout<<(L+R+1ll)/2ll<<endl;
        }
        else
            cout<<(L+R)/2ll<<endl;
    }

    
    return 0;
}