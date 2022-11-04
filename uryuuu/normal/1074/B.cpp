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
const int maxn=1005;
const ll Mod=1000000007;
//const ll Mod=998244353;

int visa[maxn],visb[maxn],a[maxn],b[maxn];
vector<int>g[maxn];
int sz[maxn];
int f;
int k1,k2;
int x;
int dep[maxn];
int d[maxn];
void dfs2(int u,int fa)
{
    dep[u]=dep[fa]+1;
    for(int v:g[u])
    {
        if(v==fa)
            continue;
        dfs2(v,u);
    }
    return;
}

bool cmp(int a,int b)
{
    return dep[a]<dep[b];
}

int n;


int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            g[i].clear();
            visa[i]=0;
            visb[i]=0;
            sz[i]=0;
        }
        int u,v;
        for(int i=1;i<n;i++)
        {
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cin>>k1;
        for(int i=1;i<=k1;i++)
        {
            cin>>a[i];
            visa[a[i]]=1;
        }
        cin>>k2;
        for(int i=1;i<=k2;i++)
        {
            cin>>b[i];
            visb[b[i]]=1;
        }
        f=0;
        if(k1<=5)
        {
            for(int i=1;i<=k1;i++)
            {
                cout<<"A "<<a[i]<<endl;
                cin>>x;
                if(visb[x])
                {
                    cout<<"C "<<a[i]<<endl;
                    f=1;
                    break;
                }
            }
            if(f==0)
                cout<<"C -1"<<endl;
            continue;
        }

        if(k2<=5)
        {
            for(int i=1;i<=k2;i++)
            {
                cout<<"B "<<b[i]<<endl;
                cin>>x;
                if(visa[x])
                {
                    cout<<"C "<<x<<endl;
                    f=1;
                    break;
                }
            }
            if(f==0)
                cout<<"C -1"<<endl;
            continue;
        }
        
        
        cout<<"B "<<b[1]<<endl;
        cin>>x;
        if(visa[x])
        {
            cout<<"C "<<x<<endl;
            continue;
        }
        dfs2(x,0);
        for(int i=1;i<=n;i++)
            d[i]=i;
        sort(d+1,d+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            if(visa[d[i]])
            {
                cout<<"A "<<d[i]<<endl;
                cin>>x;
                if(visb[x])
                    cout<<"C "<<d[i]<<endl;
                else
                    cout<<"C -1"<<endl;
                break;
            }
        }
    }
    
    
    return 0;
}