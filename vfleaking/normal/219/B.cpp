#include <iostream>
using namespace std;

typedef long long s64;

int main()
{
	s64 p, d;

	cin >> p >> d;

	s64 res;

	s64 t = 1ll;
	for (int i = 0; i <= 18; i++)
	{
		if (t > p)
			break;
		if (p % t == t - 1)
			res = p;
		else if (p - (p / t * t - 1) <= d)
			res = p / t * t - 1;
		else
			break;

		t *= 10ll;
	}
	cout << res << endl;

	return 0;
}