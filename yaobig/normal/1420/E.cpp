#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 80
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

void chmax(int &x,int y) {if(x<y) x=y;}

int pos[maxn+5];
int dp[3205][maxn+5],ans[3205];

int main()
{
    int n; scanf("%d",&n);
    int N=0,M=n*(n-1)/2;
    rep(i,1,n) 
    {
        int x; scanf("%d",&x); if(x) pos[++N]=i;
    }
    memset(dp,-1,sizeof dp);
    dp[0][0]=0;
    rep(x,0,N-1) per(s,0,M) per(i,0,n) if(dp[s][i]!=-1)
    {
        rep(j,i+1,n) chmax(dp[s+abs(j-pos[x+1])][j],dp[s][i]+(j-i-1)*(n-j-(N-x-1)));
        dp[s][i]=-1;
    }
    rep(s,0,M) rep(i,0,n) chmax(ans[s],dp[s][i]);
    rep(s,1,M) chmax(ans[s],ans[s-1]);
    rep(s,0,M) printf("%d%c",ans[s]," \n"[s==M]);
    return 0;
}