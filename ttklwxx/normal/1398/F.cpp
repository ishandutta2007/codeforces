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
char s[1000005];
int f0[1000005],f1[1000005];
int fa[1000005];
vector<int>v[1000005];
int findf(int n)
{
	if(fa[n]==n)return n;
	return fa[n]=findf(fa[n]);
}
int main()
{
	int n,ans,x;
	n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0'||s[i]=='?')f0[i]=f0[i-1]+1;
		else f0[i]=0;
		if(s[i]=='1'||s[i]=='?')f1[i]=f1[i-1]+1;
		else f1[i]=0;
		v[max(f0[i],f1[i])].push_back(i);
	}
	for(int i=1;i<=n+1;i++)fa[i]=i; 
	for(int i=1;i<=n;i++)
	{
		ans=0;
		x=findf(1);
		while(x<=n)
		{
			ans++;
			if(x+i>n)break;
			x=findf(x+i);
		}
		for(int j=0;j<v[i].size();j++)
		{
			fa[v[i][j]]=v[i][j]+1;
		}
		printf("%d ",ans);
	}
	printf("\n");
	return 0;
}