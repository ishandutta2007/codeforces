#include<bits/stdc++.h>
using namespace std;
long long n,p,d,w,x,y,g;
int main()
{
	scanf("%I64d%I64d%I64d%I64d",&n,&p,&w,&d);
	for(long long y=0,x;y<w;y++)
	{
		if((p-d*y)%w==0) 
			x=(p-d*y)/w;
		if(x>=0&&x+y<=n) 
		{
			printf("%I64d %I64d %I64d\n",x,y,n-x-y);
			return 0;
		}
	}
	puts("-1");
	return 0;
}