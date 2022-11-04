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
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=500010;  // 
const ll Mod=1000000007;
//const ll Mod = 998244353;



int a[200];
int b[200];

int dp[10002][102],pre[10002][102],suc[10002][102];
int mx[102];

int main()
{
//    sync;
    int n;
//    cin>>n;
    scanf("%d",&n);

    
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
    }
    
    
    for(int j=10000;j>=0;j--)
    {
        for(int k=0;k<=n;k++)
        {
            dp[j][k]=-1;
        }
    }
    
    dp[0][0]=0;
    
    for(int i=1;i<=n;i++)
    {
        memset(pre,-1,sizeof(pre));
        memset(suc,-1,sizeof(suc));
        for(int j=10000;j>=0;j--)
        {
            for(int k=0;k<i;k++)
            {
                if(j>=a[i]&&dp[j-a[i]][k]>=0)
                {
                    pre[j][k+1]=max(pre[j][k+1],dp[j-a[i]][k]+2*b[i]);
                }
            }
        }
        for(int j=10000;j>=0;j--)
        {
            for(int k=0;k<i;k++)
            {
                if(dp[j][k]>=0)
                {
                    suc[j][k]=max(suc[j][k],dp[j][k]+b[i]);
                }
            }
        }
        
        for(int j=10000;j>=0;j--)
        {
            for(int k=0;k<=n;k++)
            {
                dp[j][k]=max(dp[j][k],pre[j][k]);
                dp[j][k]=max(dp[j][k],suc[j][k]);
//                dp[j][k]=min(j*2,dp[j][k]);
            }
        }
        
    }
    
    for(int j=10000;j>=0;j--)
        {
            for(int k=0;k<=n;k++)
            {
                dp[j][k]=min(j*2,dp[j][k]);
            }
        }
    
//    for(int i=0;i<=20;i++)
//    {
//        for(int j=0;j<=n;j++)
//            cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
//    }
    
    mm(mx);
    for(int j=10000;j>=0;j--)
    {
        for(int k=0;k<=n;k++)
        {
            mx[k]=max(mx[k],dp[j][k]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        printf("%.11f ",1.0*mx[i]/2.0);
    }
    puts("");
    
    
    return 0;
}