#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;

ll sqr(ll x)
{
	return x * x;
}

ll d;
ll r;
ll x, xx, y, yy;

int main()
{
	cin >> r >> x >> y >> xx >> yy;
	d = sqr(x - xx) + sqr(y - yy);
	r *= 2;
	for (int i = 0;; i++)
	{
		if (sqr(r * i) >= d)
		{
			cout << i << endl;
			return 0;
		}
	}

	return 0;
}