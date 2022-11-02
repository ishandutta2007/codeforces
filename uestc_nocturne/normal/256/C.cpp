/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
int sg(LL x)
{
	if(x<=3)return 0;
	if(x<=15)return 1;
	if(x<=81)return 2;
	if(x<=6723)return 0;
	if(x<=50625)return 3;
	if(x<=1000000)return 1;
	int r=sqrt(1.0*x);
	r--;while((LL)(r+1)*(r+1)<=x)r++;
	int l=sqrt(1.0*r);l++;
	while(LL(l-1)*(l-1)*(l-1)*(l-1)>=x)l--;
	if(r<82||l>6723)return 0;
	if(r<50626)return 1;
	return 2;
}
int n;
int main()
{
	while(~scanf("%d",&n))
	{
		LL x;
		int s=0;
		for(int i=0;i<n;i++)
		{
			scanf("%I64d",&x);
			s^=sg(x);
		}
		if(s)puts("Furlo");
		else puts("Rublo");
	}
}