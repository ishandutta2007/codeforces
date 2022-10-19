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
	int t,m,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		m=read();
		n=read();
		if(m%n==0)printf("YES\n");
		else printf("NO\n");
	} 
	return 0;
}