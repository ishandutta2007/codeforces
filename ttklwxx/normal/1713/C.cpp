#include<iostream>
#include<cstdio>
#include<cmath>
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
int n,i,s,m,a[100001];
int p(int n)
{
  	return pow(ceil(sqrt(n)),2);
}
int main()
{
	int t;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
    	for(s=p(m=i=--n);i>=0;(s-i)<=m?a[i--]=s-i:s=p(m=i));
    	for(;++i<=n;printf("%d%c",a[i]," \n"[i==n]));
  	}
}