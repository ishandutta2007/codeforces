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
	int t,n,s;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		if(n>=8)
		{
			s=0;
			while((n-s*5)%3!=0)s++;
			printf("%d %d %d\n",(n-5*s)/3,s,0);
		}
		else if(n==7)printf("0 0 1\n");
		else if(n==6)printf("2 0 0\n");
		else if(n==5)printf("0 1 0\n");
		else if(n==3)printf("1 0 0\n");
		else printf("-1\n"); 
	} 
	return 0;
}