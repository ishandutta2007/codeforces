#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

const int MaxN = 20;
const int NLetter = 26;

template <class T>
inline void tension(T &a, const T &b)
{
	if (b < a)
		a = b;
}
template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

int main()
{
	int n;
	static char a[MaxN][MaxN];

	cin >> n;
	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
			while (a[x][y] = getchar(), 'a' > a[x][y] || a[x][y] > 'z');

	static int available[MaxN * 2 - 1][NLetter];
	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
			available[x + y][a[x][y] - 'a'] |= 1 << min(x, n - 1 - y);

	static int f[MaxN * 2 - 1][1 << MaxN];
	f[n * 2 - 2][1] = 0;
	for (int s = n * 2 - 3; s >= 0; s--)
	{
		int l = min(s + 1, n * 2 - 1 - s);
		for (int status = 0; status < (1 << l); status++)
		{
			int t = status;
			if (s < n - 1)
				t |= status << 1;
			else
				t |= status >> 1;

			if (s & 1)
				f[s][status] = INT_MIN;
			else
				f[s][status] = INT_MAX;
			for (int c = 0; c < NLetter; c++)
				if (t & available[s + 1][c])
				{
					int delta = (c == 0) - (c == 1);
					if (s & 1)
						relax(f[s][status], f[s + 1][t & available[s + 1][c]] + delta);
					else
						tension(f[s][status], f[s + 1][t & available[s + 1][c]] + delta);
				}
		}
	}

	int res = (a[0][0] == 'a') - (a[0][0] == 'b') + f[0][1];

	if (res > 0)
		cout << "FIRST" << endl;
	else if (res < 0)
		cout << "SECOND" << endl;
	else
		cout << "DRAW" << endl;

	return 0;
}