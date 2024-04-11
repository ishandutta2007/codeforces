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
//#include<map>
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
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,ll> pii;
//const double pi=acos(-1);
const int maxn = 2010;
//const ll Mod=1000000007;
const ll Mod = 998244353;


ll a[maxn],b[maxn],c[maxn];

bool cmp(ll a,ll b)
{
    return a>b;
}

ll dp[205][205][205];

int main()
{
    int A,B,C;
    int cnt=0;
    scanf("%d%d%d",&A,&B,&C);
    for(int i=1;i<=A;i++)
    {
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=B;i++)
    {
        scanf("%lld",&b[i]);
    }
    for(int i=1;i<=C;i++)
    {
        scanf("%lld",&c[i]);
    }
    sort(a+1,a+A+1,cmp);
    sort(b+1,b+B+1,cmp);
    sort(c+1,c+C+1,cmp);
    for(int i=0;i<=A;i++)
    {
        for(int j=0;j<=B;j++)
        {
            for(int k=0;k<=C;k++)
            {
                dp[i][j][k]=max(dp[max(0,i-1)][j][k],dp[i][j][k]);
                dp[i][j][k]=max(dp[i][max(0,j-1)][k],dp[i][j][k]);
                dp[i][j][k]=max(dp[i][j][max(k-1,0)],dp[i][j][k]);
                if(i>0&&k>0)
                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+1ll*a[i]*c[k]);
                if(i>0&&j>0)
                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+1ll*a[i]*b[j]);
                if(j>0&&k>0)
                    dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k-1]+1ll*b[j]*c[k]);
            }
        }
    }
    
    
    
    printf("%lld\n",dp[A][B][C]);
    return 0;
}