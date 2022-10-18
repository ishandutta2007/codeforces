#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;

typedef long long s64;

const int MaxN = 100000;

template <class T1, class T2>
inline void tension(T1 &a, const T2 &b)
{
	if (b < a)
		a = b;
}

template <class T>
inline T previt(T p)
{
	return --p;
}
template <class T>
inline T nextit(T p)
{
	return ++p;
}

struct man
{
	int t, s, f;
	int id;

	static inline bool lessT(const man &lhs, const man &rhs)
	{
		return lhs.t < rhs.t;
	}
};

int main()
{
	int n, m;
	static man a[MaxN];

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &a[i].t, &a[i].s, &a[i].f);
		a[i].id = i;
	}

	sort(a, a + n, man::lessT);

	set< pair<int, int> > aS, bS;
	s64 curT = 0;
	int ap = 0, ep = 1;

	int delta = 0;

	static s64 res[MaxN];

	while (ap < n || !aS.empty() || !bS.empty())
	{
		int dt = INT_MAX;
		
		if (ap < n)
			tension(dt, a[ap].t - curT);

		set< pair<int, int> >::iterator at = aS.lower_bound(make_pair(ep, 0));
		set< pair<int, int> >::iterator bt = bS.lower_bound(make_pair(ep, 0));

		int d;
		if (aS.empty() && bS.empty())
			d = 0;
		else if (delta >= 0)
		{
			d = 1;
			if (at != aS.end())
				tension(dt, at->first - ep);
			if (bt != bS.end())
				tension(dt, bt->first - ep);
		}
		else
		{
			d = -1;
			if (at != aS.begin())
				tension(dt, ep - previt(at)->first);
			if (bt != bS.begin())
				tension(dt, ep - previt(bt)->first);
		}

		curT += dt, ep += d * dt;
		while (ap < n && a[ap].t == curT)
		{
			bS.insert(make_pair(a[ap].s, ap));
			if (a[ap].s > ep)
				delta++;
			else if (a[ap].s < ep)
				delta--;
			else
				delta += d;
			ap++;
		}

		while (true)
		{
			at = aS.lower_bound(make_pair(ep, 0));
			if (at == aS.end() || at->first != ep)
				break;
			res[a[at->second].id] = curT;
			delta -= d;
			aS.erase(at);
		}
		while (true)
		{
			bt = bS.lower_bound(make_pair(ep, 0));
			if (bt == bS.end() || bt->first != ep)
				break;
			delta -= d;
			aS.insert(make_pair(a[bt->second].f, bt->second));
			if (a[bt->second].f > ep)
				delta++;
			else
				delta--;
			res[a[bt->second].id] = curT;
			bS.erase(bt);
		}
	}

	for (int i = 0; i < n; i++)
		cout << res[i] << endl;

	return 0;
}