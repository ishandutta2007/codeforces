#include<iostream>
#include<cstdio>
#define int long long
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
int a[3][300001];
signed main()
{
	int n,q,ans=0,r,c;
	n=read();
	q=read();
	for(int i=1;i<=q;i++)
	{
		r=read()-1;
		c=read();
		if(a[r][c]==0)
		{
			if(a[r^1][c]==1)ans++;
			if(c>=2&&a[r^1][c-1]==1)ans++;
			if(c<=n-1&&a[r^1][c+1]==1)ans++;
			a[r][c]=1;
		}
		else
		{
			if(a[r^1][c]==1)ans--;
			if(c>=2&&a[r^1][c-1]==1)ans--;
			if(c<=n-1&&a[r^1][c+1]==1)ans--;
			a[r][c]=0;
		}
		if(ans==0)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}