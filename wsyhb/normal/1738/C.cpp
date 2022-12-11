#include<bits/stdc++.h>
using namespace std;
const int max_n=100+5;
bool f[max_n][max_n][2],vis[max_n][max_n][2];
bool dp(int x,int y,int s)
{
	if(vis[x][y][s])
		return f[x][y][s];
	vis[x][y][s]=true;
	if(x+y==0)
		return f[x][y][s]=(s%2==0);
	if(x+y==1)
		return f[x][y][s]=((s+(x?0:1))%2==0);
	if(x>0)
	{
		bool ok=true;
		if(x>1&&!dp(x-2,y,s))
			ok=false;
		if(y>0&&!dp(x-1,y-1,s))
			ok=false;
		if(ok)
			return f[x][y][s]=true;
	}
	if(y>0)
	{
		bool ok=true;
		if(x>0&&!dp(x-1,y-1,s^1))
			ok=false;
		if(y>1&&!dp(x,y-2,s^1))
			ok=false;
		if(ok)
			return f[x][y][s]=true;
	}
	return false;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int cnt0=0;
		for(int i=1;i<=n;++i)
		{
			int a;
			scanf("%d",&a);
			cnt0+=(a%2==0);
		}
		puts(dp(cnt0,n-cnt0,0)?"Alice":"Bob");
	}
	return 0;
}