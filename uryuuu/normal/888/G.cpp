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
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define flush fflush(stdout)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=6200010;
const ll Mod=1000000007;
//const ll Mod = 998244353;

int dep[maxn],ls[maxn],rs[maxn],n,cnt;

int dfs(int u,int v,int d)
{
    if(d==0)
        return 0;
    int x=1<<d;
    if(ls[u]&&ls[v])
        x=min(x,dfs(ls[u],ls[v],d-1));
    if(rs[u]&&rs[v])
        x=min(x,dfs(rs[u],rs[v],d-1));
    if(x!=1<<d)
        return x;
    if(ls[u]&&rs[v])
        return dfs(ls[u],rs[v],d-1)|(1<<(d-1));
    if(rs[u]&&ls[v])
        return dfs(rs[u],ls[v],d-1)|(1<<(d-1));
    return x;
}

ll ans=0;

int main()
{
    sync;
    cin>>n;
    cnt=1;
    dep[1]=30;
    for(int i=1,x;i<=n;i++)
    {
        cin>>x;
        for(int p=1,d=29;~d;d--)
        {
            int &son=(x>>d&1?rs:ls)[p];
            if(son==0)
                dep[son=++cnt]=d;
            p=son;
        }
    }
    ans=0;
    for(int i=1;i<=cnt;i++)
    {
        if(ls[i]&&rs[i])
            ans+=(1<<(dep[i]-1))+dfs(ls[i],rs[i],dep[i]-1);
    }
    cout<<ans<<endl;
    return 0;
}