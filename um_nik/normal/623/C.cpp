#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const ll INF = (ll)1e17 + 2;

struct Point
{
	ll x, y;
	int id;

	Point() : x(), y(), id() {}
	Point (ll _x, ll _y, int _id) : x(_x), y(_y), id(_id) {}

	void scan(int _id)
	{
		id = _id;
		scanf("%lld%lld", &x, &y);
	}
};

bool cmpX(const Point &A, const Point &B)
{
	return A.x < B.x;
}
bool cmpY(const Point &A, const Point &B)
{
	return A.y < B.y;
}

const int N = 200100;
Point byX[N], byY[N], byId[N];
int LX, RX, LY, RY;
int n;
bool used[N];
int ord[N];
int ordSz;
ll D;
int col[N];
int C;

void read()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		byId[i].scan(i);
		byX[i] = byY[i] = byId[i];
	}
	sort(byX, byX + n, cmpX);
	sort(byY, byY + n, cmpY);
	return;
}

void init()
{
	LX = LY = 0;
	RX = RY = n - 1;
	ordSz = 0;
	for (int i = 0; i < 2 * n; i++)
		used[i] = false;
	return;
}

ll sqr(ll x)
{
	return x * x;
}
ll getDist(Point A, Point B, int ca, int cb)
{
	ll a = (ca == 0 ? A.x : A.y);
	ll b = (cb == 0 ? B.x : B.y);
	if (ca == cb)
		return sqr(a - b);
	else
		return sqr(a) + sqr(b);
}

void dfsOrd(int v)
{
	used[v] = 1;

	while(LX < n && (used[2 * byX[LX].id + 1] || getDist(byId[v / 2], byX[LX], v & 1, 0) > D))
	{
		LX++;
		if (!used[2 * byX[LX - 1].id + 1])
			dfsOrd(2 * byX[LX - 1].id + 1);
	}
	while(RX >= 0 && (used[2 * byX[RX].id + 1] || getDist(byId[v / 2], byX[RX], v & 1, 0) > D))
	{
		RX--;
		if (!used[2 * byX[RX + 1].id + 1])
			dfsOrd(2 * byX[RX + 1].id + 1);
	}
	while(LY < n && (used[2 * byY[LY].id] || getDist(byId[v / 2], byY[LY], v & 1, 1) > D))
	{
		LY++;
		if (!used[2 * byY[LY - 1].id])
			dfsOrd(2 * byY[LY - 1].id);
	}
	while(RY >= 0 && (used[2 * byY[RY].id] || getDist(byId[v / 2], byY[RY], v & 1, 1) > D))
	{
		RY--;
		if (!used[2 * byY[RY + 1].id])
			dfsOrd(2 * byY[RY + 1].id);
	}

	ord[ordSz++] = v;
	return;
}

void dfsColor(int v)
{
	col[v] = C;

	while(LX < n && (col[2 * byX[LX].id] != -1 || getDist(byId[v / 2], byX[LX], (v & 1) ^ 1, 0) > D))
	{
		LX++;
		if (col[2 * byX[LX - 1].id] == -1)
			dfsColor(2 * byX[LX - 1].id);
	}
	while(RX >= 0 && (col[2 * byX[RX].id] != -1 || getDist(byId[v / 2], byX[RX], (v & 1) ^ 1, 0) > D))
	{
		RX--;
		if (col[2 * byX[RX + 1].id] == -1)
			dfsColor(2 * byX[RX + 1].id);
	}
	while(LY < n && (col[2 * byY[LY].id + 1] != -1 || getDist(byId[v / 2], byY[LY], (v & 1) ^ 1, 1) > D))
	{
		LY++;
		if (col[2 * byY[LY - 1].id + 1] == -1)
			dfsColor(2 * byY[LY - 1].id + 1);
	}
	while(RY >= 0 && (col[2 * byY[RY].id + 1] != -1 || getDist(byId[v / 2], byY[RY], (v & 1) ^ 1, 1) > D))
	{
		RY--;
		if (col[2 * byY[RY + 1].id + 1] == -1)
			dfsColor(2 * byY[RY + 1].id + 1);
	}

	return;
}

bool solve()
{
	init();
	for (int v = 0; v < 2 * n; v++)
	{
		if (used[v]) continue;
		dfsOrd(v);
	}
	reverse(ord, ord + 2 * n);
	for (int i = 0; i < 2 * n; i++)
		col[i] = -1;
	LX = LY = 0;
	RX = RY = n - 1;
	C = 0;
	for (int i = 0; i < 2 * n; i++)
	{
		int v = ord[i];
		if (col[v] != -1) continue;
		dfsColor(v);
		C++;
	}
	for (int i = 0; i < n; i++)
		if (col[2 * i] == col[2 * i + 1])
			return false;
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	ll L = -1, R = INF;
	while(R - L > 1)
	{
		D = (L + R) / 2;
		if (solve())
			R = D;
		else
			L = D;
	}
	printf("%lld\n", R);

	return 0;
}