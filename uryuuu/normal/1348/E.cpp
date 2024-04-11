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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=2010;
const ll Mod=1000000007;
//const ll Mod=998244353;


int dp[505][505];
ll a[maxn],b[maxn];


int main()
{
    sync;
    int n,k;
    cin>>n>>k;
    ll sa=0,sb=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        sa+=1ll*a[i];
        sb+=1ll*b[i];
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<k;j++)
        {
            dp[i][j]=dp[i-1][(j-a[i]%k+k)%k];
            for(int c=0;c<=min(a[i],1ll*k-1);c++)
            {
                if((a[i]-c)%k+b[i]>=k)
                    dp[i][j]|=dp[i-1][(j-c+k)%k];
            }
        }
    }
    ll ans=0;
    for(int i=0;i<k;i++)
    {
        if(dp[n][i])
        {
            ans=1ll*(sa+sb-i)/k;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}