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
vector<int>v[2000005];
char str[2000005];
bool ky[2000005];
int zy[2000005];
int main()
{
	int n,m,q,x,y;
	n=read();
	m=read();
	for(int i=1;i<=m+1;i++)v[0].push_back(0);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str+1);
		v[i].push_back(0);
		for(int j=1;j<=m;j++)
		{
			if(str[j]=='.')x=0;
			else x=1;
			v[i].push_back(x);
			if(v[i][j-1]==1&&v[i-1][j]==1)ky[j]=true;
		}
	}
	zy[0]=1;
	for(int i=1;i<=m;i++)
	{
		if(ky[i]==true)zy[i]=i;
		else zy[i]=zy[i-1];
		//printf("%d\n",zy[i]);
	}
	q=read();
	for(int i=1;i<=q;i++)
	{
		x=read();
		y=read();
		if(x>=zy[y])printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}