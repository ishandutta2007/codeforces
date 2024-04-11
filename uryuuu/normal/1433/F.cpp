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
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=300010;  // 
//const ll Mod=1000000007;
const ll Mod = 998244353;

int dp[100][100][100];
int a[100][100];
int g[100];
int e[100];

int main()
{
    sync;
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    }
    int d=m/2;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<k;j++)
        {
            for(int h=0;h<=d;h++)
                dp[i][j][h]=-99999999;
        }
        dp[i][0][0]=0;
    }
    
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int h=d;h>=0;h--)
            {
                for(int w=0;w<k;w++)
                {
                    dp[i][(w+a[i][j])%k][h+1]=max(dp[i][(w+a[i][j])%k][h+1],dp[i][w][h]+a[i][j]);
                }
            }
        }
    }
    
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=0;j<k;j++)
//        {
//            for(int h=0;h<=d;h++)
//                cout<<i<<' '<<j<<' '<<h<<' '<<dp[i][j][h]<<endl;
//        }
//    }
    
    
    
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        mm(e);
        cnt=0;
        for(int h=d;h>=0;h--)
        {
            for(int w=0;w<k;w++)
            {
                for(int j=0;j<k;j++)
                {
                    if(dp[i][w][h]<0)
                        continue;
                    e[(g[j]+dp[i][w][h])%k]=max(e[(g[j]+dp[i][w][h])%k],g[j]+dp[i][w][h]);
                }
            }
        }
        for(int j=0;j<k;j++)
        {
            g[j]=max(g[j],e[j]);
        }
    }
    cout<<g[0]<<endl;
    
    
    return 0;
}