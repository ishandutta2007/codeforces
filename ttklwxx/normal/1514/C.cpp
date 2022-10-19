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
int gcd(int x,int y)
{
	while(x^=y^=x^=y%=x);
	return y;
}
bool xq[200005];
int main()
{
	int n,sl=0,nans=1;
	n=read();
	for(int i=1;i<=n;i++)
	{
		if(gcd(i,n)==1)
		{
			xq[i]=true;
			sl++;
			nans=1LL*nans*i%n;
		}
	}
	if(nans!=1)
	{
		xq[nans]=false;
		sl--;
	}
	printf("%d\n",sl);
	for(int i=1;i<=n;i++)
	{
		if(xq[i])printf("%d ",i);
	}
	printf("\n");
	return 0;
}