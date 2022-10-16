#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define append push_back
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(long long i=0;i<n;++i)
typedef long long ll;
ll exp(ll n, ll m, ll md){
    ll a = 1;
    while (m > 0){
        if (m&1) a = (a * n%md) % md;
        m /= 2;
        n = (n*n) % md;
    }
    return a % md;
}
int dp[31][31][51];
int solve(int x,int y,int k)
{
	if(dp[x][y][k]||x*y==k||!k) return dp[x][y][k];
	int mn=1e9+5;
	for(int i=1;i<=x/2;i++)
	{
		for(int j=0;j<=k;j++)
		{
			mn=min(mn,y*y+solve(i,y,k-j)+solve(x-i,y,j));
		}
	}
	for(int i=1;i<=y/2;i++)
	{
		for(int j=0;j<=k;j++)
		{
			mn=min(mn,x*x+solve(x,i,k-j)+solve(x,y-i,j));
		}
	}
	dp[x][y][k]=mn;
	return dp[x][y][k];


}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		cout<<solve(n,m,k)<<endl;
	}
}