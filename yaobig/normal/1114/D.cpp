#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 5000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef vector<int> vi;
typedef double db;

int a[maxn+5];
int dp[maxn+5][maxn+5][2];
int main()
{
    int n; scanf("%d",&n);
    int tot=0;
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n) if(a[i]!=a[tot]) a[++tot]=a[i];
    n=tot;
    rep(len,2,n) rep(l,1,n-len+1)
    {
        int r=l+len-1;
        if(a[l]==a[r]) dp[l][r][0]=dp[l][r][1]=r-l==1?0:min(dp[l+1][r-1][0],dp[l+1][r-1][1])+1;
        else
        {
            dp[l][r][0]=min(dp[l][r-1][0]+1,min(dp[l+1][r][0],dp[l+1][r][1])+1);
            dp[l][r][1]=min(dp[l+1][r][1]+1,min(dp[l][r-1][0],dp[l][r-1][1])+1);
        }
    }
    printf("%d\n",min(dp[1][n][0],dp[1][n][1]));
    return 0;
}