#include<bits/stdc++.h>
using namespace std;
const int N=100005,M=55,mod=1e9+7;
int n,d,dp[M][2][2][N],s[N],x[N],y[N],ch[N][10],m,a[N],f[N],q[N],bg,ed,ans;
char rs[N],rx[N],ry[N];
inline void add(int &a,int b){a+=b;if(a>=mod)a-=mod;}
void ins(int l,int r)
{
	int u=1;
	for(int i=l;i<=r;i++)
	{
		int x=s[i];
		if(!ch[u][x])
			ch[u][x]=++m;
		u=ch[u][x];
	}
	a[u]=1;
}
int main()
{
	scanf("%s%s%s",rs+1,rx+1,ry+1);
	n=strlen(rs+1),d=strlen(rx+1);
	for(int i=1;i<=n;i++)
		s[i]=rs[i]-'0';
	for(int i=1;i<=d;i++)
		x[i]=rx[i]-'0',y[i]=ry[i]-'0';
	m=1;
	for(int i=1;i<=n;i++)
		if(i+d/2-1<=n)
			ins(i,i+d/2-1);
	for(int i=0;i<=9;i++)
	{
		int v=ch[1][i];
		if(v)
		{
			f[v]=1;
			q[ed++]=v;
		}
		else
			ch[1][i]=1;
	}
	while(bg<ed)
	{
		int u=q[bg++];
		for(int i=0;i<=9;i++)
		{
			int v=ch[u][i];
			if(v)
			{
				f[v]=ch[f[u]][i];
				q[ed++]=v;
			}
			else
				ch[u][i]=ch[f[u]][i];
		}
	}
	dp[1][0][0][1]=1;
	for(int i=1;i<=d;i++)
	{
		for(int f1=0;f1<2;f1++)
		{
			for(int f2=0;f2<2;f2++)
			{
				for(int l=0;l<=m;l++)
				{
					if(!dp[i][f1][f2][l])
						continue;
					for(int v=0;v<=9;v++)
					{
						if(f1==0&&v<x[i])
							continue;
						if(f2==0&&v>y[i])
							continue;
						int nx=ch[l][v];
						if(a[nx])
							nx=0;
						add(dp[i+1][f1|(v>x[i])][f2|(v<y[i])][nx],dp[i][f1][f2][l]);
					}
				}
			}
		}
	}
	for(int f1=0;f1<2;f1++)
		for(int f2=0;f2<2;f2++)
			add(ans,dp[d+1][f1][f2][0]);
	printf("%d\n",ans);
	return 0;
}