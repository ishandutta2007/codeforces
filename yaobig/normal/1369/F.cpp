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

int dp[maxn+5][2][2];

int solve(ll s,ll e,int num_odd,int num_even,int num_not_used)
{
    ll newe=e/2;
    if(s>newe) return s&1?num_odd:num_even;
    if(newe&1)  return solve(s,newe,min(num_odd,num_not_used), min(num_odd,num_not_used) ^ num_odd ^ num_not_used, num_even);
    else return solve(s,newe,num_odd, num_not_used, num_even);
}

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n)
    {
        ll s,e; scanf("%lld%lld",&s,&e);
        
        if(solve(s,e,e&1?1:2,e&1?2:1,0)) dp[i][0][0]=1;
        else dp[i][1][0]=1;
        if(solve(s,e,e&1?0:1,e&1?1:0,2)) dp[i][0][1]=1;
        else dp[i][1][1]=1;
    }
    per(now,1,n-1)
    {
        int C[2][2]={};
        rep(i,0,1) rep(k,0,1) rep(j,0,1) C[i][j] |= dp[now][i][k] & dp[now+1][k][j];
        rep(i,0,1) rep(j,0,1) dp[now][i][j]=C[i][j];
    }
    printf("%d %d\n",dp[1][0][1],dp[1][0][0]);
    return 0;
}