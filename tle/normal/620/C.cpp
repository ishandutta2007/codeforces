#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <limits>
#include <set>
#include <map>
using namespace std;
int n,a[555555],ls[555555];
int app[555555],ln=0,ll[555555],lr[555555];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i), ls[i]=a[i];
	int le=0;
	sort(ls+1,ls+1+n);
	for(int i=1;i<=n;i++) a[i]=lower_bound(ls+1,ls+1+n,a[i])-ls;
	bool gg=1;
	for(int i=1;i<n;i++)
	{
		if(ls[i]==ls[i+1]) gg=0;
	}
	if(gg)
	{
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int cur=a[i];
		if(app[cur])
		{
			for(int j=le+1;j<=i;j++) app[a[j]]=0;
			ln++; ll[ln]=le+1; lr[ln]=i; le=i;
			continue;
		}
		app[cur]=1;
	}
	lr[ln]=n;
	printf("%d\n",ln);
	for(int i=1;i<=ln;i++) printf("%d %d\n",ll[i],lr[i]);
}