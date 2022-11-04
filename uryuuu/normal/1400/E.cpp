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
#define flush fflush(stdout)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=5010;
const ll Mod=1000000007;
//const ll Mod = 998244353;


ll a[maxn],b[maxn];
ll dp[maxn][maxn];

int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    a[0]=0;
    b[n+1]=0;
    sort(b+1,b+n+2);
    int m=unique(b+1,b+n+2)-b-1;
    
    for(int i=1;i<=n;i++)
    {
        int pos=lower_bound(b+1,b+m+1,a[i-1])-b;
        ll zx=6e17;
        for(int j=m;j>=1;j--)
        {
            if(j<=pos)
            {
                zx=min(zx,dp[i-1][j]);
            }
            if(a[i]<b[j])
            {
                continue;
            }
            if(j<=pos)
            {
                dp[i][j]=zx;
                if(b[j]<a[i])
                    dp[i][j]=1ll*dp[i][j]+1ll;
            }
            else
            {
                dp[i][j]=1ll*dp[i-1][pos]+1ll*(b[j]-b[pos]);
                if(b[j]<a[i])
                    dp[i][j]=1ll*dp[i][j]+1ll;
            }
        }
    }
    ll mn=6e17;
    for(int j=1;j<=m;j++)
    {
        if(a[n]<b[j])
            break;
        mn=min(dp[n][j],mn);
    }
    cout<<mn<<endl;
        
    return 0;
}