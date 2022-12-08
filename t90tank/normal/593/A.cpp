#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>
#include <set> 
using namespace std;

int a[30][30]; 
int b[30]; 
int d[30];
char s[1000000]; 

int main() 
{
	int n; 
	memset( a, 0, sizeof( a ) ); 
	memset( b, 0, sizeof( b ) ); 
	scanf( "%d", &n );
	for (int i = 1; i <= n; ++i) 
	{
		scanf( "%s", s ); 
		int len = strlen( s ); 
		memset( d, 0, sizeof( d ) ); 
		int sum = 0; 
		for (int j = 0; j < len; ++j)  
			if ( d[s[j]-'a'] == 0 ) 
			{ d[s[j]-'a']++; sum++; }
		if ( sum == 1 ) 
		{
			for (int j = 0; j < 26; ++j) 
				if ( d[j] > 0 ) b[j]+=len; 
		}
		else if ( sum == 2 ) 
		{
			int x,y; 
			for (int j = 0; j < 26; ++j) 
				if ( d[j] > 0 ) y = j;
			for (int j = 25; j >= 0; --j) 
				if ( d[j] > 0 ) x = j;
			a[x][y]+=len; 
		}
	}
	int ans = 0; 
	for (int i = 0; i < 26; ++i)
		for (int j = i+1; j < 26; ++j) 
			 ans = max( ans, a[i][j] + b[i] + b[j] ); 
	cout<<ans<<endl; 
}