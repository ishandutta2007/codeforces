#include<iostream>
#include<cstdio>
#include<cmath>
#define int long long
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
signed main()
{
	int t,d,k;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		d=read();
		k=read();
		flag=false;
		for(int i=0;i<=d/k;i++)
		{
			if((long long)(sqrt((d*d)/(k*k)-i*i))==i)
			{
				flag=true;
				break;
			}
		}
		if(flag==false)printf("Ashish\n");
		else printf("Utkarsh\n");
	}
	return 0;
}