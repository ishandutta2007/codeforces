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
using namespace std;
typedef pair<int,ll> pii;
//const double pi=acos(-1);
const int maxn=500010;  // 
//const ll Mod=1000000007;
const ll Mod=998244353;

ll a[maxn];
ll dp[maxn][3][2][2];

int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==1)
    {
        cout<<a[1]<<endl;
        return 0;
    }
    rep(i,0,n)
    rep(j,0,2)
    rep(k,0,1)
    rep(h,0,1)
    dp[i][j][k][h]=-2e18;
    
    dp[1][0][1][0]=a[1];
    dp[1][1][0][0]=-a[1];
    
    int mo;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=2;j++)
        {
            mo=(j+1)%3;
            dp[i][j][1][0]=max(dp[i][j][1][0],a[i]+dp[i-1][j][0][0]);
            dp[i][j][1][1]=max(dp[i][j][1][1],a[i]+dp[i-1][j][1][0]);
            dp[i][mo][0][0]=max(dp[i][mo][0][0],-a[i]+dp[i-1][j][1][0]);
            dp[i][mo][0][1]=max(dp[i][mo][0][1],-a[i]+dp[i-1][j][0][0]);
            
            dp[i][j][1][1]=max(dp[i][j][1][1],a[i]+dp[i-1][j][0][1]);
            dp[i][j][1][1]=max(dp[i][j][1][1],a[i]+dp[i-1][j][1][1]);
            dp[i][mo][0][1]=max(dp[i][mo][0][1],-a[i]+dp[i-1][j][1][1]);
            dp[i][mo][0][1]=max(dp[i][mo][0][1],-a[i]+dp[i-1][j][0][1]);
        }
    }

    mo=((1-n)%3+3)%3;
    
    cout<<max(dp[n][mo][1][1],dp[n][mo][0][1]);
    
    return 0;
}