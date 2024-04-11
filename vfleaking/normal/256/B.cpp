#include <iostream>
#include <algorithm>
using namespace std;

typedef long long s64;

s64 n, x, y, c;

inline s64 sum1(const s64 &n)
{
	return n * (n + 1) / 2;
}

// I obtain it using sigma([i + j <= t]) 1 <= i <= x, 1 <= j <= y.
inline s64 corner(const s64 &x, const s64 &y, const s64 &t)
{
	if (x == 0 || y == 0)
		return 0;

	s64 res = 0ll;
	
	// [l, r]
	s64 l, r;
	l = max(1ll, t - y);
	r = min(x, t - 1);
	if (l <= r)
		res += sum1(t - l) - sum1(t - r - 1);
	
	l = 1;
	r = min(x, t - y - 1);
	if (l <= r)
		res += (r - (l - 1)) * y;
	
	return res;
}

inline s64 calc(const s64 &t)
{
	s64 res = 1ll;
	res += min(x - 1, t);
	res += min(y - 1, t);
	res += min(n - x, t);
	res += min(n - y, t);

	res += corner(x - 1, y - 1, t);
	res += corner(x - 1, n - y, t);
	res += corner(n - x, y - 1, t);
	res += corner(n - x, n - y, t);

	return res;
}

int main()
{
	cin >> n >> x >> y >> c;

	s64 l = 0ll, r = 1000001000ll;
	while (l != r)
	{
		s64 mid = l + r >> 1;
		if (calc(mid) < c)
			l = mid + 1;
		else
			r = mid;
	}
	cout << l << endl;
	
	return 0;
}