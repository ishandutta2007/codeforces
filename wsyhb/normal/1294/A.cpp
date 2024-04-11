#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c,n;
		scanf("%d%d%d%d",&a,&b,&c,&n);
		int x=(a+b+c+n)/3;
		if((a+b+c+n)%3!=0||x<a||x<b||x<c) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}