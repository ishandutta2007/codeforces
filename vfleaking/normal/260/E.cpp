#include <iostream>
#include <iomanip>
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

const int MaxN = 100000;

const int D = 3;
const int D2 = 9;

const int MaxNSol = 362880;

struct event
{
	int x, y, s;
	int belong;

	friend inline bool operator<(const event &lhs, const event &rhs)
	{
		if (lhs.x != rhs.x)
			return lhs.x < rhs.x;
		return lhs.s < rhs.s;
	}
};
struct solution
{
	int x[D - 1], y[D - 1];
	bool ok;
};

int main()
{
	int n;
	int seqX_n = 0;
	static int seqX[MaxN];
	int seqY_n = 0;
	static int seqY[MaxN];
	static pair<int, int> po[MaxN];
	static int a[D2];

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &po[i].first, &po[i].second);
		seqX[seqX_n++] = po[i].first;
		seqY[seqY_n++] = po[i].second;
	}
	for (int i = 0; i < D2; i++)
		scanf("%d", &a[i]);

	sort(seqX, seqX + seqX_n);
	sort(seqY, seqY + seqY_n);

	for (int i = 0; i < n; i++)
	{
		po[i].first = lower_bound(seqX, seqX + seqX_n, po[i].first) - seqX;
		po[i].second = lower_bound(seqY, seqY + seqY_n, po[i].second) - seqY;
	}

	int sol_n = 0;
	static solution sol[MaxNSol];
	int eli_n = 0;
	static event eli[MaxN + MaxNSol * (D - 1) * (D - 1)];

	for (int i = 0; i < n; i++)
	{
		eli[eli_n].x = po[i].first;
		eli[eli_n].y = po[i].second;
		eli[eli_n].s = -1;
		eli_n++;
	}

	static int per[MaxN];
	for (int i = 0; i < D2; i++)
		per[i] = i;
	do
	{
		int sum[D][D];
		for (int i = 0; i < D; i++)
			for (int j = 0; j < D; j++)
			{
				sum[i][j] = a[per[i * D + j]];
				if (i - 1 >= 0)
					sum[i][j] += sum[i - 1][j];
				if (j - 1 >= 0)
					sum[i][j] += sum[i][j - 1];
				if (i - 1 >= 0 && j - 1 >= 0)
					sum[i][j] -= sum[i - 1][j - 1];
			}

		for (int i = 0; i < D - 1; i++)
			sol[sol_n].x[i] = sum[i][D - 1] - 1;
		for (int j = 0; j < D - 1; j++)
			sol[sol_n].y[j] = sum[D - 1][j] - 1;

		bool ok = true;
		for (int i = 0; i < D - 1; i++)
			if (seqX[sol[sol_n].x[i]] == seqX[sol[sol_n].x[i] + 1])
				ok = false;
		for (int j = 0; j < D - 1; j++)
			if (seqY[sol[sol_n].y[j]] == seqY[sol[sol_n].y[j] + 1])
				ok = false;
		if (ok)
		{
			for (int i = 0; i < D - 1; i++)
				for (int j = 0; j < D - 1; j++)
				{
					eli[eli_n].x = sol[sol_n].x[i];
					eli[eli_n].y = sol[sol_n].y[j];
					eli[eli_n].s = sum[i][j];
					eli[eli_n].belong = sol_n;
					eli_n++;
				}
			sol[sol_n].ok = true;
			sol_n++;
		}
	}
	while (next_permutation(per, per + D2));

	sort(eli, eli + eli_n);

	static int bit[MaxN + 1];
	for (int i = 0; i < eli_n; i++)
	{
		event e = eli[i];
		if (e.s == -1)
		{
			for (int p = e.y + 1; p < n; p += p & -p)
				bit[p]++;
		}
		else
		{
			int res = 0;
			for (int p = e.y + 1; p >= 1; p -= p & -p)
				res += bit[p];
			if (res != e.s)
				sol[e.belong].ok = false;
		}
	}

	while (sol_n > 0 && !sol[sol_n - 1].ok)
		sol_n--;
	if (sol_n == 0)
		cout << -1 << endl;
	else
	{
		cout << fixed << setprecision(3);
		for (int i = 0; i < D - 1; i++)
			cout << seqX[sol[sol_n - 1].x[i]] + 0.1 << " ";
		cout << endl;
		for (int j = 0; j < D - 1; j++)
			cout << seqY[sol[sol_n - 1].y[j]] + 0.1 << " ";
		cout << endl;
	}

	return 0;
}