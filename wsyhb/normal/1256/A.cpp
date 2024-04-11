#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int a,b,n,s;
		scanf("%d%d%d%d",&a,&b,&n,&s);
		int x=s%n;
		if(b<x)
		{
			printf("NO\n");
			continue;
		}
		if(b%n<x) b=b-b%n-n+x;
		else if(b%n>x) b=b-b%n+x;
		if((s-b)/n<=a) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}