#include <stdio.h>
int max(int a, int b)
{
	if(a>b) return a;
	else return b;
}
bool Check(int x1, int y1, int x2, int y2, int a, int b)
{
	if(x1+x2<=a && max(y1,y2)<=b) return true;
	if(x1+x2<=b && max(y1,y2)<=a) return true;
	if(x1+y2<=a && max(y1,x2)<=b) return true;
	if(x1+y2<=b && max(y1,x2)<=a) return true;
	if(y1+x2<=a && max(x1,y2)<=b) return true;
	if(y1+x2<=b && max(x1,y2)<=a) return true;
	if(y1+y2<=a && max(x1,x2)<=b) return true;
	if(y1+y2<=b && max(x1,x2)<=a) return true;
	return false;
}
int x[105],y[105];
int main()
{
	int n,a,b,i,j;
	scanf("%i %i %i",&n,&a,&b);
	for(i=0;i<n;i++) scanf("%i %i",&x[i],&y[i]);
	int sol=0;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(Check(x[i],y[i],x[j],y[j],a,b)) sol=max(sol,x[i]*y[i]+x[j]*y[j]);
		}
	}
	printf("%i\n",sol);
	return 0;
}