#include <bits/stdc++.h>
using namespace std;
int n,color[6][105][105],minn=0x7fffffff,to[6][3];
int chan_one(int x)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if((i+j+1)%2!=color[x][i][j]) cnt++;
	return cnt;
}
int chan_zero(int x)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if((i+j)%2!=color[x][i][j]) cnt++;
	return cnt;
}
int use(int x,int y)
{
	int ans=0;
	bool used[6];
	memset(used,0,sizeof(used));
	used[x]=used[y]=1;
	for(int i=1;i<=4;i++)
		ans+=to[i][used[i]+1];
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int k=1;k<=4;k++)
	{
		getchar();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				char ch;
				scanf("%c",&ch);
				color[k][i][j]=ch=='0'?0:1;
			}
			getchar();
		}
		to[k][1]=chan_one(k);
		to[k][2]=chan_zero(k);		
	}
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			if(i!=j)
				minn=min(minn,use(i,j));
	printf("%d",minn);
	return 0;
}