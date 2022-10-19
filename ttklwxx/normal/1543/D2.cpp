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
int yh(int x,int y,int k)
{
	int ans=0,jz=1,a,b;
	while(x>0||y>0)
	{
		a=x%k;
		b=y%k;
		x/=k;
		y/=k;
		ans=ans+(a-b+k)%k*jz;
		jz*=k;
	} 
	return ans;
}
int main()
{
	int t,n,k,sth;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		for(int i=0;i<n;i++)
		{
			if(i==0)printf("%d\n",0);
			else if(i%2==1)printf("%d\n",yh(i-1,i,k));
			else printf("%d\n",yh(i,i-1,k));
			fflush(stdout);
			sth=read();
			if(sth==1)break;
		}
	}
}