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
	int t,n,k1,k2,w,b;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k1=read();
		k2=read();
		w=read();
		b=read();
		if(k1>k2)swap(k1,k2);
		if(k1+(k2-k1)/2<w)
		{
			printf("NO\n");
			continue;
		}
		if(n-k2+(k2-k1)/2<b)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
	} 
	return 0;
}