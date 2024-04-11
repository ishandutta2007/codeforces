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
char s[500005];
int f[500005];
bool vis[10005];
int main() 
{
	f[0]=0;
	for(int i=1;i<=1000;i++)
	{
		for(int j=0;j<=i-2;j++)
		{
			vis[f[j]^(f[i-2-j])]=true;
		}
		f[i]=0;
		while(vis[f[i]]==true)f[i]++;
		for(int j=0;j<=i-2;j++)
		{
			vis[f[j]^(f[i-2-j])]=false;
		}
	}
	for(int i=1001;i<=500000;i++)f[i]=f[i-34];
	int t,n,rs,bs;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",s+1);
		rs=0;
		bs=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='R')rs++;
			else bs++;
		}
		if(rs>bs)
		{
			printf("Alice\n");
			continue;
		}
		if(bs>rs)
		{
			printf("Bob\n");
			continue;
		}
		int l=1,r,ans=0;
		for(;l<=n;l=r+1)
		{
			r=l;
			while(r<=n-1&&s[r]!=s[r+1])r++;
			ans^=f[r-l+1];
		}
		if(ans==0)printf("Bob\n");
		else printf("Alice\n");
	}
	return 0;
}