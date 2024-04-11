#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
int gcd(int x,int y)
{
	if(!x)return y;
	if(!y)return x;
	return gcd(y,x%y);
}
int s[120],n,fl,gd;
int main()
{
	while(~scanf("%d%d%d",&s[0],&s[1],&n))
	{
		fl=0;
		while(n>0)
		{
			gd=gcd(s[fl],n);
			n-=gd;
			if(n==0)break;
			fl^=1;
		}
		if(fl==0)puts("0");
		else puts("1");
	}
}