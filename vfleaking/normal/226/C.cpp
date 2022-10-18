#include <iostream>
using namespace std;

typedef long long s64;

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

s64 mod;
inline int modplus(const int &lhs, const int &rhs)
{
	int res = lhs + rhs;
	if (res >= mod)
		res -= mod;
	return res;
}
inline int modmult(const int &lhs, const int &rhs)
{
	return (s64)lhs * rhs % mod;
}

inline void _fib(const s64 &n, int &resV, int &resPrev)
{
	if (n == 1)
	{
		resV = 1 % mod;
		resPrev = 0;
		return;
	}

	int v, prev;
	if (n & 1)
	{
		_fib(n - 1, v, prev);
		resV = modplus(v, prev),
		resPrev = v;
	}
	else
	{
		_fib(n >> 1, v, prev);
		resV = modplus(modmult(v, modplus(v, prev)), modmult(prev, v));
		resPrev = modplus(modmult(v, v), modmult(prev, prev));
	}
}

inline s64 fib(const s64 &n)
{
	int v, prev;
	_fib(n, v, prev);
	return v;
}

int main()
{
	s64 l, r, k;
	cin >> mod >> l >> r >> k;

	l--;
	
	s64 index;
	for (s64 i = r, nexti; i > 0ll; i = nexti)
	{
		s64 t1 = l / i, t2 = r / i;
		if (t2 - t1 >= k)
		{
			index = i;
			break;
		}

		nexti = 0ll;
		relax(nexti, l / (t1 + 1ll));
		relax(nexti, r / (t2 + 1ll));
	}

	cout << fib(index) << endl;

	return 0;
}