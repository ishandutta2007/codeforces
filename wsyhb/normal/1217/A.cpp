#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c,ans=0;
		scanf("%d%d%d",&a,&b,&c);
		ans=(a+b+c)/2-a+1;
		if(ans>c) printf("0\n");
		else printf("%d\n",c-max(ans,0)+1);
	}
	return 0;
}