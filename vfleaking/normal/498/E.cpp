#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int M = 1000000007;

const int N = 7;

int main()
{
	static int f[1 << N];
	static int g[1 << N];
	f[0] = 1;
	for (int l = 1; l <= N; l++)
	{
		int w;
		cin >> w;

		static int b[1 << N][1 << N];
		for (int s = 0; s < (1 << l); s++)
			for (int t = 0; t < (1 << l); t++)
			{
				b[s][t] = 0;
				for (int rf = 0; rf < (1 << (l - 1)); rf++)
				{
					int r = 1 | rf << 1 | (1 << l);
					if (!(s & t & r & (r >> 1)))
						b[s][t]++;
				}
			}

		static int res[1 << N][1 << N];
		static int o[1 << N][1 << N];
		for (int s = 0; s < (1 << l); s++)
			for (int t = 0; t < (1 << l); t++)
				res[s][t] = s == t;

		for (int v = w; v > 0; v >>= 1)
		{
			if (v & 1)
			{
				for (int s = 0; s < (1 << l); s++)
					for (int t = 0; t < (1 << l); t++)
					{
						o[s][t] = 0;
						for (int r = 0; r < (1 << l); r++)
							o[s][t] = (o[s][t] + (long long)res[s][r] * b[r][t]) % M;
					}
				memcpy(res, o, sizeof(res));
			}
			for (int s = 0; s < (1 << l); s++)
				for (int t = 0; t < (1 << l); t++)
				{
					o[s][t] = 0;
					for (int r = 0; r < (1 << l); r++)
						o[s][t] = (o[s][t] + (long long)b[s][r] * b[r][t]) % M;
				}
			memcpy(b, o, sizeof(b));
		}

		for (int s = 0; s < (1 << l); s++)
			g[s] = 0;
		for (int s = 0; s < (1 << (l - 1)); s++)
			g[s | 1 << (l - 1)] = f[s];
		for (int s = 0; s < (1 << l); s++)
			f[s] = 0;
		for (int s = 0; s < (1 << l); s++)
			for (int t = 0; t < (1 << l); t++)
				f[t] = (f[t] + (long long)g[s] * res[s][t]) % M;
	}

	cout << f[(1 << N) - 1] << endl;

	return 0;
}