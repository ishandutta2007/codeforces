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
int Pow(int y,int P)
{
	int ret=1,x=3;
	while(y)
	{
		if(y&1)ret=(LL)ret*x%P;
		x=(LL)x*x%P;y/=2;
	}
	return ret;
}
int n,m;
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		int ret=Pow(n,m);
		ret--;
		if(ret<0)ret+=m;
		printf("%d\n",ret);
	}
}