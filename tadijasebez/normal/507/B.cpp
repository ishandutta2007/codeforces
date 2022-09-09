#include <stdio.h>
#include <cmath>
int Dist(int x, int y, int x1, int y1)
{
	return ceil(sqrt(1ll*(x-x1)*(x-x1)+1ll*(y-y1)*(y-y1)));
}
int main()
{
	int r,x,y,x1,y1;
	scanf("%i %i %i %i %i",&r,&x,&y,&x1,&y1);
	r*=2;
	int dist=Dist(x,y,x1,y1);
	int sol=(dist+r-1)/r;
	printf("%i\n",sol);
	return 0;
}