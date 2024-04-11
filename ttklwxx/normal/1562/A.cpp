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
	int t,l,r;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		l=read();
		r=read();
		if(r>=2*l)printf("%d\n",(r-1)/2);
		else printf("%d\n",r-l);
	} 
	return 0;
}