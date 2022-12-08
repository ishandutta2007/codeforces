#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1000000;

int g[maxn]; 
int n; 
int a[maxn];

int lowbit( int x ) 
{ return x & (-x); }

void update( int x, int f ) 
{
	while ( x <= n ) 
	{ g[x] = max( g[x], f ); x += lowbit( x ); } 
}
int getmax( int x ) 
{
	int ans = 0; 
	while ( x > 0 ) 
	{ ans = max( ans, g[x] ); x -= lowbit( x ); } 
	return ans; 
}

int main() 
{
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &a[i] ); 
	memset( g, 0, sizeof( g ) );
	int ans = 0;  
	for (int i = 1; i <= n; ++i) 
	{
		int f = getmax( a[i] ) + 1;
		ans = max( ans, f ); 
		update( a[i], f ); 
	}
	cout<<ans<<endl; 
}