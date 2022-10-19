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
void write(int x)
{
	if(x<1000)putchar('0');
	if(x<100)putchar('0');
	if(x<10)putchar('0');
	printf("%d\n",x);
}
int sta[300001],ttop;
int main()
{
	int t,n,l,r;
	t=read();
	for(int i=1;i<=t;i++)
	{
		n=read();
		r=0;
		ttop=0;
		for(int l=1;l<=n;l=r+1)
		{
			r=n/(n/l);
			sta[++ttop]=n/l;
		}
		printf("%d\n%d ",ttop+1,0);
		for(int i=ttop;i>=1;i--)printf("%d ",sta[i]);
		printf("\n");
	}
	return 0;
}