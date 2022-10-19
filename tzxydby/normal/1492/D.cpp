#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a,b,k,x[N],y[N];
int main()
{
	scanf("%d%d%d",&a,&b,&k);
	if(b==1)
	{
		if(k)
			puts("No");
		else
		{
			puts("Yes");
			printf("1");
			for(int i=1;i<=a;i++)
				printf("0");
			puts("");
			printf("1");
			for(int i=1;i<=a;i++)
				printf("0");
			puts("");
		}
		return 0;
	}
	if(a+b-2<k)
	{
		puts("No");
		return 0;
	}
	int n=a+b;
	x[1]=y[1]=x[n-k]=y[n]=1;
	b-=2;
	for(int i=2;b&&i<=n;i++)
	{
		if(x[i]+y[i]==0)
		{
			x[i]=y[i]=1;
			b--;
		}
	}
	if(b)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	for(int i=1;i<=n;i++)
		printf("%d",x[i]);
	puts("");
	for(int i=1;i<=n;i++)
		printf("%d",y[i]);
	return 0;
}