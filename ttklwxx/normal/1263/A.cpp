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
    int t,a,b,c;
	t=read();
	for(int i=1;i<=t;i++)
	{
		a=read();
		b=read();
		c=read();
		if(a>b)swap(a,b);
		if(a>c)swap(a,c);
		if(b>c)swap(b,c);
		printf("%d\n",min(c,a+b)+max((a+b-c)/2,0));
	} 
    return 0;
}