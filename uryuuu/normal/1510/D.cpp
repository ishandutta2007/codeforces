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


int a[maxn];
ll b[maxn];
ll dp[15];
ll pd[15];
vector<int>g[15],gg[15],tmp;

int main()
{
    sync;
    int n;
    cin>>n;
    int d;
    cin>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    
    for(int i=0;i<=10;i++)
    {
        dp[i]=-1;
    }
    
    
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        b[i]=ll(1.0*log(a[i])*100000000.0);
    }
    
    int j=0;
    for(int i=0;i<10;i++)
    {
        for(j=0;j<1005;j++)
        {
            g[i].push_back(0);
            gg[i].push_back(0);
        }
    }
    
    for(j=0;j<1005;j++)
    {
        tmp.push_back(0);
    }

    
    
    ll sum;
    int id;
    for(int i=1;i<=n;i++)
    {
        for(j=0;j<10;j++)
        {
            gg[j]=g[j];
            pd[j]=dp[j];
        }
        for(j=0;j<10;j++)
        {
            if(dp[j]<0)
                continue;
            sum=dp[j]+b[i];
            id=j*a[i]%10;
            if(sum>pd[id])
            {
                pd[id]=sum;
                gg[id]=g[j];
                gg[id][a[i]]++;
            }
        }
        
        id=a[i]%10;
        sum=b[i];
        if(sum>pd[id])
        {
            pd[id]=sum;
            gg[id]=tmp;
            gg[id][a[i]]++;
        }
        
        for(j=0;j<10;j++)
        {
            g[j]=gg[j];
            dp[j]=pd[j];
        }
    }
    
    id=d;
    
    
    if(dp[id]<0)
    {
        cout<<-1<<endl;
        return 0;
    }
    
    int sz=0;
    for(int i=1;i<=1000;i++)
    {
        sz+=g[id][i];
    }
    cout<<sz<<endl;
    for(int i=1;i<=1000;i++)
    {
        for(j=0;j<g[id][i];j++)
            cout<<i<<' ';
    }
    cout<<endl;
    
    return 0;
}