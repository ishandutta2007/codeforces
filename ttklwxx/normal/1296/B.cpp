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
    int t,n,sth;
	long long ans=0;
    sth=read();
    for(int i=1;i<=sth;i++)
    {
    	n=read();
    	t=0;
    	while(n>=10)
    	{
    		t+=n-n%10;
    		n=n%10+n/10;
		}
		t+=n;
		printf("%d\n",t);
	}
    return 0;
}