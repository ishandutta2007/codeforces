#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std; 

typedef long long ll; 

ll cc[63]; 

ll a, b; 

int main() 
{
	cin>>a>>b;
	int tot = 0; 
	ll x = 2; 
	for (int i = 2; i < 63; ++i) 
	{
		x *= 2; 
		ll y = 1; 
		for (int j = 0; j < i-1; ++j) 
		{
			ll ans = x-1-y;  
			if ( a <= ans && ans <= b ) tot++; 
			y *= 2; 
		}
	}
	cout<<tot<<endl; 
}