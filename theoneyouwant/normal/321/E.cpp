#include <bits/stdc++.h>
#include<stdlib.h>
using namespace std;
 
typedef int ll;
typedef long double ld;
 
#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define rev(i,a,b) for(ll i=a;i>=b;i--)
#define pll pair<ll,ll>
#define vll vector<ll>
#define sll set<ll>
#define vpll vector<pll>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define ln length()
#define M 1000000007
 
ll n,k,pr[4001][4001],cost[4001][4001];
ll dp[801][4001];
inline int getint(){
	char c;
	while((c=getchar())<'0'||c>'9'); return c-'0';
}
void solve(ll i,ll l,ll r,ll optl,ll optr){
    if(l>r) return;
    if(l == r){
        dp[i][l]=1e9;
        rep(j,optl,optr){
            if(j>=l) break;
            dp[i][l]=min(dp[i][l],dp[i-1][j]+cost[j+1][l]);
        }
        return;
    }
    ll mid=(l+r)/2;
    dp[i][mid]=1e9;
    ll optm;
    rep(j,optl,optr){
        if(j>=mid) break;
        if(dp[i-1][j]+cost[j+1][mid] <= dp[i][mid]){
            dp[i][mid]=dp[i-1][j]+cost[j+1][mid] ;
            optm=j;
        }
    }
    solve(i,l,mid-1,optl,optm);
    solve(i,mid+1,r,optm,optr);
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    scanf("%d %d",&n,&k);
    char ch;
    rep(i,1,n ) rep(j,1,n) {
        ch='#';
        while(!isdigit(ch)) ch=getchar();
        pr[i][j]=pr[i][j-1]+ch-'0';
    }
    rep(i,2,k) rep(j,1,n ) dp[i][j]=1e9;
    rep(i,1,n){
        rep(j,1,i-1) dp[1][i]+=pr[j][i]-pr[j][j];
        rev(j,i-1,1) cost[j][i]=cost[j+1][i]+pr[j][i]-pr[j][j];
    }
   // rep(i,1,n) cout<<i<<" "<<dp[1][i]<<endl;
 
    rep(i,2,k) solve(i,i,n,1,n);
    printf("%d",dp[k][n]);
}