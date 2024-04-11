#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long s64;

const s64 INF = 4000000000000000000ll;

const int MaxN = 200001;
const int MaxL = 2000000;

// getint
inline s64 getint()
{
    char c;
    while (c = getchar(), ('0' > c || c > '9') && c != '-');
    
    if (c != '-')
    {
        s64 res = c - '0';
        while (c = getchar(), '0' <= c && c <= '9')
            res = res * 10 + c - '0';
        return res;
    }
    else
    {
        s64 res = 0;
        while (c = getchar(), '0' <= c && c <= '9')
            res = res * 10 + c - '0';
        return -res;
    }
}

template <class T>
inline void tension(T &a, const T &b)
{
	if (b < a)
		a = b;
}

int n, l;
s64 pt[MaxN], px[MaxN], py[MaxN];

char res[MaxL + 1];
pair<int, int> b[MaxN];

inline s64 orzmod(s64 a, s64 b)
{
	return (a % b + b) % b;
}

inline s64 orzfloor(s64 a, s64 b)
{
	if (a < 0)
		return -((-a + b - 1) / b);
	return a / b;
}

inline bool check(s64 x, s64 y)
{
	int res_n = 0;
	for (int i = 0; i < n; i++)
	{
		int v = b[i].second, u = b[(i + 1) % n].second;
		if (abs((px[u] - (double)(pt[u] / l) * x) - (px[v] - (double)(pt[v] / l) * x)) > 1.5e18)
			return false;
		if (abs((py[u] - (double)(pt[u] / l) * y) - (py[v] - (double)(pt[v] / l) * y)) > 1.5e18)
			return false;
		s64 dx = (px[u] - (pt[u] / l) * x) - (px[v] - (pt[v] / l) * x);
		s64 dy = (py[u] - (pt[u] / l) * y) - (py[v] - (pt[v] / l) * y);
		s64 dt = i + 1 < n ? b[i + 1].first - b[i].first : l - b[i].first;
		
		if (i + 1 == n)
			dx += x, dy += y;

		if (abs(dx) + abs(dy) > dt)
			return false;
		if ((abs(dx) + abs(dy)) % 2 != dt % 2)
			return false;
		while (dx > 0)
			res[res_n++] = 'R', dx--, dt--;
		while (dx < 0)
			res[res_n++] = 'L', dx++, dt--;
		while (dy > 0)
			res[res_n++] = 'U', dy--, dt--;
		while (dy < 0)
			res[res_n++] = 'D', dy++, dt--;
		while (dt > 0)
			res[res_n++] = 'L', dt--, res[res_n++] = 'R', dt--;
	}
	return true;
}

inline bool handle()
{
	for (int i = 0; i < n; i++)
		if (orzmod(px[i] + py[i], 2) != pt[i] % 2)
			return false;

	for (int i = 0; i < n; i++)
		b[i] = make_pair(pt[i] % l, i);
	sort(b, b + n);

	for (int i = 0; i + 1 < n; i++)
		if (b[i].first == b[i + 1].first)
		{
			int v = b[i].second;
			int u = b[i + 1].second;
			return check((px[v] - px[u]) / ((pt[v] - pt[u]) / l), (py[v] - py[u]) / ((pt[v] - pt[u]) / l));
		}

	s64 sxy = INF, mxy = INF;
	for (int i = 0; i < n; i++)
	{
		int v = b[i].second;
		int u = b[(i + 1) % n].second;

		s64 dx = px[u] - px[v];
		s64 dy = py[u] - py[v];
		s64 dk = pt[u] / l - pt[v] / l;
		s64 dt = i + 1 < n ? b[i + 1].first - b[i].first : l - b[i].first;

		if (i + 1 == n)
			dk--;

		if (dk < 0)
		{
			tension(sxy, orzfloor(dt - dx - dy, -dk));
			tension(mxy, orzfloor(dt - dx + dy, -dk));
		}
		else if (dk > 0)
		{
			tension(sxy, orzfloor(dt + dx + dy, dk));
			tension(mxy, orzfloor(dt + dx - dy, dk));
		}
		else
		{
			if (abs(dx) + abs(dy) > dt)
				return false;
		}
	}
	while (abs(sxy) % 2 != l % 2)
		sxy--;
	while (abs(mxy) % 2 != l % 2)
		mxy--;

	s64 vx = (sxy + mxy) / 2, vy = (sxy - mxy) / 2;
	return check(vx, vy);
}

int main()
{
	cin >> n >> l;
	for (int i = 0; i < n; i++)
		pt[i] = getint(), px[i] = getint(), py[i] = getint();
	pt[n] = 0, pt[n] = 0, py[n] = 0;
	n++;

	if (handle())
		puts(res);
	else
		puts("NO");

	return 0;
}