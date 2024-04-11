#include <iostream>
#include <cstdio>
using namespace std;

const int INF = 2000000000;

// adjust
template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool tension(T &a, const T &b)
{
	if (b < a)
	{
		a = b;
		return true;
	}
	return false;
}

int main()
{
	int hy, ay, dy;
	int hm, am, dm;
	int h, a, d;

	cin >> hm >> am >> dm;
	cin >> hy >> ay >> dy;
	cin >> h >> a >> d;

	int res = INF;
	for (int i = 0; i <= dy + hy; i++)
		for (int j = 0; j <= ay; j++)
		{
			if (am + i - dy <= 0)
				continue;
			int p = am + i - dy;
			int q = max(ay - dm - j, 0);
			tension(res, max((hy + p - 1) / p * q + 1 - hm, 0) * h + i * a + j * d);
		}

	cout << res << endl;

	return 0;
}