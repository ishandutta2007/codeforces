#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define ALL(a) a.begin(), a.end()

typedef long long s64;

const int MaxN = 100000;
const int MaxM = 100000;

int n, m;
vector<int> diagA[MaxN + MaxM + 3];
vector<int> diagB[MaxN + MaxM + 3];

struct status
{
	int x, y, dx, dy;

	friend inline bool operator==(const status &lhs, const status &rhs)
	{
		return lhs.x == rhs.x && lhs.y == rhs.y && lhs.dx == rhs.dx && lhs.dy == rhs.dy;
	}
};

void addP(int x, int y)
{
	diagA[x + y].push_back(y);
	diagB[x + m + 1 - y].push_back(y);
}

inline bool hasP(int x, int y)
{
	return *lower_bound(ALL(diagA[x + y]), y) == y;
}

status go(status s)
{
	int nx, ny;
	if (s.dx == s.dy)
	{
		if (s.dx == -1)
			ny = *(lower_bound(ALL(diagB[s.x + m + 1 - s.y]), s.y) - 1);
		else
			ny = *lower_bound(ALL(diagB[s.x + m + 1 - s.y]), s.y);
		nx = s.x - s.y + ny;
	}
	else
	{
		if (s.dx == -1)
			ny = *lower_bound(ALL(diagA[s.x + s.y]), s.y);
		else
			ny = *(lower_bound(ALL(diagA[s.x + s.y]), s.y) - 1);
		nx = s.x + s.y - ny;
	}

	bool br = hasP(nx - s.dx, ny), bc = hasP(nx, ny - s.dy);
	if (br && bc)
		return (status){.x = nx - s.dx, .y = ny - s.dy, .dx = -s.dx, .dy = -s.dy};
	else if (br)
		return (status){.x = nx, .y = ny - s.dy, .dx = s.dx, .dy = -s.dy};
	else if (bc)
		return (status){.x = nx - s.dx, .y = ny, .dx = -s.dx, .dy = s.dy};
	else
		return (status){.x = nx - s.dx, .y = ny - s.dy, .dx = -s.dx, .dy = -s.dy};
}


int main()
{
	int nP;
	cin >> n >> m >> nP;

	for (int i = 0; i < nP; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		addP(x, y);
	}

	for (int y = 0; y <= m + 1; y++)
		addP(0, y), addP(n + 1, y);
	for (int x = 0; x <= n + 1; x++)
		addP(x, 0), addP(x, m + 1);

	for (int i = 0; i <= n + m + 2; i++)
		sort(diagA[i].begin(), diagA[i].end());
	for (int i = 0; i <= n + m + 2; i++)
		sort(diagB[i].begin(), diagB[i].end());

	int sx, sy;
	char sd[3];

	scanf("%d %d %s", &sx, &sy, sd);

	status st = {.x = sx, .y = sy, .dx = sd[0] == 'N' ? -1 : 1, .dy = sd[1] == 'W' ? -1 : 1};
	st = go(st);
	
	s64 res = 0;

	bool is_foldback = false;

	status s = st;
	do
	{
		status next = go(s);
		res += max(abs(next.x - s.x), abs(next.y - s.y));
		if (s.dx == -next.dx && s.dy == -next.dy)
		{
			res++;
			is_foldback = true;
		}
		s = next;
	}
	while (!(s == st));

	if (is_foldback)
		res /= 2;

	cout << res << endl;

	return 0;
}