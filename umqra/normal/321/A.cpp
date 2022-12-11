#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
char anti(char c)
{
	if (c == 'U')
		return 'D';
	if (c == 'D')
		return 'U';
	if (c == 'L')
		return 'R';
	if (c == 'R')
		return 'L';
}

void changeC(ll &a, ll &b, char c)
{
	if (c == 'U')
		b++;
	if (c == 'D')
		b--;
	if (c == 'L')
		a--;
	if (c == 'R')
		a++;
}

bool eqSgn(ll a, ll b)
{
	if (a == 0 && b == 0)
		return true;
	if (a > 0 && b > 0)
		return true;
	if (a < 0 && b < 0)
		return true;
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	ll a, b;
	cin >> a >> b;
	string str;
	cin >> str;

	ll x = 0, y = 0;
	for (int i = 0; i < (int)str.length(); i++)
		changeC(x, y, str[i]);

	for (int i = -1; i < (int)str.length(); i++)
	{
		ll locX = a, locY = b;
		for (int s = i; s >= 0; s--)
			changeC(locX, locY, anti(str[s]));           
		if ((locX * y == locY * x && eqSgn(x, locX) && eqSgn(y, locY)) || (locX == 0 && locY == 0))
		{                        
			if (x != 0 && locX % x != 0)
				continue;
			if (y != 0 && locY % y != 0)
				continue;       
			puts("Yes");
			return 0;
		}
	}

	puts("No");
	return 0;
}