#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int a[110],b[110];

int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	if(N<M)
	{
		printf("0/1\n");
		return 0;
	}
	for(int i=0;i<=N;i++)
	{
		scanf("%d",a+i);
	}
	for(int i=0;i<=M;i++)
	{
		scanf("%d",b+i);
	}
	if(N==M)
	{
		int aa=abs(a[0]),bb=abs(b[0]);
		if(aa<bb) swap(aa,bb);
		int d=gcd(aa,bb);
		a[0]/=d,b[0]/=d;
		if(a[0]<0&&b[0]<0)
		{
			a[0]*=(-1);
			b[0]*=(-1);
		}
		else if(a[0]>0&&b[0]<0)
		{
			a[0]*=(-1);
			b[0]*=(-1);
		}
		printf("%d/%d\n",a[0],b[0]);
		return 0;
	}
	else if(N>M)
	{
		if(a[0]*b[0]>0)
		{
			printf("Infinity\n");
		}
		else printf("-Infinity\n");
	}
	return 0;
}