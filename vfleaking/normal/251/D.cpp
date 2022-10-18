#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;

typedef long long s64;

const int MaxN = 100000;

int main()
{
	int n;
	static s64 x[MaxN];
	s64 sum = 0;
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%I64d", &x[i]);
		sum ^= x[i];
	}
	
	int len = 0;
	static bitset<MaxN + 1> mat[64];
	for (int i = 62; i >= 0; i--)
		if (~sum & (1ll << i))
		{
			for (int j = 0; j < n; j++)
				mat[len][j] = (x[j] & (1ll << i)) ? 1 : 0;
			len++;
		}
	for (int i = 62; i >= 0; i--)
		if (sum & (1ll << i))
		{
			for (int j = 0; j < n; j++)
				mat[len][j] = (x[j] & (1ll << i)) ? 1 : 0;
			len++;
		}
	
	static int d[64];
	for (int i = 0; i < len; i++)
	{
		mat[i][n] = 1;
		for (int j = 0; j < i; j++)
			if (d[j] != n && mat[i][d[j]])
				mat[i] ^= mat[j];
		for (d[i] = 0; d[i] < n && mat[i][d[i]] == 0; d[i]++);
		if (d[i] != n)
		{
			for (int j = 0; j < i; j++)
				if (mat[j][d[i]])
					mat[j] ^= mat[i];
		}
	}
	
	static int res[MaxN];
	fill(res, res + n, 1);
	for (int i = 0; i < len; i++)
		if (d[i] != n)
			res[d[i]] = mat[i][n] ? 2 : 1;
	
	for (int i = 0; i < n; i++)
		printf("%d ", res[i]);
	cout << endl;
	
	return 0;
}