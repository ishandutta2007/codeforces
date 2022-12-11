#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int w,b;
double dp[maxn][maxn][2];
bool vis[maxn][maxn][2];
double solve(int w,int b,int k)
{
	if(vis[w][b][k])return dp[w][b][k];
	if(!w)return 0.0;
	if(!b)
	{
		if(!k)return 1.0;
		else return 0.0;
	}
	vis[w][b][k]=1;
	double p=(double)w/(double)(w+b);
	if(!k)
	{
		dp[w][b][k]=p+(1-p)*solve(w,b-1,1);
	}
	else
	{
		double t=(double)w/(double)(w+b-1);
		if(b>=2&&w>=1)dp[w][b][k]=(1-p)*t*solve(w-1,b-1,0)+(1-p)*(1-t)*solve(w,b-2,0);
		else if(b>=2)dp[w][b][k]=(1-p)*solve(w,b-2,0);
		else if(w>=1)dp[w][b][k]=(1-p)*solve(w-1,b-1,0);
		else dp[w][b][k]=0.0; 
	}
	return dp[w][b][k];
}
int main()
{
	scanf("%d%d",&w,&b);
	printf("%.10f\n",solve(w,b,0));
	return 0;
}