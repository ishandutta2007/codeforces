#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

const int MaxN = 200;
const int MaxA = 40000;

template <class T>
inline void tension(T &a, const T &b)
{
	if (b < a)
		a = b;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	int a, b;
	static int h[MaxN + 1];
	static int sum[MaxN + 1];
	
	cin >> n;
	cin >> a >> b;
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	sum[0] = 0;
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + h[i];
	
	static int f[MaxN + 1][MaxA + 1][2];
	for (int j = 0; j <= a; j++)
		f[1][j][0] = f[1][j][1] = INT_MAX;
	if (h[1] <= a)
		f[1][h[1]][0] = 0;
	if (h[1] <= b)
		f[1][0][1] = 0;
	
	for (int i = 2; i <= n; i++)
		for (int j = 0; j <= a; j++)
		{
			if (sum[i] - j > b)
			{
				f[i][j][0] = f[i][j][1] = INT_MAX;
				continue;
			}
			
			f[i][j][0] = INT_MAX;
			if (h[i] <= j)
			{
				tension(f[i][j][0], f[i - 1][j - h[i]][0]);
				if (f[i - 1][j - h[i]][1] != INT_MAX)
					tension(f[i][j][0], f[i - 1][j - h[i]][1] + min(h[i], h[i - 1]));
			}
			
			f[i][j][1] = INT_MAX;
			if (f[i - 1][j][0] != INT_MAX)
				tension(f[i][j][1], f[i - 1][j][0] + min(h[i], h[i - 1]));
			tension(f[i][j][1], f[i - 1][j][1]);
		}
	
	int res = INT_MAX;
	for (int j = 0; j <= a; j++)
	{
		tension(res, f[n][j][0]);
		tension(res, f[n][j][1]);
	}
	if (res != INT_MAX)
		cout << res << endl;
	else
		cout << -1 << endl;
	
	return 0;
}