#include <iostream>
using namespace std;

typedef long long s64;

inline s64 qpow(const int &a, const int &n, const int &m)
{
	s64 res = 1ll;
	s64 t = a;
	for (int i = 0; i < 31; i++)
	{
		if (n & 1 << i)
			res = res * t % m;
		t = t * t % m;
	}
	return res;
}

int main()
{
	int n, m;
	cin >> n >> m;

	cout << (qpow(3, n, m) + m - 1) % m << endl;

	return 0;
}