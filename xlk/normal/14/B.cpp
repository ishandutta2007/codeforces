#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int n,m,s=0,e=1000,x,y,z;
int main()
{
	scanf("%d %d",&n,&z);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		if(x>y)
			swap(x,y);
		s=max(s,x);
		e=min(e,y);
	}
	if(s>e)
		puts("-1");
	else
		printf("%d\n",s<=z&&z<=e?0:min(abs(e-z),abs(z-s)));
	return 0;
}