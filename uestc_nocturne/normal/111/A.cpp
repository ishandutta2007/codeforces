#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
typedef long long LL;
LL x;
int n,y,i;
int main()
{
	while(~scanf("%d%I64d%d",&n,&x,&y))
	{
		if(n>y){puts("-1");continue;}
		LL s=(LL)(n-1);
		y-=n;y++;
		s+=(LL)y*y;
		if(s<x){puts("-1");continue;}
		for(i=1;i<n;i++)printf("1\n");
		printf("%d\n",y);
	}
}