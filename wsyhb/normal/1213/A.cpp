#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,s1=0,s2=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x&1) s1++;
		else s2++;
	}
	printf("%d",min(s1,s2));
	return 0;
}