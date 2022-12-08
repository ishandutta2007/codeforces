#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std; 

int n; 

pair<int,int> a[200000]; 
int f[200000]; 

int main() 
{
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) scanf( "%d%d", &a[i].first, &a[i].second ); 
	sort( a+1, a+n+1 );
	f[0] = 0;
	int ans = n; 
	for (int i = 1; i <= n; ++i) 
	{
		int l = 0, r = i+1;
		while ( l + 1 < r ) 
		{
			int m = ( l + r ) / 2; 
			if ( a[m].first + a[i].second < a[i].first ) l = m; 
			else r = m;  
		}
		f[i] = i - l - 1 + f[l]; 
		ans = min( ans, f[i] + n-i ); 
	}
	cout<<ans<<endl; 
}