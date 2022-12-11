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

const int N = 2000;
const int K = 10;

struct Point
{
	int x, y;
	Point () : x(), y() {}
	Point (int _x, int _y) : x(_x), y(_y) {}
	Point operator + (const Point &a) const
	{
		return Point(x + a.x, y + a.y);
	}
	Point operator - (const Point &a) const
	{
		return Point(x - a.x, y - a.y);
	}
	ll operator % (const Point &a) const
	{
		return 1LL * x * a.x + 1LL * y * a.y;
	}
	ll operator * (const Point &a) const
	{
		return 1LL * x * a.y - 1LL * y * a.x;
	}
	void scan()
	{
		scanf("%d%d", &x, &y);
	}
	void print()
	{
		printf("%d %d\n", x, y);
	}
	void eprint()
	{
		eprintf("%d %d\n", x, y);
	}
};

int k, n;
Point stone[K];
Point p[N];

void read()
{
	scanf("%d %d", &k, &n);
	for (int i = 0; i < k; i++)
		stone[i].scan();
	for (int i = 0; i < n; i++)
		p[i].scan();
}

bool onLine(Point P, Point A, Point v)
{
	return (P - A) * v == 0;
}

bool onSegment(Point P, Point A, Point B)
{
	return onLine(P, A, B - A) && ((P - A) % (P - B)) < 0;
}

int locInter[N];
int locCnt = 0;

const int CNT = 10;
int cntShoot[K][N];
int shoots[K][N][CNT];

void precalc()
{
	for (int i = 0; i < k; i++)
	{
		for (int s = 0; s < n; s++)
		{
			locCnt = 0;
			for (int a = 0; a < n; a++)
			{
				if (onSegment(p[a], stone[i], p[s]))
					locInter[locCnt++] = a;
			}
			if (locCnt > CNT)
			{
				cntShoot[i][s] = -1;
				continue;
			}
			for (int a = 0; a < locCnt; a++)
				shoots[i][s][a] = locInter[a];
			cntShoot[i][s] = locCnt;
		}
	}
}

int perm[K];
int inter[N];
int cntInter = 0;
int used[N];
int killed[N];

bool brute(int pos)
{
	int cntNonKilled = 0;
	for (int i = 0; i < cntInter; i++)
		if (!killed[inter[i]])
			cntNonKilled++;
	if (pos == -1 || cntNonKilled == 0)
		return cntNonKilled == 0;

	int oldCnt = cntInter;
	int oldNonKilled = cntNonKilled;
	for (int i = 0; i < oldCnt; i++)
	{
		if (killed[inter[i]])
			continue;
		int id = perm[pos];
		int v = inter[i];
		if (cntShoot[id][v] == -1)
			continue;

		for (int s = 0; s < cntShoot[id][v]; s++)
		{
			int u = shoots[id][v][s];
			if (killed[u])
				continue;
			cntNonKilled++;
			inter[cntInter++] = u;
			if (cntNonKilled - 1 > pos)
				break;
		}
		bool res = false;

		killed[v] = true;
		if (cntNonKilled - 1 <= pos && brute(pos - 1))
			res = true;
		killed[v] = false;
		cntInter = oldCnt;
		cntNonKilled = oldNonKilled;

		if (res)
			return true;
	}
	return false;
}

void solve()
{
	precalc();
	for (int i = 0; i < k; i++)
		perm[i] = i;
	int ans = 0;
	do
	{
		for (int i = 0; i < n; i++)
		{
			if (used[i] || cntShoot[perm[k - 1]][i] == -1)
				continue;
			cntInter = 0;
			for (int a = 0; a < cntShoot[perm[k - 1]][i]; a++)
				inter[cntInter++] = shoots[perm[k - 1]][i][a];

			killed[i] = true;
			if (brute(k - 2))
			{
				used[i] = 1;
				ans++;
			}
			killed[i] = false;
		}
	} while (next_permutation(perm, perm + k));
	printf("%d\n", ans);
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	read();
	solve();

	return 0;
}