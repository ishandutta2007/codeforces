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
const int V=3000*3000;
double f[V][2];
int a[3100],n;
int main()
{
	while(~scanf("%d",&n))
	{
		int inv=0;
		for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
		for(int i=0;i<n;i++)
		for(int j=0;j<i;j++)
		if(a[j]>a[i])inv++;
		f[0][0]=f[0][1]=0.0;
		for(int i=1;i<=inv;i++)
		{
			f[i][0]=f[i-1][1]+1;
			if(i!=(n-1)*n/2)
			f[i][1]=3.0+f[i-1][0];
			else f[i][1]=f[i-1][0]+1.0;
		}
		printf("%8f\n",f[inv][0]);
	}
	return 0;
}