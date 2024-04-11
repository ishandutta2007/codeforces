#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 3000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[maxn+5];
int cnt[maxn+5][maxn+5]; // cnt[i][j] = #{ 1<=k<=j | k+a[k]>i }.
int dp[maxn+5][maxn+5]; // dp[i][j] = minimum cost to set way[i]=1 and way[k]=0 for all i<k<=j.

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n; scanf("%d",&n);
        rep(i,1,n) scanf("%d",&a[i]);
        rep(i,1,n) rep(j,1,i) cnt[i][j]=cnt[i][j-1]+(j+a[j]>i);
        rep(i,1,n) rep(j,1,n) dp[i][j]=inf;
        rep(j,1,n) dp[n][j]=0;
        per(i,1,n-1)
        {
            int mn=inf;
            per(j,i+1,i+a[i]) 
            {
                mn=min(mn,dp[j][i+a[i]]+cnt[j-1][j-1]-cnt[j-1][i]);
                dp[i][j-1]=mn;
            }
            rep(j,1,i-1) dp[i][j]=dp[i][i];
        }
        printf("%d\n",dp[1][1]);
    }
    return 0;
}