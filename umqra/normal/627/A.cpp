#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <sstream>
#include <fstream>
#include <functional>
#include <cassert>
#include <complex>
#include <valarray>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

ll dp[100][2];

int main()
{
	ll X, Y;
	cin >> X >> Y;
	dp[0][0] = 1;
	for (int i = 0; i < 50; i++)
	{
		int ba = ((X >> i) & 1);
		int bb = ((Y >> i) & 1);
		for (int z = 0; z < 2; z++)
		{
			for (int a = 0; a < 2; a++)
			{
				for (int b = 0; b < 2; b++)
				{
					if ((a ^ b) == bb && (a + b + z) % 2 == ba)
						dp[i + 1][(a + b + z) / 2] += dp[i][z];
				}
			}
		}
	}
	ll ans = dp[50][0];
	if (X == Y && ans > 0)
		ans -= 2;
	cout << ans << endl;
	return 0;
}