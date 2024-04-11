#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;

struct Event
{
	int type;
	ll t;
	ll d;

	Event() : type(), t(), d() {}
	Event(int _type, ll _t, ll _d) : type(_type), t(_t), d(_d) {}

	bool operator < (const Event &e) const
	{
		if (t != e.t) return t < e.t;
		return type < e.type;
	}
};

const int N = 200200;
int n, b;
int l, r;
ll q[N][2];
set<Event> setik;
ll ans[N];

int main()
{

	scanf("%d%d", &n, &b);
	while(n--)
	{
		ll t, d;
		scanf("%lld%lld", &t, &d);
		setik.insert(Event(1, t, d));
	}
	l = r = 0;
	n = 0;
	while(!setik.empty())
	{
		Event e = *setik.begin();
		setik.erase(setik.begin());
		if (e.type == 0)
		{
			int id = q[l][0];
			l++;
			ans[id] = e.t;
			if (l != r)
				setik.insert(Event(0, e.t + q[l][1], -1));
		}
		else
		{
			int id = n++;
			if (r - l > b)
			{
				ans[id] = -1;
				continue;
			}
			q[r][0] = id;
			q[r][1] = e.d;
			r++;
			if (r == l + 1)
				setik.insert(Event(0, e.t + q[l][1], -1));
		}
	}
	for (int i = 0; i < n; i++)
		printf("%lld ", ans[i]);
	printf("\n");

	return 0;
}