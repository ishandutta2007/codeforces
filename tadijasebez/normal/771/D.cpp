#include <stdio.h>
#include <vector>
using namespace std;
const int N=80;
const int inf=1e9+7;
int min(int a, int b){ return a>b?b:a;}
int dp[N][N][N][2],n;
bool was[N][N][N][2];
vector<int> v,k,x;
int DP(int a, int b, int c, bool fl)
{
	if(a+b+c==n) return 0;
	if(was[a][b][c][fl]) return dp[a][b][c][fl];
	was[a][b][c][fl]=1;
	int sol=inf,i;
	if(a<v.size())
	{
		int ans=0;
		for(i=0;i<b;i++) if(k[i]>v[a]) ans++;
		for(i=0;i<c;i++) if(x[i]>v[a]) ans++;
		sol=min(sol,DP(a+1,b,c,1)+ans);
	}
	if(b<k.size() && !fl)
	{
		int ans=0;
		for(i=0;i<a;i++) if(v[i]>k[b]) ans++;
		for(i=0;i<c;i++) if(x[i]>k[b]) ans++;
		sol=min(sol,DP(a,b+1,c,0)+ans);
	}
	if(c<x.size())
	{
		int ans=0;
		for(i=0;i<a;i++) if(v[i]>x[c]) ans++;
		for(i=0;i<b;i++) if(k[i]>x[c]) ans++;
		sol=min(sol,DP(a,b,c+1,0)+ans);
	}
	return dp[a][b][c][fl]=sol;
}
char s[N];
int main()
{
	int i;
	scanf("%i",&n);
	scanf("%s",s+1);
	for(i=1;i<=n;i++)
	{
		if(s[i]=='V') v.push_back(i);
		else if(s[i]=='K') k.push_back(i);
		else x.push_back(i);
	}
	printf("%i\n",DP(0,0,0,0));
	return 0;
}