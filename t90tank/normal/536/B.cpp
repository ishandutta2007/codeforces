#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std; 

const long long mod = 1000000007; 

char s[2000000]; 
int p[2000000];
bool v[2000000];
int y[2000000]; 

int n,m;  

long long getmul( long long k ) 
{
	if ( k == 0 ) return 1; 
	long long c = getmul( k / 2 ); 
	c = c * c % mod; 
	if ( k % 2 == 1 ) return c * 26 % mod; 
	return c;  
}

int main() 
{
	scanf( "%d%d", &n, &m );
	scanf( "%s", s ); 
	p[1] = 0; 
	int len = strlen( s );
	int j = 0;  
	for (int i = 2; i <= len; ++i) 
	{
		while ( j > 0 && s[j] != s[i-1] ) j = p[j]; 
		if ( s[j] == s[i-1] ) ++j;
		p[i] = j; 
	}
	memset( v, false, sizeof( v ) ); 
	int x = len; 
	while ( x > 0 ) 
	{ v[x] = true; x = p[x]; }
	for (int i = 1; i <= m; ++i) scanf( "%d", &y[i] );
	long long ans = 0;
	bool flag = true;   
	for (int i = 1; i <= m; ++i) 
	{
		if ( i == 1 ) ans += y[i]-1; 
		if ( i == m ) ans += n-(y[i]+len-1);  
		if ( i < m )
		{
			if ( y[i] + len - 1 < y[i+1] ) ans += y[i+1] - y[i] - len;
			else if ( !v[y[i]+len-y[i+1]] ) flag = false;
		}
	} 
	if ( m == 0 ) ans = n; 
	if ( flag ) cout<<getmul(ans)<<endl; 
	else cout<<0<<endl;  
}