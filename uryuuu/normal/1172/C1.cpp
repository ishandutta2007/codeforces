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
//#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;

ll a[maxn];
ll w[maxn];

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

ll f[105][55][55],g[105][55][55];

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    rep(i,1,n)
    {
        cin>>a[i];
    }
    ll sa=0,sb=0;
    rep(i,1,n)
    {
        cin>>w[i];
        if(a[i])
            sa+=w[i];
        else
            sb+=w[i];
    }
    for(int W=1;W<=102;W++)
    {
        for(int i=0;i<=m;i++)
        {
            g[W][i][m-i]=W;
            f[W][i][m-i]=W;
        }
    }
    
    for(int k=m-1;k>=0;k--)
    {
        for(int W=1;W<102;W++)
        {
            for(int i=0;i<=k;i++)
            {
                int j=k-i;
                if(sa+i+sb-j<W)
                    continue;
                if(sb-j<0)
                    continue;
                ll inv=ksm(sa+i+sb-j,Mod-2);
                f[W][i][j]=f[W+1][i+1][j]*W%Mod*inv%Mod;
                if(sa+i>=W)
                    f[W][i][j]+=f[W][i+1][j]*(sa+i-W)%Mod*inv%Mod;
                f[W][i][j]+=f[W][i][j+1]*(sb-j)%Mod*inv%Mod;
                f[W][i][j]%=Mod;
                
                if(W>0)
                    g[W][i][j]=g[W-1][i][j+1]*W%Mod*inv%Mod;
                if(sb-j>=W)
                    g[W][i][j]+=g[W][i][j+1]*(sb-j-W)%Mod*inv%Mod;
                g[W][i][j]+=g[W][i+1][j]*(sa+i)%Mod*inv%Mod;
                g[W][i][j]%=Mod;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i])
            cout<<f[w[i]][0][0]<<endl;
        else
            cout<<g[w[i]][0][0]<<endl;
    }
    
   
    return 0;
}