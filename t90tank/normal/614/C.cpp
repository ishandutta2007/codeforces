#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std; 

struct point {
	double x, y; 
	point () {}
	point( double x, double y ) : x(x), y(y) {}
	point operator+( const point &b ) const 
	{ return point( x+b.x, y+b.y ); }
	point operator-( const point &b ) const 
	{ return point( x-b.x, y-b.y ); }
}a[2000000]; 

int n; 

double xmul( point a, point b ) 
{
	return a.x * b.y - a.y * b.x; 
}

double Sqr( double x ) 
{ return x*x; }

double Dist( point a, point b ) 
{
	return sqrt( Sqr(a.x-b.x) + Sqr( a.y-b.y ) ); 
}

double Abs( double x ) 
{ return max(x,-x); } 

double GetDist( point A, point B, point C ) 
{
	double a = Dist( B,C ); 
	double b = Dist( A,C ); 
	double c = Dist( A,B ); 
	if ( a*a + b*b <= c*c || a*a + c*c <= b*b ) return min( b, c ); 
	return Abs(xmul( B-A, C-A )) / a; 
}

int main() 
{
	scanf( "%d", &n ); 
	point P; 
	scanf( "%lf%lf", &P.x, &P.y ); 
	for (int i = 0; i < n; ++i) scanf( "%lf%lf", &a[i].x, &a[i].y ); 
	double mind = Dist( a[0], P ), maxd = Dist( a[0], P ); 
	for (int i = 0; i < n; ++i) maxd = max( maxd, Dist( a[i], P ) );  
	for (int i = 0; i < n; ++i) mind = min( mind, GetDist( P, a[i], a[(i+1)%n] ) ); 
//	cout<<Sqr(maxd)<<' '<<Sqr(mind)<<endl; 
	printf( "%.20f\n", 3.1415926535897932385*(Sqr(maxd)-Sqr(mind)) ); 
}