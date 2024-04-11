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
    int t,n,m;
    t=read();
    for(int i=1;i<=t;i++)
    {
    	n=read();
    	m=read();
    	printf("%d\n",(n*m+1)/2);
	}
	return 0;
}