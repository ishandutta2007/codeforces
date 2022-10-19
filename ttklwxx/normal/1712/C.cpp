#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#define mod 998244353
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
int a[100005],las[100005],fir[100005];
int main()
{
	int t,n,maxn,mink;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)las[i]=0,fir[i]=0; 
		for(int i=1;i<=n;i++)a[i]=read(),las[a[i]]=i;
		for(int i=n;i>=1;i--)fir[a[i]]=i;
		maxn=0;
		mink=n;
		while(mink>=2&&a[mink-1]<=a[mink])mink--;
		if(mink==1)
		{
			printf("0\n");
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(i==fir[a[i]])
			{
				maxn=max(maxn,las[a[i]]);
				ans++;
			}
			if(i==maxn&&maxn>=mink-1)
			{
				printf("%d\n",ans);
				break;
			}
		}
	}
	return 0;
}