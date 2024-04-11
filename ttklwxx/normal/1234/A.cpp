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
    int t,n,s=0;
    t=read();
    for(int i=1;i<=t;i++)
    {
    	n=read();
    	s=0;
    	for(int j=1;j<=n;j++)s+=read();
    	if(s%n==0)printf("%d\n",s/n);
    	else printf("%d\n",s/n+1);

	}
    return 0;
}