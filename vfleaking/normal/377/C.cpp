#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <climits>
using namespace std;

const int MaxN = 100;
const int MaxM = 20;

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

int n;
int a[MaxN];

int m;
char qt[MaxM];
int qv[MaxM];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> qt[i] >> qv[i];

	sort(a, a + n, greater<int>());

	static int cntOne[1 << MaxM];
	cntOne[0] = 0;
	for (int i = 1; i < (1 << m); i++)
		cntOne[i] = cntOne[i ^ (i & -i)] + 1;

	static int f[MaxM + 1][1 << MaxM];
	f[m][~(~0 << m)] = 0;
	for (int i = m - 1; i >= 0; i--)
		for (int status = 0; status < (1 << m); status++)
		{
			if(cntOne[status] != i)
				continue;
			if (qv[i] == 1)
			{
				if (qt[i] == 'p')
				{
					int j = 0;
					while (status >> j & 1)
						j++;
					f[i][status] = f[i + 1][status | 1 << j] + a[j];
				}
				else
				{
					f[i][status] = INT_MIN;
					for (int j = 0; j < m; j++)
						if (!(status >> j & 1))
							relax(f[i][status], f[i + 1][status | 1 << j]);
				}
			}
			else
			{
				if (qt[i] == 'p')
				{
					int j = 0;
					while (status >> j & 1)
						j++;
					f[i][status] = f[i + 1][status | 1 << j] - a[j];
				}
				else
				{
					f[i][status] = INT_MAX;
					for (int j = 0; j < m; j++)
						if (!(status >> j & 1))
							tension(f[i][status], f[i + 1][status | 1 << j]);
				}
			}
		}

	cout << f[0][0] << endl;

	return 0;
}