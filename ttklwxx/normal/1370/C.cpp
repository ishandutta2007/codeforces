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
bool pri(int n)
{
	if(n==1)return false;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)return false;
	}
	return true;
} 
int main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		if(n==1)printf("FastestFinger\n");
		else if(n==2)printf("Ashishgup\n");
		else if(n%2==1)printf("Ashishgup\n");
		else if(pri(n/2))printf("FastestFinger\n");
		else if(n%4==2)printf("Ashishgup\n");
		else
		{
			while(n%2==0)n/=2;
			if(n!=1)printf("Ashishgup\n");
			else printf("FastestFinger\n");
		}
	}
	return 0;
}