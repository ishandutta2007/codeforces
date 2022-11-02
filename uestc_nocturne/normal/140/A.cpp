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
const double pi=acos(-1.0);
int n,R,r;
int main()
{
	while(~scanf("%d%d%d",&n,&R,&r))
	{
		bool can=true;
		if(r>R)can=false;
		else if(n!=1)
		{
			if(2*r>R)can=false;
			else
			{
				double th=asin(1.0*r/(R-r));
				if(th*n-1e-12>pi)can=false;
			}
		}
		if(can)puts("YES");
		else puts("NO");
	}
}