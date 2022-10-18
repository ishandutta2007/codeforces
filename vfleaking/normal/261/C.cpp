#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

typedef long long s64;

const int MaxD = 63;

s64 f[MaxD + 1][MaxD + 1];

inline s64 handle(const s64 &n, const int &cnt)
{
	f[0][0] = 1;
	for (int i = 1; i <= MaxD; i++)
	{
		f[i][0] = 1;
		for (int j = 1; j <= MaxD; j++)
			f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
	}

	s64 t = n;
	int a[MaxD + 1];
	int len = 0;
	while (t > 0)
		a[len++] = t % 2, t /= 2;
	
	s64 res = 0;
	int have = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		if (a[i] == 1)
		{
			res += f[i][cnt - have];
			have++;
		}
		if (have > cnt)
			break;
	}
	if (have == cnt)
		res++;
	return res;
}

int main()
{
	s64 n, t;
	cin >> n >> t;

	int cnt = -1;
	for (int i = 1; i < 63; i++)
		if (t == (1ll << (i - 1)))
			cnt = i;
	if (cnt == -1)
		cout << 0 << endl;
	else
		cout << handle(n + 1, cnt) - (cnt == 1 ? 1 : 0)<< endl;

	return 0;
}