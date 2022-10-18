#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define M 500005
inline int read()
{
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int ans=0;
	while(isdigit(ch))
	{
		ans=ans*10+ch-48;
		ch=getchar();
	}
	return ans;
}
int suf[M][25];

int main()
{
	int n,m;
	cin>>n>>m;
	int x,y;
	for(int i=1;i<=n;i++)
	{
		x=read(),y=read();
		x++;
		if(suf[x][0]<y)
		{
			suf[x][0]=y;
		}
	}
	for(int i=1;i<=M;i++)
	{
		suf[i][0]=max(suf[i][0],suf[i-1][0]);
	}
	for(int i=1;i<=19;i++)
	{
		for(int j=1;j<=M;j++)
		{
			suf[j][i]=suf[suf[j][i-1]+1][i-1];
		}
	}
//	for(int i=1;i<=10;i++)
//	{
//		for(int j=0;j<=4;j++)
//		{
//			printf("%d ",suf[i][j]);
//		}
//		cout<<"\n";
//	}
	for(int i=1;i<=m;i++)
	{
		x=read(),y=read();
//		x++;
		int ans=0;
//		cout<<x<<endl;
		for(int j=19;j>=0;j--)
		{
			if(suf[x+1][j]<y&&suf[x+1][j]>x)
			{
				x=suf[x+1][j];
				ans+=(1<<j);
			}
//			cout<<x<<endl;
		}
		ans++;x=suf[x+1][0];
//		cout<<x<<endl;
		if(x<y) printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}