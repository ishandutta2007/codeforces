#include<bits/stdc++.h>
using namespace std;
const int N=10;
int n,a,b,c,x[N],y[N],px,py;
long long t,p[N];
long long sol(long long s,long long l){return (s+s+l-1)*l/2;}
long long cal(int px,int py,int x,int y)
{
	if(x>=px&&y>=py) return sol(1,x+y-px-py)+sol(1,2*n-x-y);
	if(x<px&&y>=py) return sol(px-x+1,2*n-px-y)+sol(px-x,y-py+1);
	if(x>=px&&y<py) return sol(y-py+1,2*n-x-py)+sol(py-y,x-px+1);
	if(x<px&&y<py) return sol(px+py-x-y,2*n-px-py+1);
}
int main()
{
	scanf("%d%lld%d%d%d",&n,&t,&a,&b,&c);
	x[1]=a,x[2]=a+c-1,x[3]=a,x[4]=a+c-1;
	y[1]=b,y[2]=b,y[3]=b+c-1,y[4]=b+c-1;
	px=py=1;
	for(int i=1;i<=4;i++)
	{
		if(cal(1,1,x[i],y[i])-abs(x[i]-1)-abs(y[i]-1)>t)
		{
			puts("Impossible");
			return 0;
		}
	}
	for(int k=1;k<=2*n-2;k++)
	{
		c=0;
		if(px<n)
		{
			for(int i=1;i<=5;i++)
			{
				if(i==5)
					c=1;
				if(p[i]+cal(px+1,py,x[i],y[i])>t)
					break;
			}
		}
		if(c)
		{
			printf("R");
			px++;
		}
		else
		{
			printf("U");
			py++;
		}
		for(int i=1;i<=4;i++)
			p[i]+=abs(px-x[i])+abs(py-y[i]);
	}
	return 0;
}