#include <iostream>
#include <cstdio>
using namespace std;

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
	int a, b;
	cin >> a >> b;

	int res = 0;
	int rest = 0;
	while (a > 0)
	{
		res += a, rest += a;
		a = rest / b;
		rest %= b;
	}
	cout << res << endl;

	return 0;
}