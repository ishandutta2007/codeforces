#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=100010;
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
int n,m,x[100010],s[100010],f[100010]; 
int main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)x[i]=read(),s[i]=read();
	f[0]=0;
	for(int i=1;i<=m;i++)
	{
		f[i]=i;
		bool flag=false;
		for(int j=1;j<=n;j++)if(x[j]+s[j]>=i&&x[j]-s[j]<=i)flag=true;
		if(flag)f[i]=f[i-1];
		for(int j=1;j<=n;j++)if(x[j]+s[j]<i)f[i]=min(f[i],f[max(0,2*x[j]-i-1)]+i-(x[j]+s[j]));
	}
	printf("%d\n",f[m]);
}