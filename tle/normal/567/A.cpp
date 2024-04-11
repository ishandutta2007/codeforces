#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
int n;
struct city
{
	int id,x;
}sb[233333];
bool operator < (city a,city b)
{
	return a.x<b.x;
}
int minn[233333],maxn[233333];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&sb[i].x);
		sb[i].id=i;
	}
	sort(sb+1,sb+1+n);
	sb[n+1].x=1000000005;
	sb[0].x=-1000000005;
	for(int i=1;i<=n;i++)
	{
		if(i==1) minn[sb[i].id]=sb[i+1].x-sb[i].x;
		else if(i==n) minn[sb[i].id]=sb[i].x-sb[i-1].x;
		else minn[sb[i].id]=min(sb[i].x-sb[i-1].x,sb[i+1].x-sb[i].x);
		maxn[sb[i].id]=max(sb[n].x-sb[i].x,sb[i].x-sb[1].x);
	}
	for(int i=1;i<=n;i++) printf("%d %d\n",minn[i],maxn[i]);
}