#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;

ll abs64(ll a)
{
	return a < 0 ? -a : a;
}

ll gcd(ll a, ll b, ll &x, ll &y)
{
	if (b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	ll g = gcd(b, a % b, x, y);
	ll nx = y;
	ll ny = x - (a / b) * y;
	x = nx, y = ny;
	return g;
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	ll C, Hr, Hb, Wr, Wb;
	cin >> C >> Hr >> Hb >> Wr >> Wb;

	ll ans = 0;

	if (Wr < Wb)
	{
		swap(Wr, Wb);
		swap(Hr, Hb);
	}

	if (C / Wr < (int)1e7)
	{
		for (int c1 = 0; c1 * Wr <= C; c1++)
		{
			int c2 = (C - c1 * Wr) / Wb;
			ans = max(ans, (ll)c1 * Hr + (ll)c2 * Hb);
		}
		cout << ans;
	}
	else
	{
		int len = Wr * Wb;
		ll Cr = len / Wr * Hr;
		ll Cb = len / Wb * Hb;
		
		ll added = max(Cr, Cb);
		
		for (int a = 0; a < 200; a++)
			for (int b = 0; b < 200; b++)
			{
				if (Wr * a + Wb * b > C)
					continue;
				ll d = C - Wr * a - Wb * b;
				ans = max(ans, a * Hr + b * Hb + (d / len) * added);
			}
		cout << ans;
	}

	return 0;
}