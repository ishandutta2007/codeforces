#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>

#include <functional>
#include <complex>
#include <valarray>
#include <cassert>

using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
#define X first
#define Y second
#define mp make_pair

const int START = 1970;
const int N = 2000;
const int Y = (int)2e5 + 10;

ll t[N];
int Ps, Pm, Ph, Pday, Pdate, Pmonth;

ll secInYears[Y];
ll prefSec[Y];
int startWith[Y];

ll secInDay = 1LL * 24 * 60 * 60;
ll secInLeap = 1LL * 366 * secInDay;
ll secInNotLeap = 1LL * 365 * secInDay;
int n;

void read()
{
	scanf("%d%d%d %d%d%d", &Ps, &Pm, &Ph, &Pday, &Pdate, &Pmonth);
	scanf("%d", &n);
	if (Pday != -1)
		Pday--;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &t[i]);
	}
}

bool isLeap(int year)
{
	if (year % 400 == 0)
		return 1;
	if (year % 100 == 0)
		return 0;
	if (year % 4 == 0)
		return 1;
	return 0;
}

void precalc()
{

	startWith[0] = 3;

	for (int i = START; i < START + Y; i++)
	{
		if (isLeap(i))
			secInYears[i - START] = secInLeap;
		else
			secInYears[i - START] = secInNotLeap;
		if (i != START)
			startWith[i - START] = (startWith[i - START - 1] + (isLeap(i - 1) ? 366 : 365)) % 7;
	}
	for (int i = 1; i < Y; i++)
		prefSec[i] = prefSec[i - 1] + secInYears[i - 1];
}


const int DayInMonth[] = {
	0,
	31, 
	28, 
	31,
	30,
	31,
	30,
	31,
	31,
	30,
	31,
	30,
	31
};

int getDayInMonth(int m, int y)
{
	if (isLeap(y) && m == 2)
		return 29;
	return DayInMonth[m];
}

bool onPattern(int value, int pattern)
{
	return pattern == -1 || value == pattern;
}

bool onDayPattern(int m, int day, int date)
{
	if (Pday != -1 && Pdate != -1)
		return onPattern(m, Pmonth) && (onPattern(day, Pday) || onPattern(date, Pdate));
	return onPattern(m, Pmonth) && onPattern(day, Pday) && onPattern(date, Pdate);
}

bool IsFirstTry = true;

ll solveForDate(ll x, ll l)
{
	if (IsFirstTry)
	{
		ll secs = l;
		IsFirstTry = false;
		for (int h = 0; h < 24; h++)
			for (int m = 0; m < 60; m++)
				for (int s = 0; s < 60; s++)
				{
					if (onPattern(h, Ph) && onPattern(m, Pm) && onPattern(s, Ps) && secs > x)
						return secs;
					secs++;
				}
		return -1;
	}
	else
	{
		ll h = (Ph == -1 ? 0 : Ph);
		ll m = (Pm == -1 ? 0 : Pm);
		ll s = (Ps == -1 ? 0 : Ps);
		return l + s + 60 * m + 60 * 60 * h;
	}
}

ll solveForYear(ll x, int year)
{
	int curWeek = startWith[year];
	ll curSecs = prefSec[year];

	for (int month = 1; month <= 12; month++)
	{
		int maxDay = getDayInMonth(month, year + START);
		for (int day = 1; day <= maxDay; day++)
		{
			ll endDay = curSecs + secInDay;
			if (onDayPattern(month, curWeek, day))
			{
//				eprintf("Accept date: %d %d %d\n", year + START, month, day);
				if (endDay - 1 > x)
				{
					ll res = solveForDate(x, curSecs);
					if (res != -1)
						return res;
				}
			}
			curWeek = (curWeek + 1) % 7;
			curSecs = endDay;
		}
	}
	return -1;
}

ll solve(ll x)
{
	IsFirstTry = true;

	int year = upper_bound(prefSec, prefSec + Y, (ll)x) - prefSec - 1;
//	eprintf("Year: %d\n", year + START);
//	eprintf("Start with: %d\n", startWith[year]);
	ll res = solveForYear(x, year);
	for (int i = year + 1; res == -1; i++)
	{
		res = solveForYear(x, i);
	}
	return res;
}

void solve()
{
	for (int i = 0; i < n; i++)
	{
		ll res = solve(t[i]);
		printf("%lld\n", res);
//		eprintf("Try: %lld\n", res + secInDay);
	}
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	precalc();
	read();
	solve();

	return 0;
}