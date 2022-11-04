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
//#pragma comment(linker, "/STACK:36777216")  //hdu 
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
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;


struct node
{
    ll x,y;
}e[maxn];
ll x[2],y[2];

int main()
{
    sync;
    int n;
    cin>>n;
    
    ll xmin=1e9,xmax=-1e9,ymin=1e9,ymax=-1e9;
    
    for(int i=1;i<=n;i++)
    {
        cin>>e[i].x>>e[i].y;
        xmin=min(e[i].x,xmin);
        xmax=max(e[i].x,xmax);
        ymin=min(e[i].y,ymin);
        ymax=max(e[i].y,ymax);
    }
    
    x[0]=xmin;
    x[1]=xmax;
    y[0]=ymin;
    y[1]=ymax;
    
    ll mx=-2e18;
    int j,k;
    for(int i=1;i<=n;i++)
    {
        for(j=0;j<=1;j++)
        {
            for(k=0;k<=1;k++)
            {
                mx=max(mx,2ll*(max(x[j],e[i].x)-min(x[j],e[i].x)+max(y[k],e[i].y)-min(y[k],e[i].y)));
            }
        }
    }
    cout<<mx<<' ';
    ll ans=2ll*(ymax-ymin+xmax-xmin);
    for(int i=4;i<=n;i++)
        cout<<ans<<' ';
    cout<<endl;
    
    
    return 0;
}