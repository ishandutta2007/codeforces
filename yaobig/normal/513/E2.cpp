#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 30000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[maxn+5];
ll DP[2][200+5][4];

void chmax(ll &x,ll y) {if(y>x) x=y;}

int main()
{
    #define dp(i,j,s) DP[(i)&1][j][s]

    int n,k; scanf("%d%d",&n,&k);
    rep(i,1,n) scanf("%d",&a[i]);
    
    rep(j,1,k) rep(st,0,3) dp(0,j,st) = -1ll<<60;
    rep(i,1,n) rep(j,1,k)
    {
        rep(st,0,3) dp(i,j,st) = -1ll<<60;
        int c=1+(j!=1 && j!=k);
        chmax(dp(i,j,0), dp(i-1,j,0)-1ll*c*a[i]);
        chmax(dp(i,j,0), dp(i-1,j-1,3)-1ll*c*a[i]);
        //printf("?? %lld %lld\n",dp(i-1,j,0)-1ll*c*a[i],dp(i-1,j-1,3)-1ll*c*a[i]);
        chmax(dp(i,j,2), dp(i-1,j,2)+1ll*c*a[i]);
        chmax(dp(i,j,2), dp(i-1,j-1,1)+1ll*c*a[i]);
        dp(i,j,1) = dp(i,j,0);
        chmax(dp(i,j,1), dp(i-1,j,1));
        if(j!=1 && j!=k) chmax(dp(i,j,1), dp(i-1,j-1,1));
        dp(i,j,3) = dp(i,j,2);
        chmax(dp(i,j,3), dp(i-1,j,3));
        if(j!=1 && j!=k) chmax(dp(i,j,3), dp(i-1,j-1,3));
        //rep(st,0,3) {printf("? %d, %d, %d: %lld\n",i,j,st,dp(i,j,st));}
    }
    printf("%lld\n",max(dp(n,k,1), dp(n,k,3)));
    return 0;
}