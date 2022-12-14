#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l + r >> 1)
#define lo (o << 1)
#define ro (lo | 1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

int n,m;
ll arr[110][110];

ll f(ll a)
{
    ll dp[110][110];
    memset(dp,0x3f,sizeof(dp));
    dp[0][1]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(arr[i][j]<a)dp[i][j]=linf;
            else dp[i][j]=min(dp[i-1][j],dp[i][j-1])+arr[i][j]-a;
        }
    }
    return dp[n][m];
}
ll solve()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%lld",&arr[i][j]);
            arr[i][j]-=i+j-2;
        }
    }

    ll ret=linf;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            ret=min(ret,f(arr[i][j]));
        }
    }
    return ret;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        printf("%lld\n",solve());
    }
    return 0;
}