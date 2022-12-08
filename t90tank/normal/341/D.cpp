#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

const int maxn = 1006; 
 
ll g[4][maxn][maxn]; 
int n, m; 

int lowbit( int x ) 
{ return x & (-x); }

void update1( int d, int x, int y, int r ) 
{
	while ( y <= n ) 
	{ g[d][x][y] ^= r; y += lowbit( y ); }
}

void update( int d, int x, int y, ll r ) 
{
	while ( x <= n ) 
	{ update1( d, x, y, r ); x += lowbit( x ); } 
}

ll getsum1( int d, int x, int y ) 
{
	ll ans = 0; 
	while ( y > 0 ) 
	{ ans ^= g[d][x][y]; y -= lowbit( y ); }
	return ans; 
}

ll getsum( int d, int x, int y ) 
{
	ll ans = 0; 
	while ( x > 0 ) 
	{ ans ^= getsum1( d, x, y ); x -= lowbit( x ); } 
	return ans; 
}

void add( int x, int y, ll r ) 
{
	if ( x == 0 || y == 0 ) return; 
	if ( x % 2 == 1 && y % 2 == 1 ) update( 0, x, y, r ); 
	if ( x % 2 == 1 ) update( 1, x, n-y+1, r );
	if ( y % 2 == 1 ) update( 2, n-x+1, y, r ); 
	update( 3, n-x+1, n-y+1, r ); 
}

ll solve( int x, int y ) 
{
	if ( x == 0 || y == 0 ) return 0; 
	ll ans = 0; 
	ans ^= getsum( 0, x, y ); 
	if ( y % 2 == 1 ) ans ^= getsum( 1, x, n-y ); 
	if ( x % 2 == 1 ) ans ^= getsum( 2, n-x, y );
	if ( x % 2 == 1 && y % 2 == 1 ) ans ^= getsum( 3, n-x, n-y );
	return ans;    
}

void op2( int x0, int y0, int x1, int y1, ll r ) 
{
	add( x1, y1, r ); 
	add( x0-1, y1, r ); 
	add( x1, y0-1, r );
	add( x0-1, y0-1, r );  
}

ll op1( int x0, int y0, int x1, int y1 ) 
{
	ll ans = 0; 
	ans ^= solve( x1, y1 );
	ans ^= solve( x0-1, y1 );
	ans ^= solve( x1, y0-1 );
	ans ^= solve( x0-1, y0-1 );
	return ans;   
}

int main() 
{
	scanf( "%d%d", &n, &m ); 
	memset( g, 0, sizeof( g ) ); 
	for (int i = 1; i <= m; ++i) 
	{
		int op, x0, y0, x1, y1; 
		scanf( "%d%d%d%d%d", &op, &x0, &y0, &x1, &y1 ); 
		ll r; 
		if ( op == 1 ) printf( "%I64d\n", op1( x0, y0, x1, y1 ) ); 
		else {
			scanf( "%I64d", &r ); 
			op2( x0, y0, x1, y1, r ); 
		}
	}
}