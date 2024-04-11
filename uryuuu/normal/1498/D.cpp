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
#define umap(a) (a).reserve(1024);(a).max_load_factor(0.25);
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=200005;
const ll Mod=1000000007;
//const ll Mod=998244353;

int vis[maxn];

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    int op,y;
    ll x;
    int lmt;
    ll s;
    int i;
    int j;
    vis[0]=1;
    ll fk;
    ll p,d;
    for(int k=1;k<=n;k++)
    {
        cin>>op>>x>>y;
        if(op==1)
        {
            fk=x/100000ll;
            if(x%100000ll)
                fk++;
            for(i=m;i>=0;i--)
            {
                if(vis[i]==0)
                    continue;
                s=fk+i;
                if(s>m||vis[s])
                    continue;
                vis[s]=k;
                for(j=2;j<=y;j++)
                {
                    s=ceil(1.0*s+fk);
                    if(s>m||vis[s])
                        break;
                    vis[s]=k;
                }
            }
        }
        else
        {
            for(i=m;i>=0;i--)
            {
                if(vis[i]==0)
                    continue;
                p=1ll*x*i;
                s=p/100000ll;
                if(p%100000)
                    s++;
                if(s>m||vis[s])
                    continue;
                vis[s]=k;
                for(j=2;j<=y;j++)
                {
                    p=1ll*x*s;
                    s=p/100000ll;
                    if(p%100000)
                        s++;
                    if(s>m||vis[s])
                        break;
                    vis[s]=k;
                }
            }
        }
    }
    for(i=1;i<=m;i++)
    {
        if(vis[i]==0)
            cout<<-1<<' ';
        else
            cout<<vis[i]<<' ';
    }
    cout<<endl;
    
    return 0;
}