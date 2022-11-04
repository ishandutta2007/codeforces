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
const int maxn=5005;
//const ll Mod=1000000007;
const ll Mod=998244353;

int a[maxn];
int dp[maxn][maxn];
int op[maxn],fe[maxn];

int main()
{
    sync;
    int n;
    cin>>n;
    int m=0;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i])
            op[++m]=i;
        else
            fe[++cnt]=i;
    }
    if(m==0)
    {
        cout<<0<<endl;
        return 0;
    }
    int j;
    for(int i=1;i<=n;i++)
    {
        for(j=0;j<=n;j++)
            dp[i][j]=1e9;
    }
    
    dp[0][0]=0;
    for(int i=1;i<=m;i++)
    {
        for(j=i;j<=cnt;j++)
        {
            dp[i][j]=min(dp[i][j],dp[i-1][j-1]+abs(op[i]-fe[j]));
        }
        for(j=1;j<=cnt;j++)
        {
            dp[i][j]=min(dp[i][j-1],dp[i][j]);
        }
    }
    cout<<dp[m][cnt]<<endl;
    
    return 0;
}