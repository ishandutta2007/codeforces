#include<bits/stdc++.h>
using namespace std;
string c1="23456789TJQKA",c2="SDHC";
const int N=60;
int dp[N][N][N][N],n,a[N];
char b[10];
int ok(int x,int y){return x%13==y%13||x/13==y/13;}
int dfs(int p,int x,int y,int z)
{
	int &f=dp[p][x][y][z];
	if(f!=-1)
		return f;
	if(p<=3)
		return f=(ok(y,z)&&ok(x,z));
	f=0;
	if(ok(y,z))
		f|=dfs(p-1,a[p-3],x,z);
	if(ok(a[p-3],z))
		f|=dfs(p-1,z,x,y);
	return f;
}
int sol()
{
	memset(dp,-1,sizeof(dp));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",b);
		for(int x=0;x<13;x++)
			for(int y=0;y<4;y++)
				if(b[0]==c1[x]&&b[1]==c2[y])
					a[i]=x*13+y;
	}
	if(n==1)
		return 1;
	if(n==2)
		return ok(a[1],a[2]);
	return dfs(n,a[n-2],a[n-1],a[n]);
}
int main()
{
	int T=1;
	while(T--)
		puts(sol()?"YES":"NO");
	return 0;
}