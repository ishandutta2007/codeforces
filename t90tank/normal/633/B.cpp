#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std; 

int Count( int x ) 
{
	int ans = 0; 
	for (int i = 5; i <= x; i *= 5 ) ans += x / i; 
	return ans; 
}

int Find( int x ) 
{
	int l = 0, r = 500000; 
	while ( l + 1 < r ) 
	{
		int m = ( l + r ) / 2; 
		if ( Count( m ) <= x ) l = m; 
		else r = m; 
	}
	return r; 
}

int main() 
{
	int m; 
	cin>>m; 
	int a = Find(m-1); 
	int b = Find( m ); 
	cout<<b-a<<endl; 
	for (int i = a; i < b; ++i) 
		if ( i == a ) cout<<i; 
		else cout<<' '<<i; 
	cout<<endl;  
}