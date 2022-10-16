#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

char s[maxn+5],t[5];
int DP[2][maxn+5][maxn+5];

void upd(int &x,int y) {if(x<y) x=y;}

int main()
{
    int n,k; scanf("%d%d",&n,&k);
    scanf("%s%s",s+1,t+1);
    char a=t[1],b=t[2];
    #define dp(i,j,c) DP[(i)&1][j][c]
    rep(j,0,k) rep(c,1,n) dp(0,j,c)=-inf;
    rep(i,1,n) 
    {
        rep(j,0,k) rep(c,0,n) dp(i,j,c)=-inf;
        rep(j,0,k) rep(c,0,n) if(dp(i-1,j,c)!=-inf)
        {
            upd(dp(i,j,c+(s[i]==a)), dp(i-1,j,c) + c*(s[i]==b));
            upd(dp(i,j+1,c+1), dp(i-1,j,c) + c*(a==b));
            upd(dp(i,j+1,c+(a==b)), dp(i-1,j,c) + c);
        }
    }
    int ans=0;
    rep(i,0,n) upd(ans, dp(n,k,i));
    printf("%d\n",ans);
    return 0;
}