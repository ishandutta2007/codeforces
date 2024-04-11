#include <iostream>
#include <climits>
using namespace std;

const int MaxN = 500000;
const int MaxK = 26;

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

int main()
{
	int n, k;
	static char s[MaxN + 1];

	cin >> n >> k;
	cin >> s;

	static int f[MaxN + 1][MaxK];
	static int g[MaxN + 1][MaxK];
	for (int i = 0; i < k; i++)
		f[0][i] = 1;
	f[0][s[0] - 'A'] = 0;
	
	for (int i = 1; i < n; i++)
		for (int j = 0; j < k; j++)
		{
			f[i][j] = INT_MAX;
			for (int p = 0; p < k; p++)
				if (p != j)
				{
					if (tension(f[i][j], f[i - 1][p]))
						g[i][j] = p;
				}
			if (j != s[i] - 'A')
				f[i][j]++;
		}

	int final = 0;
	for (int j = 1; j < k; j++)
		if (f[n - 1][j] < f[n - 1][final])
			final = j;
	
	for (int i = n - 1, j = final; i >= 0; i--)
	{
		s[i] = j + 'A';
		j = g[i][j];
	}

	cout << f[n - 1][final] << endl;
	cout << s << endl;

	return 0;
}