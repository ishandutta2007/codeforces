#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std; 

const int maxn = 20; 

int f[maxn*2][1<<maxn];
bool v[maxn*2][1<<maxn]; 

char T[maxn+2][maxn+2];
int n;  

int dfs( int l, int maze ) 
{
	if ( v[l][maze] ) return f[l][maze];
	int ans;  
	if ( l % 2 == 1 ) ans = -n*2; 
	else ans = 2*n; 
	for (char c='a'; c <='z'; c++) 
	{
		int maze_ = 0; 
		for (int i = 0; i < n; ++i) 
			if ( (maze|(1<<i))==maze ) 
			{
				if ( l-i+1 < n && T[i][l-i+1] == c )
					maze_ |= (1<<i); 
				if ( i+1 < n && T[i+1][l-i] == c ) 
					maze_ |= (1<<(i+1)); 
			}
		if ( maze_ != 0 ) 
		{
			int tmp = dfs( l+1, maze_ );
			if ( c == 'a' ) tmp++; 
			else if ( c == 'b' ) tmp--; 
			if ( l % 2 == 1 ) ans = max( ans, tmp ); 
			else ans = min( ans, tmp );  
		}
	}
	f[l][maze] = ans; 
	v[l][maze] = true;
	//cout<<l<<' '<<maze<<' '<<ans<<endl;  
	return ans; 
}

int main() 
{
	scanf( "%d", &n ); 
	for (int i = 0; i < n; ++i) 
		scanf( "%s", T[i] );
	memset( v, false, sizeof( v ) ); 
	v[2*n-2][1<<(n-1)] = true; 
	f[2*n-2][1<<(n-1)] = 0;  
	int ans = dfs( 0, 1 );  
	if ( T[0][0] == 'a' ) ans++; 
	else if ( T[0][0] == 'b' ) ans--;
	if ( ans > 0 ) printf( "FIRST\n" ); 
	else if ( ans < 0 ) printf( "SECOND\n" ); 
	else printf( "DRAW\n" );  
}