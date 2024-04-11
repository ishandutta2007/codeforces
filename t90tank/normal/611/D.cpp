#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std; 

const int maxn = 5006; 

char a[maxn]; 
int f[maxn][maxn]; 
int l[maxn][maxn]; 

void Com( int x, int y ) 
{
	if ( f[x][y] != 0 ) return; 
	if ( a[x] < a[y] || a[x] > a[y] ) 
	{ f[x][y] = (a[x]<a[y])*2-1; l[x][y] = 0; return; }
	Com( x+1, y+1 ); 
	l[x][y] = l[x+1][y+1] + 1; 
	f[x][y] = f[x+1][y+1]; 	
}

int n; 
typedef long long ll; 

const ll maxp = 1000000007; 
int dp[maxn][maxn]; 
int s[maxn][maxn]; 

int main() 
{
	memset( f, 0, sizeof( f ) ); 
	scanf( "%d", &n ); 
	scanf( "%s", a+1 );
	memset( dp, 0, sizeof( dp ) ); 
	memset( s, 0, sizeof( s ) );  
	for (int i = 1; i <= n; ++i) 
	{
		dp[i][i] = 1; 
		for (int j = 1; j < i; ++j)
		{ 
			if ( a[i-j+1] != '0' ) 
			{
				dp[i][j] = s[i-j][j-1];
				if (i-j*2+1 >= 1 ) 
				{
					Com( i-j*2+1, i-j+1 ); 
					if ( f[i-j*2+1][i-j+1] == 1 && l[i-j*2+1][i-j+1] < j ) dp[i][j] = ( ll(dp[i][j]) + ll(dp[i-j][j]) ) % maxp; 
				}
			}
			//cout<<i<<' '<<j<<' '<<dp[i][j]<<endl; 
			s[i][j] = ( ll(s[i][j-1]) + ll(dp[i][j]) ) % maxp; 
		}
		for (int j = i; j <= n; ++j) 
			s[i][j] = ( ll(s[i][j-1]) + ll(dp[i][j]) ) % maxp; 
	}
	cout<<s[n][n]<<endl; 
}