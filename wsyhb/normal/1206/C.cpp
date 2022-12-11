#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int mx=2e5+5,mx1=4e5+5;
int a[mx],s[mx1];
int main()
{
	int n,x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		if(i%2==1) a[i]=2*i-1,a[n+i]=2*i;
		else a[i]=2*i,a[n+i]=2*i-1;
	}
	for(int i=1;i<=4*n;i++) s[i]=s[i-1]+a[(i-1)%(2*n)+1];
	x=s[n]-s[0],y=s[n+1]-s[1];
	for(int i=n;i<=3*n;i++)
	{
		if((i-n)%2==0&&s[i]-s[i-n]!=x)
		{
			printf("NO\n");
			return 0;
		}
		if((i-n)%2==1&&s[i]-s[i-n]!=y)
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for(int i=1;i<=2*n;i++) printf("%d ",a[i]);
	printf("\n");
	return 0;
}