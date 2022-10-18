#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

const int MaxLogN = 18;
const int MaxN = 200000;

// adjust
template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}
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
	int n;
	static int ap[MaxN + 2], al[MaxN + 2];

	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &ap[i], &al[i]);

	ap[n + 1] = INT_MAX, al[n + 1] = 0;

	static int next[MaxLogN + 1][MaxN + 2];
	static int cost[MaxLogN + 1][MaxN + 2];

	int q_t = 0;
	static int q[MaxN + 1];

	next[0][n + 1] = n + 1;
	cost[0][n + 1] = 0;
	q[q_t++] = n + 1;

	for (int i = n; i >= 1; i--)
	{
		int ex = ap[i] + al[i];
		while (ap[q[q_t - 1]] <= ex)
		{
			relax(ex, ap[next[0][q[q_t - 1]]] - cost[0][q[q_t - 1]]);
			q_t--;
		}
		next[0][i] = q[q_t - 1];
		cost[0][i] = ap[q[q_t - 1]] - ex;
		q[q_t++] = i;
	}

	for (int j = 1; j <= MaxLogN; j++)
		for (int i = 1; i <= n + 1; i++)
		{
			next[j][i] = next[j - 1][next[j - 1][i]];
			cost[j][i] = cost[j - 1][i] + cost[j - 1][next[j - 1][i]];
		}

	int nQ;
	cin >> nQ;
	while (nQ--)
	{
		int l, r;
		scanf("%d %d", &l, &r);

		int res = 0;
		for (int j = MaxLogN; j >= 0; j--)
			if (next[j][l] <= r)
			{
				res += cost[j][l];
				l = next[j][l];
			}
		printf("%d\n", res);
	}

	return 0;
}