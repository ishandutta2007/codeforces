#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std; 

const int maxn = 200000;

int l[maxn],r[maxn]; 
int n,pp; 
double p[maxn]; 

int main() 
{
	scanf( "%d%d", &n, &pp ); 
	for (int i = 0; i < n; ++i) 
	{
		scanf( "%d%d", &l[i], &r[i] ); 
		p[i] = (r[i]/pp-(l[i]-1)/pp)/(r[i]-l[i]+1.0);  
	}
	double s = 2000*n; 
	for (int i = 0; i < n; ++i)
		s -= 2000 * ( 1-p[i] ) * ( 1-p[(i+1)%n] ); 
	printf( "%.15f\n", s );   
}