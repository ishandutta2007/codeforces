#include <iostream>
#include <cstdio>
using namespace std;

const int L = 100;
bool f[L + 1][L + 1][L + 1][L + 1];
bool vis[L + 1][L + 1][L + 1][L + 1];

bool dfs(int x1, int y1, int x2, int y2)
{
	if (x1 < 0 || y1 < 0)
		return false;
	if (x2 < 0 || y2 < 0)
		return true;
	if (x1 == 0 && y1 == 0)
		return true;
	if (x2 == 0 && y2 == 0)
		return false;
	if (vis[x1][y1][x2][y2])
		return f[x1][y1][x2][y2];
	vis[x1][y1][x2][y2] = true;

	for (int dx = 0; dx <= 1; dx++)
		for (int dy = 0; dy <= 1; dy++)
			if (dx + dy <= 1)
			{
				if (x1 - dx == x2 && y1 - dy == y2)
					continue;
				bool b = true;
				for (int cx = 0; cx <= 1; cx++)
					for (int cy = 0; cy <= 1; cy++)
					{
						if (x1 - dx == x2 - cx && y1 - dy == y2 - cy)
							continue;
						if (!dfs(x1 - dx, y1 - dy, x2 - cx, y2 - cy))
							b = false;
					}
				if (b == true)
					return f[x1][y1][x2][y2] = true;
			}
	return f[x1][y1][x2][y2] = false;
}

inline bool solve(int x1, int y1, int x2, int y2)
{
	if (x1 <= x2 && y1 <= y2)
		return true;
	return x1 + y1 <= max(x2, y2);
}

int main()
{
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	puts(solve(x1, y1, x2, y2) ? "Polycarp" : "Vasiliy");

	return 0;
}