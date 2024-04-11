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
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

ll dp[maxn+5][10];
int pre[maxn+5][10];

int main()
{
    int n,d; scanf("%d%d",&n,&d);
    vi a{0};
    rep(i,1,n)
    {
        int x; scanf("%d",&x);
        if(d%2!=0 && x%2==0) continue;
        if(d%5!=0 && x%5==0) continue;
        a.pb(x);
    }
    n=a.size()-1;
    memset(dp,63,sizeof dp);
    memset(pre,-1,sizeof pre);
    dp[0][1]=1;
    rep(i,1,n) 
    {
        rep(j,0,9) if(dp[i-1][j]<=1e13)
        {
            dp[i][j]=dp[i-1][j]*a[i];
        }
        rep(j,0,9) if(dp[i-1][j]<=1e13)
        {
            if(chmin(dp[i][j*a[i]%10],dp[i-1][j])) pre[i][j*a[i]%10]=j;
        }
    }

    //rep(i,0,n) rep(j,0,9) printf("? %d %d: %lld %d\n",i,j,dp[i][j],pre[i][j]);

    if(dp[n][d]>(1ll<<60)) return puts("-1"),0;
    int now=d; vi ans;
    per(i,1,n) if(pre[i][now]!=-1)
    {
        ans.pb(a[i]);
        now=pre[i][now];
    }
    if(ans.size())
    {
        int N=ans.size(); printf("%d\n",N);
        rep(i,1,N) printf("%d%c",ans[i-1]," \n"[i==N]);
    }
    else puts("-1");
    return 0;
}