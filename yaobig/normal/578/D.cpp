#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;
 
ll DP[2][9];
int nxt[maxn+5][26];
char s[maxn+5];

int main()
{
    #define dp(i,msk) DP[(i)&1][msk]

    int n,m; scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    rep(c,0,m-1) nxt[n+1][c]=4;
    per(i,1,n) 
    {
        rep(c,0,m-1) nxt[i][c]=nxt[i+1][c]+1;
        nxt[i][s[i]-'a']=0;
    }

    dp(0,1*3)=1;
    rep(i,1,n) 
    {
        rep(nmsk,0,9-1) dp(i,nmsk)=0;
        rep(msk,0,9-1) if(dp(i-1,msk)) 
        {
            int f0=msk%3,f1=msk/3;
            rep(c,0,m-1)
            {
                int g0=min(2,f0+nxt[i+f0][c]);
                int g1=min(f0,f1+nxt[i-1+f1][c]);
                int nmsk=g0 + g1*3; 
                dp(i,nmsk)+=dp(i-1,msk);
            }
        }
    }
    ll ans=-1;
    rep(msk,0,625-1) if(msk/3<2) ans+=dp(n,msk);
    printf("%lld\n",ans);
    return 0;
}