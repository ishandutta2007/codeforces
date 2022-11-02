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
int a[100100],n,i;
int main()
{
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		sort(a,a+n);
		if(a[n-1]==1)a[n-1]=2;
		else a[n-1]=1;
		sort(a,a+n);
		for(i=0;i<n;i++)printf("%d ",a[i]);puts("");
	}
}