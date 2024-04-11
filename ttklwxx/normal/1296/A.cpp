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
    int t,n,x;
    bool f1,f2;
    t=read();
    for(int i=1;i<=t;i++)
    {
    	n=read();
    	f1=false;
    	f2=false;
    	for(int i=1;i<=n;i++)
		{
			x=read();
			if(x%2==1)
			{
				f1=true;
			}
			else
			{
				f2=true;
			}
		}
		if(f1==true&&f2==true)printf("YES\n");
		else if(f1==true&&n%2==1)printf("YES\n");
		else printf("NO\n");
	}
    return 0;
}