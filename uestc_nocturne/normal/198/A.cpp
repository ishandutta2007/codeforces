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
int k,n,b,t;
int main()
{
	while(~scanf("%d%d%d%d",&k,&b,&n,&t))
	{
		int ret=n;
		LL te=1;
		if(k==1)
		{
			LL last=1+(LL)n*b;
			LL now=t;
			ret=0;
			while(1)
			{
				if(now>=last)break;
				now+=b;ret++;
			}
		}
		else
		{
			while(1)
			{
				if(te*(k-1+b)> (LL)(k-1)*t+b)break;
				te*=k;ret--;
			}
			ret=max(0,ret+1);
		}
		cout<<ret<<endl;
	}
}