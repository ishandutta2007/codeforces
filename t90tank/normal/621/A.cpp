#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std; 
int n; 
typedef long long ll; 
ll maxs1,maxs2; 

int main() 
{
	scanf( "%d", &n );
	ll maxs1 = -n*ll(1000000007);
	ll maxs2 = 0;
	for (int i = 1; i <= n; ++i) 
	{
		int x; 
		scanf( "%d", &x );
		ll tmaxs1 = maxs1; 
		ll tmaxs2 = maxs2; 
		if ( x % 2 == 0 ) 
		{
			maxs1 = max( maxs1, tmaxs1 + x ); 
			maxs2 = max( maxs2, tmaxs2 + x );
		} 
		else {
			maxs1 = max( maxs1, tmaxs2 + x ); 
			maxs2 = max( maxs2, tmaxs1 + x );
		}
	} 
	cout<<maxs2<<endl; 
}