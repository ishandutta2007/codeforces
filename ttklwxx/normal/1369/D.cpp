#include<iostream>
#include<cstdio>
#define mod 1000000007
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
int f[2000004];
int main()
{
    int t,n,ans;
    t=read();
    f[1]=f[2]=0;
    f[3]=4;
    for(int i=4;i<=2000000;i++)
    {
    	f[i]=(1LL*f[i-1]+2LL*f[i-2])%mod;
    	if(i%3==0)f[i]=(f[i]+4)%mod;
	}
    for(int greg=1;greg<=t;greg++)
    {
    	n=read();
    	printf("%d\n",f[n]);
	}
	return 0;
}