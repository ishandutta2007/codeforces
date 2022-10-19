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
    int t,a,b,ans;
	t=read();
	for(int i=1;i<=t;i++)
	{
		a=read();
		b=read();
		if(a>b)swap(a,b);
		ans=(b-a)/5+((b-a)%5)/2+((b-a)%5)%2;
		printf("%d\n",ans);
	} 
    return 0;
}