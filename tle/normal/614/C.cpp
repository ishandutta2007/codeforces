#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <limits>
#include <set>
#include <map>
using namespace std;
int n,xs[233333],ys[233333],px,py;
int main()
{
	scanf("%d%d%d",&n,&px,&py);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",xs+i,ys+i);
	}
	double maxd=0,mind=20000000000000LL;
	for(int i=0;i<n;i++)
	{
		maxd=max(maxd,sqrt(double(xs[i]-px)*(xs[i]-px)+double(ys[i]-py)*(ys[i]-py)));
	}
	for(int i=0;i<n;i++)
	{
		double x1=xs[i],y1=ys[i],x2=xs[(i+1)%n],y2=ys[(i+1)%n];
		double A=y1-y2,B=x2-x1,C=x1*y2-x2*y1;
		double x0=px,y0=py;
		double qx=(B*B*x0-A*B*y0-A*C)/(A*A+B*B),qy=(A*A*y0-A*B*x0-B*C)/(A*A+B*B);
		double cd=20000000000000LL;
		cd=min(cd,sqrt(double(x1-px)*(x1-px)+double(y1-py)*(y1-py)));
		cd=min(cd,sqrt(double(x2-px)*(x2-px)+double(y2-py)*(y2-py)));
		if(qx<min(x1,x2)||qx>max(x1,x2));else
		{
			cd=min(cd,fabs(A*x0+B*y0+C)/sqrt(A*A+B*B));
		}
		mind=min(mind,cd);
	}
	printf("%.23lf\n",asin(1)*2*(maxd*maxd-mind*mind));
}