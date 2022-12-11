#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio> 
#include <string>
#include <vector>
#include <cmath>	
#include <set>
#include <map>
using namespace std;

typedef long long ll;
const int MAX_IT = (int)1e7;

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	ll x, y, m;
	cin >> x >> y >> m;

	for (ll i = 0;;)
	{                     
		if (x >= m || y >= m)
		{
cout << i;
		 	return 0;
		}
		if (x < y)
		{
			if (y == 0)
				break;
			ll n = (y - x + y - 1) / y;         
			i += n;             
			x = n * y + x;               
			if (n * y <= 0)
				break;
		}	
		else if (y < x)
		{
			if (x == 0)
				break;
			ll n = (x - y + x - 1) / x;
			i += n;
			y = n * x + y;
			if (n * x <= 0)
				break;
		}
		else
		{
			if (x == 0)
				break;
			x += y;
			i++;
		}
	}

	puts("-1");

	return 0;
}