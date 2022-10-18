#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 300000;

int ufs_f[MaxN + 2];
inline int ufs_find(const int &v)
{
	if (ufs_f[v] != v)
		ufs_f[v] = ufs_find(ufs_f[v]);
	return ufs_f[v];
}

int main()
{
	int n, m;

	cin >> n >> m;
	for (int i = 1; i <= n + 1; i++)
		ufs_f[i] = i;

	static int res[MaxN + 1];

	while (m--)
	{
		int le, ri, winner;
		scanf("%d %d %d", &le, &ri, &winner);

		for (int i = ufs_find(le); i <= ri; i = ufs_find(i + 1))
			if (i != winner)
			{
				res[i] = winner;
				ufs_f[i] = ufs_find(i + 1);
			}
	}

	for (int i = 1; i <= n; i++)
		printf("%d ", res[i]);
	cout << endl;

	return 0;
}