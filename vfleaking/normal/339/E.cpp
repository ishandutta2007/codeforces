#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int MaxN = 1000;
const int MaxM = 7;
const int MaxStep = 3;

int n;
int a[MaxN + 1];

int m;
int pS[MaxM + 1];

struct block
{
	int id;
	int dir;
};
int bl;
block b[MaxM + 1];

int solS[MaxM + 1];
int solL[MaxStep];
int solR[MaxStep];

bool check(int i, int p)
{
	if (i == m + 1)
	{
		if (p != bl + 1)
			return false;

		static int lab[MaxM + 1];
		lab[0] = 0;
		for (int i = 1; i <= bl; i++)
			lab[i] = lab[i - 1] + solS[i];
		int s = 0;
		for (int k = 1; k <= bl; k++)
		{
			if (max(a[s + 1], a[s + solS[b[k].id]]) != lab[b[k].id])
				return false;
			s += solS[b[k].id];
		}
		return true;
	}
	if (p == bl + 1)
		return false;
	if (pS[i] - pS[i - 1] == 1)
	{
		solS[b[p].id] = 1;
		return check(i + 1, p + 1);
	}
	else
	{
		int q = p + 1;
		int pd = a[pS[i]] - a[pS[i] - 1];
		while (q <= bl && b[q].id - b[q - 1].id == pd)
			q++;

		for (int r = p; r < q; r++)
		{
			int rest = pS[i] - pS[i - 1];
			for (int k = p; k <= r; k++)
				if (b[k].dir != pd)
					solS[b[k].id] = 1, rest--;
			if (rest < 0)
				continue;
			if (rest > 0)
			{
				int c = -1;
				for (int k = p; k <= r; k++)
					if (b[k].dir == pd)
					{
						c = k;
						break;
					}
				if (c == -1)
					continue;
				for (int k = p; k <= r; k++)
					if (b[k].dir == pd && k != c)
						solS[b[k].id] = 1, rest--;
				if (rest <= 0)
					continue;
				solS[b[c].id] = rest;
			}
			if (check(i + 1, r + 1))
				return true;
		}
		return false;
	}
}

void dfs(int step)
{
	if (check(1, 1))
	{
		vector< pair<int, int> > ans;
		for (int i = 0; i < step; i++)
		{
			int l = 0;
			for (int k = 1; k <= bl; k++)
				if (solL[i] >> k & 1)
					l += solS[k];
			int r = 0;
			for (int k = 1; k <= bl; k++)
				if (solR[i] >> k & 1)
					r += solS[k];
			if (l + 1 != r)
				ans.push_back(make_pair(l + 1, r));
		}
		printf("%d\n", (int)ans.size());
		for (int i = 0; i < (int)ans.size(); i++)
			printf("%d %d\n", ans[i].first, ans[i].second);
		exit(0);
	}
			
	if (step == MaxStep)
		return;

	solL[step] = 0;
	for (int i = 1; i <= bl; i++)
	{
		solR[step] = solL[step];
		for (int j = i; j <= bl; j++)
		{
			solR[step] += 1 << b[j].id;

			for (int k = i; k <= j; k++)
				b[k].dir = -b[k].dir;
			reverse(b + i, b + j + 1);

			dfs(step + 1);

			reverse(b + i, b + j + 1);
			for (int k = i; k <= j; k++)
				b[k].dir = -b[k].dir;
		}
		solL[step] += 1 << b[i].id;
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	m = 0;
	pS[0] = 0;
	for (int i = 2; i <= n; i++)
		if (abs(a[i] - a[i - 1]) != 1 && a[i] - a[i - 1] != a[i + 1] - a[i])
			pS[++m] = i - 1;
	pS[++m] = n;

	bl = m - 1;
	while (bl < 7)
	{
		bl++;
		for (int i = 1; i <= bl; i++)
			b[i].id = i, b[i].dir = 1;
		dfs(0);
	}

	return 0;
}