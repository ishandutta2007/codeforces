#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std; 

const int maxn = 1000; 

int a[2][maxn][maxn]; 
int s[2][maxn][maxn]; 

int getsum( int d, int r1, int c1, int r2, int c2 ) 
{
	return s[d][r2][c2]-s[d][r1-1][c2]-s[d][r2][c1-1]+s[d][r1-1][c1-1]; 
}

char c[maxn][maxn]; 

int main() 
{
	int n,m; 
	scanf( "%d%d", &n, &m ); 
	for (int i = 1; i <= n; ++i) 
		scanf( "%s", c[i]+1 ); 
	memset( a, 0, sizeof( a ) ); 
	memset( s, 0, sizeof( s ) ); 
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j)  
			if ( c[i][j] == '.' ) 
			{
				if ( c[i+1][j] == '.' ) a[0][i][j] = 1; 
				if ( c[i][j+1] == '.' ) a[1][i][j] = 1; 
			}
	for (int d = 0; d <= 1; ++d) 
		for (int i = 1; i <= n; ++i) 
			for (int j = 1; j <= m; ++j) 
				s[d][i][j] = s[d][i-1][j]+s[d][i][j-1]-s[d][i-1][j-1]+a[d][i][j]; 
	int q; 
	scanf( "%d", &q ); 
	for (int i = 1; i <= q; ++i) 
	{
		int r1,c1,r2,c2; 
		scanf( "%d%d%d%d", &r1,&c1,&r2,&c2 ); 
		printf( "%d\n", getsum( 0,r1,c1,r2-1,c2 ) + getsum( 1,r1,c1,r2,c2-1 ) ); 
	}
}