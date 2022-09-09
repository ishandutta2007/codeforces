#include <stdio.h>
struct Point
{
	long long x,y;
} A,B,C;
int Orientation(Point p, Point q, Point r)
{
	long long o=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
	if(o==0) return 0;
	if(o>0) return 1;
	return 2;
}
int main()
{
	scanf("%lld %lld",&A.x,&A.y);
	scanf("%lld %lld",&B.x,&B.y);
	scanf("%lld %lld",&C.x,&C.y);
	if(Orientation(A,C,B)==0) printf("TOWARDS\n");
	else if(Orientation(A,C,B)==2) printf("RIGHT\n");
	else printf("LEFT\n");
	return 0;
}