#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 20
#define mod 2520
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll dp[maxn+5][256][2600];
int dig[maxn+5];

ll dfs(int dep,int st,int m,int lim)
{
    if(lim==0 && ~dp[dep][st][m]) return dp[dep][st][m];
    if(dep==0) return dp[dep][st][m];
    int B=lim?dig[dep]:9;
    ll res=0;
    rep(i,0,B)
    {
        int f=(i<2)?0:1<<(i-2);
        res+=dfs(dep-1,st|f,(m*10+i)%mod,lim && i==B);
    }
    if(lim==0) dp[dep][st][m]=res;
    return res;
}

ll cal(ll x)
{
    if(x==0) return 1;
    int cnt=0;
    while(x)
    {
        dig[++cnt]=x%10;
        x/=10;
    }
    return dfs(cnt,0,0,1);
}

int main()
{
    memset(dp,-1,sizeof dp);
    rep(i,0,255) rep(j,0,mod-1)
    {
        int f=1;
        rep(d,2,9) if(i&(1<<d-2)) if(j%d!=0) f=0;
        dp[0][i][j]=f;
    }

    int CAS; scanf("%d",&CAS);
    rep(cas,1,CAS)
    {
        ll l,r; scanf("%I64d%I64d",&l,&r);
        printf("%I64d\n",cal(r)-cal(l-1));
    }
    return 0;
}