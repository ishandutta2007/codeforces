#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;

struct Actor
{
	int x, y, id, cnt;

	Actor () : x(), y(), id(), cnt() {}
	Actor(int _x, int _y, int _id, int _cnt) : x(_x), y(_y), id(_id), cnt(_cnt) {}

	bool operator < (const Actor &a) const
	{
		if (y != a.y)
			return y < a.y;
		return id < a.id;
	}
};

struct Event
{
	int type;
	int x;
	int y;
	int id;
	int cnt;

	Event() : type(), x(), y(), id(), cnt() {}
	Event(int _type, int _x, int _y, int _id, int _cnt) : type(_type), x(_x), y(_y), id(_id), cnt(_cnt) {}

	bool operator < (const Event &a) const
	{
		if (x != a.x)
			return x < a.x;
		if (type != a.type)
			return type < a.type;
		return id < a.id;
	}
};

int n, m;
const int N = 100100;
int sz;
Event ev[4 * N];
int ans[N];
set<Actor> actors;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		ev[sz++] = Event(0, x, y, i, 0);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		ev[sz++] = Event(-1, x, y, i, c);
	}
	sort(ev, ev + sz);
	for (int i = 0; i < sz; i++)
	{
		Event e = ev[i];
		if (e.type == -1)
		{
			actors.insert( Actor(e.x, e.y, e.id, e.cnt) );
		}
		else
		{
			Actor tmp = Actor(e.x, e.y, -1, 0);
			auto iter = actors.lower_bound(tmp);
			if (iter == actors.end())
			{
				printf("NO\n");
				return 0;
			}
			tmp = *iter;
			actors.erase(iter);
			tmp.cnt--;
			ans[e.id] = tmp.id + 1;
			if (tmp.cnt > 0)
				actors.insert(tmp);
		}
	}
	printf("YES\n");
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);

	return 0;
}