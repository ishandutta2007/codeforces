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
const int maxn = 3e3 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

string s,t;
ll two[maxn],dp[maxn][maxn],base[maxn];
int n,m;
ll tmp[maxn][maxn];

void init()
{
    for(int i=0;i<maxn;i++)tmp[0][i]=1;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m-i+1;j++)
        {
            if(s[i]==t[j])tmp[i][j]=tmp[i-1][j+1];
            if(s[i]==t[j+i-1])tmp[i][j]+=tmp[i-1][j];
            tmp[i][j]%=mod;
        }
    }
    for(int i=1;i<=m;i++)
    {
        dp[i][m-i+1]=tmp[i][m-i+1];
//        cout<<dp[i][m-i+1]<<endl;
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
    cin>>s>>t;
    n=s.size(),m=t.size();
    s="*"+s;
    t="5"+t;
    init();
    dp[0][m+1]=1;
    for(int i=1;i<=maxn;i++)dp[i][m+1]=dp[i-1][m+1]*2%mod;
    for(int j=m;j;j--)
    {
        for(int i=m-j+2;i<=n;i++)
        {
            dp[i][j]=dp[i-1][j];
            if(s[i]==t[j])
            {
                dp[i][j]+=dp[i-1][j+1];
                dp[i][j]%=mod;
            }
//            cout<<dp[i][j]<<' ';
        }
//        cout<<endl;
    }
    ll ans=0;
    for(int i=m;i<=n;i++)ans=(ans+dp[i][1])%mod;
    cout<<ans;
    return 0;
}