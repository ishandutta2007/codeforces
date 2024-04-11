#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 500
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int cnt[maxn+5][2][26];
char s[maxn+5][maxn+5];
char t[maxn+5][maxn+5];
int dp[2][26][26];
pii pre[maxn+5][26][26];
pii mn[26][3];

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%s",s[i]+1);
    rep(i,1,n) rep(j,1,m) rep(c,0,25) cnt[i][j&1][c]+=s[i][j]-'a'!=c;
    rep(a,0,25)
    {
        rep(b,0,25)
        {
            if(a!=b) dp[1][a][b]=cnt[1][0][a]+cnt[1][1][b];
            else dp[1][a][b]=inf;
        }
        mn[a][0]=mn[a][1]={inf,-1};
        rep(b,0,25)
        {
            mn[a][2]={dp[1][a][b],b};
            per(i,0,1) if(mn[a][i]>mn[a][i+1]) swap(mn[a][i],mn[a][i+1]);
        }
    }
    rep(i,2,n)
    {
        rep(a,0,25) rep(b,0,25)
        {
            if(a==b) dp[i&1][a][b]=inf;
            else
            {
                dp[i&1][a][b]=cnt[i][0][a]+cnt[i][1][b];
                int tmp=inf;
                rep(a2,0,25) if(a2!=a)
                {
                    if(mn[a2][0].SE!=b)
                    {
                        if(tmp>mn[a2][0].FI) tmp=mn[a2][0].FI,pre[i][a][b]={a2,mn[a2][0].SE};
                    }
                    else if(tmp>mn[a2][1].FI) tmp=mn[a2][1].FI,pre[i][a][b]={a2,mn[a2][1].SE};
                }
                dp[i&1][a][b]+=tmp;
            }
        }
        rep(a,0,25)
        {
            mn[a][0]=mn[a][1]={inf,-1};
            rep(b,0,25)
            {
                mn[a][2]={dp[i&1][a][b],b};
                per(i,0,1) if(mn[a][i]>mn[a][i+1]) swap(mn[a][i],mn[a][i+1]);
            }
        }
    }
    int ans=inf;
    pii now={-1,-1};
    rep(a,0,25) rep(b,0,25) if(ans>dp[n&1][a][b]) ans=dp[n&1][a][b],now={a,b};
    per(i,1,n)
    {
        int a=now.FI,b=now.SE;
        rep(j,1,m) t[i][j]=j&1?b+'a':a+'a';
        now=pre[i][a][b];
    }
    printf("%d\n",ans);
    rep(i,1,n) puts(t[i]+1);
    return 0;
}