#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
typedef long long LL;
int n,m,id,i,j,re,a,b,x;
double ans,te;
int main()
{
	while(~scanf("%d%d%d",&n,&m,&id))
	{
		a=0;b=0;
		for(i=0;i<m;i++)
		{
			scanf("%d",&x);
			if(i+1==id)a+=x-1;
			else b+=x;
		}
		if(a+b+1<n){puts("-1.0");continue;}
		ans=0.0;
		for(i=1;i<=min(n-1,a);i++)
		{
			re=n-1-i;
			te=1.0;
		//	printf("%d %d %d %d\n",i,re,a,b);
			for(j=1;j<=i;j++)
			{
				te*=(double)(a-j+1);
				te/=(double)j;
				te/=(double)(a+b-j+1);
				te*=(double)j;
			}
			for(j=1;j<=re;j++)
			{
				te*=(double)(b-j+1);
				te/=(double)j;
				te/=(double)(a+b-j-i+1);
				te*=(double)(i+j);
			}
			ans+=te;
		}
		printf("%.8f\n",ans);
	}
}