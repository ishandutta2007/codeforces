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
int a[V],n,D;
int main()
{
	while(~scanf("%d%d",&n,&D))
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int p=0;
		LL ans=0;
		for(int i=0;i<n;i++)
		{
			while(p+1<n&&a[p+1]-a[i]<=D)p++;
			ans+=(LL)(p-i)*(p-i-1)/2;
		//	cout<<p<<endl;
		}
		cout<<ans<<endl;
	}
}