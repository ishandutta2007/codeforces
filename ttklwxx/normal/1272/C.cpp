#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
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
bool cx[26];
char str[200001],h[11];
signed main()
{
	int n,x,ans=0,lx=0;
	n=read();
	x=read();
	scanf("%s",str+1);
	for(int i=1;i<=x;i++)
	{
		scanf("%s",h);
		cx[h[0]]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(!cx[str[i]])
		{
			ans+=lx*(lx+1)/2;
			lx=0;
		}
		else lx++;
	}
	ans+=lx*(lx+1)/2;
	printf("%lld\n",ans);
	return 0;
}