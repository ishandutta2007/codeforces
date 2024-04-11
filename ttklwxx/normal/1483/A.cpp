#include<iostream>
#include<cstdio>
#include<vector>
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
int k[200005],cx[200005],rd[200005];
int tans[200005];
vector<int>f[200005]; 
int main()
{
	int t,n,m,x,mpos;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		for(int i=1;i<=m;i++)f[i].clear();
		for(int i=1;i<=n;i++)rd[i]=0;
		for(int i=1;i<=m;i++)
		{
			k[i]=read();
			for(int j=1;j<=k[i];j++)
			{
				x=read();
				rd[x]++;
				f[i].push_back(x);
			}
		}
		for(int i=1;i<=m;i++)tans[i]=0;
		flag=false;
		for(int i=1;i<=m;i++)
		{
			mpos=f[i][0];
			for(int j=1;j<k[i];j++)
			{
				if(rd[f[i][j]]<rd[mpos])mpos=f[i][j];
			}
			tans[i]=mpos;
			for(int j=0;j<k[i];j++)
			{
				if(f[i][j]==mpos)continue;
				rd[f[i][j]]--;
			}
		}
		for(int i=1;i<=n;i++)if(rd[i]>=(m+3)/2)flag=true;
		if(flag==true)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i=1;i<=m;i++)printf("%d ",tans[i]);
		printf("\n");
	} 
	return 0;
}