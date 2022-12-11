#include<bits/stdc++.h>
#define maxn 50
using namespace std;
int n;
int a[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int has=0;
	for(int i=1;i<=n;++i)if(a[i]==1)has++;
	if(has==0)
	{
		int minv=100;
		for(int i=1;i<=n;++i)minv=min(a[i],minv);
		int num=0;
		for(int i=1;i<=n;++i)if(minv==a[i])num++;
		if(num<=n/2)
		{
			puts("Alice");
		}
		else
		{
			puts("Bob");
		}
	}
	else if(has<=n/2)
	{
		puts("Alice");
	}
	else
	{
		puts("Bob");
	}
	return 0;
}