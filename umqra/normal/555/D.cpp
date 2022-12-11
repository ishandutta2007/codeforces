#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)2e5 + 10;
pii p[N];
int coord[N];
int pos[N];
int n;


int solve(int id, int len, int dir)
{
	if ((id == 0 || coord[id] - coord[id - 1] > len) &&
		(id == n - 1 || coord[id + 1] - coord[id] > len))
		return id;

	if (dir == 1)
	{
		int nId = upper_bound(coord, coord + n, coord[id] + len) - coord - 1;
		if (nId != id)
		{
			int nLen = len - (coord[nId] - coord[id]);
			int bId = lower_bound(coord, coord + n, coord[nId] - nLen) - coord;
			if (bId != nId)
			{
				int d = coord[nId] - coord[bId];
				int bLen = nLen - d;
				int cnt = bLen / d;
				int rem = bLen % d;
				if (cnt & 1)
					return solve(nId, rem, -1);
				return solve(bId, rem, 1);
			}
			return bId;
		}
		return solve(id, len, -1);
	}
	else
	{
		int nId = lower_bound(coord, coord + n, coord[id] - len) - coord;
		if (nId != id)
		{
			int nLen = len - (coord[id] - coord[nId]);
			int bId = upper_bound(coord, coord + n, coord[nId] + nLen) - coord - 1;
			if (bId != nId)
			{
				int d = coord[bId] - coord[nId];
				int bLen = nLen - d;
				int cnt = bLen / d;
				int rem = bLen % d;
				if (cnt & 1)
					return solve(nId, rem, 1);
				return solve(bId, rem, -1);
			}
			return bId;
		}
		return solve(id, len, 1);
		return solve(id, len, 1);
	}
}

int main()
{
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		p[i] = mp(x, i);
	}
	sort(p, p + n);
	for (int i = 0; i < n; i++)
	{
		pos[p[i].Y] = i;
		coord[i] = p[i].X;
	}
	for (int i = 0; i < m; i++) 
	{
		int id, len;
		scanf("%d%d", &id, &len);
		id = pos[id - 1];
		printf("%d\n", p[solve(id, len, 1)].Y + 1);
	}
	return 0;
}