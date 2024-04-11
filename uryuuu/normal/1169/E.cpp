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
#define ch(a) (int(a-'1')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=300010;
//const ll Mod=1000000007;
const ll Mod=998244353;


int a[maxn];
int dp[maxn][25];
int b[25][25];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<=20;i++)
    {
        for(int j=0;j<=20;j++)
        {
            b[i][j]=n+1;
        }
    }
    memset(dp,inf,sizeof(dp));
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<=20;j++)
        {
            if((a[i]&(1<<j)))
            {
                for(int k=0;k<=20;k++)
                {
                    if((a[i]&(1<<k)))
                    {
                        b[j][k]=i;
                    }
                    dp[i][k]=min(b[j][k],dp[i][k]);
                }
            }
        }
        for(int j=0;j<=20;j++)
        {
            if((a[i]&(1<<j)))
            {
                for(int k=0;k<=20;k++)
                {
                    b[j][k]=min(b[j][k],dp[i][k]);
                }
            }
        }
    }
    int x,y;
    int f=0;
    while(m--)
    {
        scanf("%d%d",&x,&y);
        f=0;
        for(int j=0;j<=20;j++)
        {
            if(a[y]&(1<<j))
            {
                if(dp[x][j]<=y)
                {
                    f=1;
                    break;
                }
            }
        }
        if(f)
            printf("Shi\n");
        else
            printf("Fou\n");
    }
    
    return 0;
}