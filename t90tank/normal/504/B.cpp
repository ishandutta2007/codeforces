#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std; 

const int maxn = 300000; 

#define lowbit(x) (x&(-x))

int n; 

struct tree{
	int g[maxn]; 
	void add( int x, int c ) 
	{
		x++; 
		for ( ;x <= n; x+=lowbit(x)) g[x]+=c; 
	}
	void init1()
	{
		for (int i = 0; i < n; ++i) add( i, 1 ); 
	}
	void init2()
	{
		memset( g, 0, sizeof( g ) ); 
	}
	int getord( int x ) 
	{
		x++; 
		int ans = 0; 
		for (; x > 0; x-=lowbit(x)) ans += g[x]; 
		return ans; 
	}
	int getkth( int k ) 
	{
		int l = -1, r = n; 
		while ( l + 1 < r ) 
		{
			int m = ( l + r ) / 2; 
			if ( getord( m ) < k ) l = m; 
			else r = m; 
		}
		return r; 
	}
}ga, gb, gc; 

int a[maxn], b[maxn], c[maxn], z[maxn];

int main() 
{
	scanf( "%d", &n ); 
	for (int i = n-1; i >= 0; --i) scanf( "%d", &a[i] ); 
	for (int i = n-1; i >= 0; --i) scanf( "%d", &b[i] ); 
	ga.init2(); gb.init2(); gc.init1();
	int pre = 0; 
	for (int i = 0; i < n; ++i) 
	{
		int x = ga.getord( a[i] ); 
		int y = gb.getord( b[i] ); 
		z[i] = ( x + y + pre ) % ( i + 1 ); 
		pre = ( x + y + pre ) / ( i + 1 );
		//cout<<x<<' '<<y<<' '<<z[i]<<' '<<pre<<endl;  	
		ga.add( a[i], 1 ); 
		gb.add( b[i], 1 ); 
	}
	for (int i = n-1; i >= 0; --i) 
	{
		c[i] = gc.getkth( z[i]+1 ); 
		gc.add( c[i], -1 ); 
	}
	for (int i = n-1; i > 0; --i) printf( "%d ", c[i] ); 
	printf( "%d\n", c[0] ); 	
}