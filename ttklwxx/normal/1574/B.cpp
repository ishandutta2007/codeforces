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
	int t,a,b,c,m;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		a=read();
		b=read();
		c=read();
		if(a<b)swap(a,b);
		if(a<c)swap(a,c);
		if(b<c)swap(b,c);
		m=read();
		if(max(a-1,0)+max(b-1,0)+max(c-1,0)<m)printf("NO\n");
		else if(m<max(a-b-c-1,0))printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}