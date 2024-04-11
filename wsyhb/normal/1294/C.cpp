#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,a,b;
		scanf("%d",&n);
		a=b=-1;
		for(int i=2;i*i<=n;i++)
			if(n%i==0)
			{
				a=i;
				break;
			}
		if(a==-1)
		{
			printf("NO\n");
			continue;
		}
		n/=a;
		for(int i=a+1;i*i<=n;i++)
			if(n%i==0)
			{
				b=i;
				break;
			}
		if(b==-1)
		{
			printf("NO\n");
			continue;
		}
		n/=b;
		if(n>b) printf("YES\n%d %d %d\n",a,b,n);
		else printf("NO\n");
	}
	return 0;
}