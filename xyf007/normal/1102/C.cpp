#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,x,y,a[101];
int main()
{
	scanf("%d%d%d",&n,&x,&y);
	if(x>y)
	{
		printf("%d",n);
		return 0;
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<=x)
		{
			sum++;
		}
	}
	printf("%d",(sum+1)/2);
	return 0;
}
//ff