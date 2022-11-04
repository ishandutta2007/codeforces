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
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=2005;
const ll Mod=1000000007;
//const ll Mod=998244353;
 
ll dp[maxn][maxn];

int main()
{
    sync;
    int n;
    ll mod;
    cin>>n>>mod;
    dp[0][0]=1;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            (dp[i+1][j+1]+=1ll*(j+1)*dp[i][j])%=mod;
            (dp[i+1][j]+=2ll*j*dp[i][j])%=mod;
            (dp[i+2][j]+=2ll*j*dp[i][j])%=mod;
            if(i>=2)
            {
                (dp[i+2][j-1]+=2ll*(j-1)*dp[i][j])%=mod;
                (dp[i+3][j-1]+=1ll*(j-1)*dp[i][j])%=mod;
            }
        }
    }
    cout<<dp[n][1]%mod<<endl;
    return 0;
}