#include <stdio.h>
void swap(int &a, int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}
int main()
{
	int x,y,z,a[7],x1,y1,z1,i;
	scanf("%i %i %i",&x1,&y1,&z1);
	scanf("%i %i %i",&x,&y,&z);
	for(i=1;i<=6;i++) scanf("%i",&a[i]);
	if(x<0)
	{
		swap(a[5],a[6]);
		x1=-x1;
		x=-x;
	}
	if(y<0)
	{
		swap(a[1],a[2]);
		y1=-y1;
		y=-y;
	}
	if(z<0)
	{
		swap(a[3],a[4]);
		z1=-z1;
		z=-z;
	}
	int sol=0;
	if(x1>x) sol+=a[6];
	if(x1<0) sol+=a[5];
	if(y1>y) sol+=a[2];
	if(y1<0) sol+=a[1];
	if(z1>z) sol+=a[4];
	if(z1<0) sol+=a[3];
	printf("%i\n",sol);
	return 0;
}