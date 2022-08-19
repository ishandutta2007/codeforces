#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
#define mp make_pair
#define X first
#define Y second

const int N = (int)4e5 + 200;
int n, m;
int ans[N];

struct Event
{
	int type;
	int idx;
	ll x;
	ll r;

	Event() : type(), idx(), x(), r() {}
	Event(int _type, int _idx, ll _x, ll _r) : type(_type), idx(_idx), x(_x), r(_r) {}

	bool operator < (const Event &e) const
	{
		if (x != e.x) return x < e.x;
		return type < e.type;
	}

	void print()
	{
		printf("type = %d, idx = %d, x = %lld, r = %lld\n", type, idx, x, r);
	}
};

Event ev[N];
int evSz;

void read()
{
	scanf("%d%d", &n, &m);
	ll l, r;
	ll nl, nr;
	scanf("%lld%lld", &l, &r);
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%lld%lld", &nl, &nr);
		ev[evSz++] = Event(0, i, nl - r, nr - l + 1);
		l = nl;
		r = nr;
	}
	for (int i = 0; i < m; i++)
	{
		ll x;
		scanf("%lld", &x);
		ev[evSz++] = Event(1, i, x, 0);
	}
	return;
}

bool solve()
{
	sort(ev, ev + evSz);
	set<pli> setik;
	for (int i = 0; i < evSz; i++)
	{
		Event e = ev[i];
//		e.print();
		if (e.type == 0)
			setik.insert(mp(e.r, e.idx));
		else
		{
			if (setik.empty()) continue;
			ll x = e.x;
			pli f = *setik.begin();
			if (f.X <= x) return false;
			setik.erase(setik.begin());
			ans[f.Y] = e.idx;
		}
	}
	return setik.empty();
}

int main()
{
//	freopen("input.txt", "r", stdin);

	read();
	if (!solve())
	{
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	for (int i = 0; i < n - 1; i++)
		printf("%d ", ans[i] + 1);
	printf("\n");

	return 0;
}