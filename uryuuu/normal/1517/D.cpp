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
const int maxn=500005;
//const ll Mod=1000000007;
const ll Mod=998244353;

int dp[505][505][12];
int r[505][505];
int c[505][505];

int main()
{
    sync;
    int n,m;
    int j;
    int k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        for(j=1;j<m;j++)
            cin>>r[i][j];
    }
    
    for(int i=1;i<n;i++)
    {
        for(j=1;j<=m;j++)
            cin>>c[i][j];
    }
    
    if(k%2)
    {
        for(int i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
                cout<<-1<<' ';
            cout<<endl;
        }
        return 0;
    }
    
    k/=2;
    int st;
    for(st=1;st<=k;st++)
    {
        for(int i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                dp[i][j][st]=1e9;
            }
        }
    };
    
    for(int i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            dp[i][j][0]=0;
    }
    
    for(st=1;st<=k;st++)
    {
        for(int i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(j<m)
                {
                    dp[i][j][st]=min(dp[i][j][st],dp[i][j+1][st-1]+r[i][j]);
                }
                if(j>1)
                {
                    dp[i][j][st]=min(dp[i][j][st],dp[i][j-1][st-1]+r[i][j-1]);
                }
                if(i<n)
                {
                    dp[i][j][st]=min(dp[i][j][st],dp[i+1][j][st-1]+c[i][j]);
                }
                if(i>1)
                {
                    dp[i][j][st]=min(dp[i][j][st],dp[i-1][j][st-1]+c[i-1][j]);
                }
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
           cout<<2*dp[i][j][k]<<' ';
        cout<<endl;
    }
    
    return 0;
}