#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define append push_back
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(long long i=0;i<n;++i)
typedef double dd;
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
int visited[1005][1005],ans,n,m,k,i,p[100005];
char c[1005][1005];
int x,y;
void solve(int x,int y)
{
	if(x==0||y==0||x==n+1||y==m+1) return;
	if(c[x][y]=='*') 
		{
			ans++; 
			return;
		}
	if(visited[x][y]!=0) return;
	visited[x][y]=i;
	solve(x+1,y);
	solve(x,y+1);
	solve(x-1,y);
	solve(x,y-1);
	return;
}
int main()
{
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>c[i][j];
		}
	}
	for(i=1;i<=k;i++)
	{
		ans=0;
		cin>>x>>y;
		if(!visited[x][y]) solve(x,y);
		else ans=p[visited[x][y]];
		p[i]=ans;
		cout<<ans<<"\n";
	}
}