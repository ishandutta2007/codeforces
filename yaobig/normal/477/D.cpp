#include "bits/stdc++.h"
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
typedef vector<int> vi;
typedef double db;

inline void add(int &x,int y) {x+=y; if(x>=mod) x-=mod;}
inline void upd(int &x,int y) {if(x>y) x=y;}

char s[maxn+5];
int dp[maxn+5][maxn+5],lcp[maxn+5][maxn+5];

inline bool check(int pos,int len)
{
    int s2=pos-len+1,s1=s2-len;
    if(s1<1) return 0;
    if(lcp[s1][s2]>=len) return 1;
    return s[s2+lcp[s1][s2]]>s[s1+lcp[s1][s2]];
}

int cal(int be,int ed)
{
    int x=0;
    rep(i,be,ed) 
    {
        x=x*2+(s[i]=='1');
    }
    return x;
}

int main()
{
    scanf("%s",s+1);
    int n=strlen(s+1);
    per(i,1,n) per(j,i+1,n) lcp[i][j]=s[i]==s[j]?lcp[i+1][j+1]+1:0;
    //rep(i,1,n) rep(j,1,n) printf("%d%c",lcp[i][j]," \n"[j==n]);
    
    rep(j,0,n) dp[0][j]=1;
    rep(i,1,n) 
    {
        rep(j,1,i) if(s[i-j+1]=='1')
        {
            if(check(i,j)) dp[i][j]=dp[i-j][j];
            else dp[i][j]=dp[i-j][j-1];
        }
        //rep(j,1,n) printf("%d%c",dp[i][j]," \n"[j==n]);
        rep(j,1,n) add(dp[i][j],dp[i][j-1]);
    }
    printf("%d\n",dp[n][n]);
    memset(dp,63,sizeof dp);
    rep(j,0,n) dp[0][j]=0;
    rep(i,1,n)
    {
        rep(j,1,i) if(s[i-j+1]=='1')
        {
            if(check(i,j)) dp[i][j]=dp[i-j][j]+1;
            else dp[i][j]=dp[i-j][j-1]+1;
        }
        if(i!=n) rep(j,1,n) upd(dp[i][j],dp[i][j-1]);
    }
    int id=n,ans=inf;
    per(j,1,n-1) if(dp[n][j]<inf)
    {
        if(id>=20) 
        {
            id=j;
            ans=j>=20?inf:cal(n-j+1,n)+dp[n][j];
        }
        else
        {
            int x=cal(n-j+1,n)+dp[n][j];
            if(x<ans)
            {
                id=j;
                ans=x;
            }
        }
    }
    if(ans==inf)
    {
        ans=0;
        rep(i,n-id+1,n) ans=(ans*2+(s[i]=='1'))%mod;
        ans=(ans+dp[n][id])%mod;
    }
    printf("%d\n",ans);
    return 0;
}