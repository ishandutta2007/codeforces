#include <bits/stdc++.h>
using namespace std;

struct circle
{
	int x, y, r;
};

circle dat[100005];

long long dsq(int x, int y)
{
	return x * 1ll * x + y * 1ll * y;
}

vector<pair<long double, int>> events;
constexpr long double PI = 3.14159265358979323846264338;

void push_event(long double s, long double e)
{
	while (s < 0) s += 2 * PI;
	while (s >= 2 * PI) s -= 2 * PI;
	while (e < 0) e += 2 * PI;
	while (e >= 2 * PI) e -= 2 * PI;

	if (s <= e)
	{
		events.emplace_back(s, 1);
		events.emplace_back(e, -1);
	}
	else
	{
		events.emplace_back(0, 1);
		events.emplace_back(e, -1);
		events.emplace_back(s, 1);
		events.emplace_back(2 * PI, -1);
	}
}

long double squeeze(long double f)
{
	if (f < -1.0L) return -1.0L;
	if (f > 1.0L) return 1.0L;
	return f;
}

int main()
{
	int x, y, v, t, n;
	scanf("%d%d%d%d%d", &x, &y, &v, &t, &n);
	long double maxdist = (long double)v * t;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &dat[i].x, &dat[i].y, &dat[i].r);

		if (dsq(dat[i].x - x, dat[i].y - y) <= 1ll * dat[i].r*dat[i].r)
		{
			printf("1.00000000000000000000000000000000000000000000000000000000000\n");
			return 0;
		}
	}

	if (v == 0 || t == 0)
	{
		printf("0.000000000000000000000000000000000000000000000000\n");
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		long double dist = hypot((long double)dat[i].x - x, (long double)dat[i].y - y);
		if (dist - dat[i].r >= maxdist) continue;

		long double tangent = sqrt(dist * dist - dat[i].r * 1ll * dat[i].r);
		long double cangle = atan2(dat[i].y - y, dat[i].x - x);
		long double md = min(tangent, maxdist);

		long double theta = acos(squeeze((md * md + dist * dist - dat[i].r * 1ll * dat[i].r) / (2 * md * dist)));

		push_event(cangle - theta, cangle + theta);
	}

	sort(events.begin(), events.end());

	int now = 0;
	long double ans = 0, last = 0;
	for (auto &&e : events)
	{
		if (now) ans += e.first - last;
		now += e.second;
		last = e.first;
	}

	printf("%.9Lf\n", ans / 2 / PI);
}