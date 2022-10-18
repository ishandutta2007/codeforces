#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

// adjust
template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool tension(T &a, const T &b)
{
	if (b < a)
	{
		a = b;
		return true;
	}
	return false;
}

int cnt[5][5];

bool check(int hintX, int hintY)
{
	for (int x = 0; x < 5; x++)
		if (hintX >> x & 1)
		{
			int c = 0, d = 0;
			for (int y = 0; y < 5; y++)
				c += cnt[x][y] > 0, d += cnt[x][y] > 0 && (hintY >> y & 1);
			if (c - d > 1)
				return false;
		}

	bool book[5];
	fill(book, book + 5, false);
	for (int x = 0; x < 5; x++)
		if (!(hintX >> x & 1))
		{
			for (int y = 0; y < 5; y++)
				if (cnt[x][y] > 0)
				{
					if (book[y])
						return false;
					book[y] = true;
				}
		}
	int c = 0, d = 0;
	for (int y = 0; y < 5; y++)
		c += book[y], d += book[y] && (hintY >> y & 1);
	return c - d <= 1;
}

int main()
{
	int n;
	cin >> n;

	map<char, int> orz;
	orz['R'] = 0;
	orz['G'] = 1;
	orz['B'] = 2;
	orz['Y'] = 3;
	orz['W'] = 4;

	for (int i = 0; i < n; i++)
	{
		char c, d;
		cin >> c >> d;
		cnt[orz[c]][d - '1']++;
	}

	int res = 10;

	for (int hintX = 0; hintX < (1 << 5); hintX++)
		for (int hintY = 0; hintY < (1 << 5); hintY++)
			if (check(hintX, hintY))
			{
				int cur = 0;
				for (int x = 0; x < 5; x++)
					if (hintX >> x & 1)
						cur++;
				for (int y = 0; y < 5; y++)
					if (hintY >> y & 1)
						cur++;
				tension(res, cur);
			}
	cout << res << endl;

	return 0;
}