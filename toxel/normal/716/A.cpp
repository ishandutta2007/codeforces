#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#define N 100001
int main()
{
	int n,c,time[N],i,total=1;
	scanf("%d%d",&n,&c);
	for (i=0;i<n;i++)
		scanf("%d",&time[i]);
	for (i=0;i<n-1;i++)
		if (time[i+1]-time[i]>c)
			total=1;
		else
			total++;
	printf("%d",total);
	return 0;
}