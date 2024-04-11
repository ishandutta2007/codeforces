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
    int n;
    n=read();
    double ans=0;
	for(int i=1;i<=n;i++)ans+=((double)1.0/i);
	printf("%.6lf",ans); 
    return 0;
}