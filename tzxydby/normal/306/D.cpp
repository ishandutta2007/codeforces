#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
int n;
int main()
{
	scanf("%d",&n);
	if(n<=4)
	{
		puts("No solution");
		return 0;
	}
	double ag=0,p=pi*2/n,l=500,x=-l,y=0;
	for(int i=1;i<n;i++)
	{
		x+=cos(ag)*l,y+=sin(ag)*l;
		printf("%.5lf %.5lf\n",x,y);
		ag+=p;
		l+=0.01;
	}
	printf("%.5lf %.5lf\n",x-y/tan(ag),0.0);
	return 0;
}