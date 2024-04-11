#include <iostream>
#include <cstdio>
using namespace std;

const int M = 1000000009;
const int MaxN = 1000;
const int MaxH = 30;

inline int &modaddto(int &a, const int &b)
{
	a += b;
	if (a >= M)
		a -= M;
	return a;
}

int main()
{
	int n, h;
	cin >> n >> h;

	static int f[MaxN + 1][2][MaxH + 1][MaxH + 1][MaxH + 1];
	f[1][0][0][0][0] = 4;
	for (int i = 1; i < n; i++)
		for (int over = 0; over <= 1; over++)
			for (int la = 0; la <= h; la++)
				for (int lb = 0; lb <= h; lb++)
					for (int lc = 0; lc <= h; lc++)
					{
						int cur = f[i][over][la][lb][lc];
						if (cur == 0)
							continue;
						modaddto(f[i + 1][over][min(la + 1, h)][min(lb + 1, h)][min(lc + 1, h)], cur);
						modaddto(f[i + 1][min(la + 1, h) == h][over ? h : 0][min(lb + 1, h)][min(lc + 1, h)], cur);
						modaddto(f[i + 1][min(lb + 1, h) == h][over ? h : 0][min(la + 1, h)][min(lc + 1, h)], cur);
						modaddto(f[i + 1][min(lc + 1, h) == h][over ? h : 0][min(la + 1, h)][min(lb + 1, h)], cur);
					}
	int res = 1;
	for (int i = 0; i < n; i++)
		res = res * 2 % M * 2 % M;
	for (int la = h - 1; la <= h; la++)
		for (int lb = h - 1; lb <= h; lb++)
			for (int lc = h - 1; lc <= h; lc++)
				res = (res + M - f[n][1][la][lb][lc]) % M;

	cout << res << endl;

	return 0;
}