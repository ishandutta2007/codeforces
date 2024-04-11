#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define SZ 666666 
int k,n;
bool gg[SZ];
int main()
{
	scanf("%d%d",&n,&k);
	int l=1,r=n,c=0;
	for(int i=1;i<=k;i++)
	{
		int cur;
		if(!c) cur=l++; else cur=r--;
		gg[cur]=1;
		printf("%d ",cur);
		c=!c;
	}
	if(k&1)
	{
		for(int i=1;i<=n;i++) if(!gg[i]) printf("%d ",i);
	}
	else
	{
		for(int i=n;i>=1;i--) if(!gg[i]) printf("%d ",i);
	}
}