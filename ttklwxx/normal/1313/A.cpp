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
int main()
{
	int t,a,b,c,ans=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		a=read();
		b=read();
		c=read();
		ans=0;
		if(a>0)a--,ans++;
		if(b>0)b--,ans++;
		if(c>0)c--,ans++;
		if(a<b)swap(a,b);
		if(b<c)swap(b,c);
		if(a<c)swap(a,c);
		if(a>0&&b>0)a--,b--,ans++;
		if(a>0&&c>0)a--,c--,ans++;
		if(b>0&&c>0)b--,c--,ans++;
		if(a>0&&b>0&&c>0)a--,b--,c--,ans++;
		printf("%d\n",ans);
	}
	return 0;
}