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
    int t,n,k1,k2,max1,max2,x;
	t=read();
	for(int sth=1;sth<=t;sth++)
	{
		n=read();
		k1=read();
		k2=read();
		max1=-1000000000;
		max2=-1000000000;
		for(int i=1;i<=k1;i++)x=read(),max1=max(max1,x);
		for(int i=1;i<=k2;i++)x=read(),max2=max(max2,x);
		if(max1>max2)printf("YES\n");
		else printf("NO\n");
	}
    return 0;
}