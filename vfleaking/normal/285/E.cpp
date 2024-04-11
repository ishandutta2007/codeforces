#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

const int M = 1000000007;

const int MaxN = 1000;
const int MaxG = 1000;

inline int &modaddto(int &a, const int &b)
{
	a = (a + b) % M;
	return a;
}

int main()
{
	int n, nG;
	cin >> n >> nG;

	static int f[MaxN + 1][MaxG + 1][3][3];

	f[1][0][0][0] = 1;
	for (int i = 1; i < n; i++)
		for (int g = 0; g <= i; g++)
			for (int ta = 0; ta < 3; ta++)
				for (int tb = 0; tb < 3; tb++)
					if (f[i][g][ta][tb])
					{
						int cur = f[i][g][ta][tb];
						modaddto(f[i + 1][g][0][0], cur);
						if (ta == 0 && tb == 0)
						{
							modaddto(f[i + 1][g + 2][1][1], cur);
							modaddto(f[i + 1][g][2][2], (s64)cur * (i - g - 1) % M);
							modaddto(f[i + 1][g - 1][2][2], (s64)cur * g % M);
						}
						else
						{
							if (ta == 1)
								modaddto(f[i + 1][g][2][1], cur);
							else
								modaddto(f[i + 1][g + 1][2][1], cur);
							if (tb == 1)
								modaddto(f[i + 1][g][1][2], cur);
							else
								modaddto(f[i + 1][g + 1][1][2], cur);
							modaddto(f[i + 1][g][2][2], (s64)cur * (i - g - (ta != 1) - (tb != 1)) % M);
							modaddto(f[i + 1][g - 1][2][2], (s64)cur * (g - (ta == 1) - (tb == 1)) % M);
						}
					}

	int res = 0;
	for (int ta = 0; ta < 3; ta++)
		for (int tb = 0; tb < 3; tb++)
			modaddto(res, f[n][nG][ta][tb]);

	cout << res << endl;

	return 0;
}