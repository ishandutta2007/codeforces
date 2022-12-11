#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,n;
		scanf("%d%d%d",&a,&b,&n);
		if(n%3==0) printf("%d\n",a);
		if(n%3==1) printf("%d\n",b);
		if(n%3==2) printf("%d\n",a^b);
	}
	return 0;
}