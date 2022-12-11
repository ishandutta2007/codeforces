#include <bits/stdc++.h>
using namespace std;

struct pts
{
	long long x, y, z;
};

pts dat[100005];
int n;

int sign(long long f)
{
	return f < 0 ? -1 : f > 0 ? 1 : 0;
}

long long safe_add(long long a, long long b)
{
	if (a < 0 && b < 0)
	{
		if (LLONG_MIN - b > a) return LLONG_MIN;
	}
	else if (a > 0 && b > 0)
	{
		if (LLONG_MAX - b < a) return LLONG_MAX;
	}

	return a + b;
}

long long avg(long long a, long long b)
{
	if (sign(a) != sign(b) || a == 0 || b == 0) return (a + b) / 2;
	return a / 2 + b / 2 + (a & 1) * sign(a);
}

bool check(long long t, bool print = false)
{
	long long tL = LLONG_MIN, tR = LLONG_MAX;
	long long bL = LLONG_MIN, bR = LLONG_MAX;
	long long cL = LLONG_MIN, cR = LLONG_MAX;
	long long dL = LLONG_MIN, dR = LLONG_MAX;

	for (int i = 0; i < n; i++)
	{
		tL = max(tL, -t + dat[i].x + dat[i].y + dat[i].z);
		tR = min(tR, t + dat[i].x + dat[i].y + dat[i].z);
		bL = max(bL, -t + dat[i].x + dat[i].y - dat[i].z);
		bR = min(bR, t + dat[i].x + dat[i].y - dat[i].z);
		cL = max(cL, -t + dat[i].x - dat[i].y + dat[i].z);
		cR = min(cR, t + dat[i].x - dat[i].y + dat[i].z);
		dL = max(dL, -t - dat[i].x + dat[i].y + dat[i].z);
		dR = min(dR, t - dat[i].x + dat[i].y + dat[i].z);
	}

	if (bL > bR || cL > cR || dL > dR) return false;
	tL = max(tL, bL + cL + dL);
	tR = min(tR, bR + cR + dR);
	if (tL > tR) return false;

	long long b = bL, c = cL, d = dL;
	long long diff = tL - (b + c + d);

	if (diff)
	{
		long long blen = bR - bL;
		long long f = min(blen, diff);
		b += f; diff -= f;
	}

	if (diff)
	{
		long long clen = cR - cL;
		long long f = min(clen, diff);
		c += f; diff -= f;
	}

	if (diff)
	{
		long long dlen = dR - dL;
		long long f = min(dlen, diff);
		d += f; diff -= f;
	}

	for (int dx = -2; dx <= 2; dx++)
	{
		b += dx;
		for (int dy = -2; dy <= 2; dy++)
		{
			c += dy;
			if ((b & 1) == (c & 1))
			{
				for (int dz = -2; dz <= 2; dz++)
				{
					d += dz;

					if ((b & 1) == (d & 1) && b >= bL && b <= bR && c >= cL && c <= cR && d >= dL && d <= dR &&
						b + c + d >= tL && b + c + d <= tR)
					{
						if (print)
						{
							printf("%lld %lld %lld\n", avg(b, c), avg(b, d), avg(c, d));
						}
						return true;
					}

					d -= dz;
				}
			}
			c -= dy;
		}
		b -= dx;
	}
	return false;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%lld%lld%lld", &dat[i].x, &dat[i].y, &dat[i].z);
		}

		long long lo = 0, hi = 3e18, ans = -1;
		while (lo <= hi)
		{
			long long mid = (lo + hi) / 2;
			if (check(mid))
			{
				ans = mid;
				hi = mid - 1;
			}
			else lo = mid + 1;
		}

		check(ans, true);
	}
}