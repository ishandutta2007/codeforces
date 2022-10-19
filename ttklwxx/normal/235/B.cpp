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
double pf[100001],he[100001],kn[100001];
int main()
{
    int n;
	n=read();
	double x;
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&x);
		pf[i]=pf[i-1]+x*(2*he[i-1]+1);
		he[i]=x*(he[i-1]+1);
	}
	printf("%.10f",pf[n]);
	return 0;
}