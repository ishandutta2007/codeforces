#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio> 
using namespace std;
#define ll long long
inline ll read()
{
	ll t=0,f=1;char tmp=getchar();
	while(tmp<'0'||tmp>'9')	{if(tmp=='-')	f=-1;tmp=getchar();}
	while(tmp>='0'&&tmp<='9')	t=t*10+tmp-48,tmp=getchar();
	return t*f;
}
int n,a,b;
int main()
{
	n=read();a=read();b=read();
	for(int i=min(a,b);i>=0;i--)
	{
		if((a/i+b/i)>=n)	
		{
			printf("%d\n",i);
			return 0;
		}
	}
}