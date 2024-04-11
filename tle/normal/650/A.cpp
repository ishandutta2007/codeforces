//By zzq
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <set>
#include <map>
using namespace std;
int n;
typedef long long ll; 
pair<int,int> sb[233333]; 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&sb[i].first,&sb[i].second);
	sort(sb+1,sb+1+n);
	ll x=0,y=0,xy=0;
	for(int i=1;i<=n;i++)
	{
		int tot;
		for(int j=i;j<=n;j++)
		{
			if(sb[j].first!=sb[i].first||sb[j].second!=sb[i].second) break;
			tot=j;
		}
		xy+=(ll)(tot-i)*(tot-i+1)/2;
		i=tot;
	}
	for(int i=1;i<=n;i++)
	{
		int tot;
		for(int j=i;j<=n;j++)
		{
			if(sb[j].first!=sb[i].first) break;
			tot=j;
		}
		x+=(ll)(tot-i)*(tot-i+1)/2;
		i=tot;
	}
	for(int i=1;i<=n;i++) swap(sb[i].first,sb[i].second);
	sort(sb+1,sb+1+n);
	for(int i=1;i<=n;i++)
	{
		int tot;
		for(int j=i;j<=n;j++)
		{
			if(sb[j].first!=sb[i].first) break;
			tot=j;
		}
		y+=(ll)(tot-i)*(tot-i+1)/2;
		i=tot;
	}
	cout<<x+y-xy<<"\n";
}