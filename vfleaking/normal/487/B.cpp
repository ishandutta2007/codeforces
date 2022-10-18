#include <iostream>
#include <cstdio>
using namespace std;

const int INF = 1000000000;

const int MaxN = 100000;

int main()
{
	int n, s, l;
	static int a[MaxN + 1];
	static int f[MaxN + 1];

	cin >> n >> s >> l;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	int q1_t, q1_b;
	static int q1[MaxN];
	int q2_t, q2_b;
	static int q2[MaxN];
	int q3_t, q3_b;
	static int q3[MaxN];

	q1_t = q1_b = 0;
	q2_t = q2_b = 0;
	q3_t = q3_b = 0;

	f[0] = 0;

	for (int i = 1, j = 1; i <= n; i++)
	{
		while (q1_b != q1_t && a[i] < a[q1[q1_b - 1]])
			q1_b--;
		q1[q1_b++] = i;
		while (q2_b != q2_t && a[i] > a[q2[q2_b - 1]])
			q2_b--;
		q2[q2_b++] = i;

		while (j < i && a[q2[q2_t]] - a[q1[q1_t]] > s)
		{
			if (q1[q1_t] == j)
				q1_t++;
			if (q2[q2_t] == j)
				q2_t++;
			if (q3_t != q3_b && q3[q3_t] == j - 1)
				q3_t++;
			j++;
		}

		if (i - l >= j - 1 && f[i - l] != INF)
		{
			while (q3_b != q3_t && f[i - l] < f[q3[q3_b - 1]])
				q3_b--;
			q3[q3_b++] = i - l;
		}

		if (q3_t == q3_b)
			f[i] = INF;
		else
			f[i] = f[q3[q3_t]] + 1;
	}

	if (f[n] == INF)
		cout << -1 << endl;
	else
		cout << f[n] << endl;

	return 0;
}