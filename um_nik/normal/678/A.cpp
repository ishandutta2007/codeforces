#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

int main()
{
	ll x, y;
	cin >> x >> y;
//	x--;
	x -= x % y;
	x += y;
	cout << x << endl;

	return 0;
}