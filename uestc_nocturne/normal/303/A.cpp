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
const int V=100100;
int a[V],b[V],c[V],n;
int main()
{
	while(~scanf("%d",&n))
	{
		if(n%2==0)
		{
			puts("-1");
			continue;
		}
		for(int i=0;i<n;i++)
		a[i]=i,c[i]=n-1-i,b[i]=(c[i]-a[i]+n)%n;
		for(int i=0;i<n;i++)printf("%d ",a[i]);puts("");
		for(int i=0;i<n;i++)printf("%d ",b[i]);puts("");
		for(int i=0;i<n;i++)printf("%d ",c[i]);puts("");
	}
}