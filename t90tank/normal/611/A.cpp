#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std; 

int main() 
{
	char a[20],b[20]; 
	int x; 
	scanf( "%d%s%s", &x, a, b ); 
	if ( b[0] == 'w' ) 
	{
		int t = 5; 
		int ans = 0; 
		for (int i = 1; i <= 366; ++i) 
		{
			if ( t == x ) ans++;
			t = t % 7 + 1; 
		}
		cout<<ans<<endl; 
	}
	else if ( x == 31 ) cout<<7<<endl; 
	else if ( x == 30 ) cout<<11<<endl; 
	else cout<<12<<endl;  
}