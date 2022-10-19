#include<iostream>
#include<cstdio>
#define int long long
#define inf 1121131433448687LL
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int dx[100005][2],dy[100005][2];
int dp[100005][20][2][2];
int jdz(int x)
{
	if(x<0)return -x;
	return x;
}
int findmen(int x1,int id1,int x2,int id2)
{
	if(x1==x2)return jdz(dx[x1][id1]-dx[x2][id2])+jdz(dy[x1][id1]-dy[x2][id2]);
	int las0=inf,las1=inf,now0,now1;
	if(id1==0)las0=0;
	else las1=0;
	for(int i=19;i>=0;i--)
	{
		if(x1+(1<<i)<=x2)
		{
			now0=min(las0+dp[x1][i][0][0],las1+dp[x1][i][1][0]);
			now1=min(las0+dp[x1][i][0][1],las1+dp[x1][i][1][1]);
			las0=now0;
			las1=now1;
			x1+=(1<<i);
		}
	}
	if(id2==0)return las0;
	else return las1;
}
int findans(int x1,int y1,int x2,int y2)
{
	int sth1=max(x1,y1),sth2=max(x2,y2),ans=inf;
	//printf("orz%lld %lld\n",sth1,sth2);
	for(int i=0;i<=1;i++)
	{
		for(int j=0;j<=1;j++)
		{
			int now=jdz(x1-dx[sth1][i])+jdz(y1-dy[sth1][i]);
			now+=findmen(sth1,i,sth2-1,j);
			if(j==0)now+=jdz(x2-dx[sth2-1][j]-1)+jdz(y2-dy[sth2-1][j])+1;
			else now+=jdz(x2-dx[sth2-1][j])+jdz(y2-dy[sth2-1][j]-1)+1;
			ans=min(ans,now);
		}
	}
	return ans;
}
signed main()
{
	int n;
	n=read();
	for(int i=1;i<=n-1;i++)
	{
		dx[i][0]=read();
		dy[i][0]=read();
		dx[i][1]=read();
		dy[i][1]=read();
	}
	for(int i=1;i<=n-2;i++)
	{
		for(int j=0;j<=1;j++)
		{
			for(int k=0;k<=1;k++)
			{
				if(j==0)dp[i][0][j][k]=jdz(dx[i+1][k]-(i+1))+jdz(dy[i+1][k]-dy[i][0])+1;
				else dp[i][0][j][k]=jdz(dy[i+1][k]-(i+1))+jdz(dx[i+1][k]-dx[i][1])+1;
			}
		}
	}
	for(int i=1;i<=19;i++)
	{
		for(int j=1;j<=n-(1<<i);j++)
		{
			for(int k=0;k<=1;k++)
			{
				for(int l=0;l<=1;l++)
				{
					dp[j][i][k][l]=inf;
					for(int sth=0;sth<=1;sth++)
					{
						dp[j][i][k][l]=min(dp[j][i][k][l],dp[j][i-1][k][sth]+dp[j+(1<<(i-1))][i-1][sth][l]);
					}
				}
			}
		}
	}
	int x1,y1,x2,y2;
	int q=read();
	for(int i=1;i<=q;i++)
	{
		x1=read();
		y1=read();
		x2=read();
		y2=read();
		if(max(x1,y1)>max(x2,y2))
		{
			swap(x1,x2);
			swap(y1,y2);
		}
		//printf("%lld %lld %lld %lld\n",x1,y1,x2,y2);
		if(max(x1,y1)==max(x2,y2))
		{
			printf("%lld\n",jdz(x1-x2)+jdz(y1-y2));
			continue;
		}
		printf("%lld\n",findans(x1,y1,x2,y2));
	}
}