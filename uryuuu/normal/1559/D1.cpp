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
const int maxn=200005;
//const ll Mod=1000000007;
const ll Mod=998244353;


struct unio
{
    int fa[maxn];
    int findx(int x)
    {
        if(x==fa[x])
            return x;
        return fa[x]=findx(fa[x]);
    }
    
}tr[2];

int ans[maxn][2];

int main()
{
    sync;
    int n,m1,m2;
    int u,v;
    cin>>n>>m1>>m2;
    
    for(int i=1;i<=n;i++)
        tr[0].fa[i]=tr[1].fa[i]=i;
    
    int fu,fv;
    for(int i=1;i<=m1;i++)
    {
        cin>>u>>v;
        fu=tr[0].findx(u);
        fv=tr[0].findx(v);
        tr[0].fa[fu]=fv;
    }
    
    for(int i=1;i<=m2;i++)
    {
        cin>>u>>v;
        fu=tr[1].findx(u);
        fv=tr[1].findx(v);
        tr[1].fa[fu]=fv;
    }
    
    int cnt=0;
    
    for(u=1;u<=n;u++)
    {
        for(v=u+1;v<=n;v++)
        {
            fu=tr[0].findx(u);
            fv=tr[0].findx(v);
            if(fu==fv)
                continue;
            
            fu=tr[1].findx(u);
            fv=tr[1].findx(v);
            if(fu==fv)
                continue;
            
            tr[1].fa[fu]=fv;
            
            fu=tr[0].findx(u);
            fv=tr[0].findx(v);
            tr[0].fa[fu]=fv;
            
            cnt++;
            ans[cnt][0]=u;
            ans[cnt][1]=v;
        }
    }
    
    cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++)
        cout<<ans[i][0]<<' '<<ans[i][1]<<endl;
    
    return 0;
}