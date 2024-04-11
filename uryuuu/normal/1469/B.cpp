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
//const double pi=acos(-1);
const int maxn=500010;  // 
const ll Mod=1000000007;
//const ll Mod = 998244353;


int a[1010],b[1010],dp[105][105];

int main()
{
    sync;
    int t;
    int n,m;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        cin>>m;
        for(int i=1;i<=m;i++)
            cin>>b[i];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                dp[i][j]=-99999999;
        dp[0][0]=0;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i>0)
                    dp[i][j]=max(dp[i][j],dp[i-1][j]+a[i]);
                if(j>0)
                    dp[i][j]=max(dp[i][j],dp[i][j-1]+b[j]);
            }
        }
        int ans=-99999999;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                ans=max(dp[i][j],ans);
            }
        }
        cout<<ans<<endl;
    }
    
    
    return 0;
}