#include<iostream>
#include<cstdio>
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
int sl[200005][26];
char str[300005];
int main()
{
	int t,n,k,ans,maxn;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		ans=0;
		scanf("%s",str+1);
		for(int i=1;i<=n;i++)
		{
			if((i-1)%k+1<=k/2)sl[(i-1)%k+1][str[i]-'a']++;
			else sl[k+1-(i-1)%k-1][str[i]-'a']++;
		}
		for(int i=1;i<=k/2+1;i++)
		{
			maxn=0;
			for(int j=0;j<26;j++)maxn=max(maxn,sl[i][j]);
			for(int j=0;j<26;j++)sl[i][j]=0;
			ans+=maxn;
		}
		printf("%d\n",n-ans);
	}
	return 0;
}