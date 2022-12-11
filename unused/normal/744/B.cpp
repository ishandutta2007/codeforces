#include <bits/stdc++.h>
using namespace std;

constexpr int SIZE = 2;
int matrix[SIZE][SIZE]=
{
	0,0,
	0,0
};

int n;

int dim()
{
#ifdef ONLINE_JUDGE
	int ret;
	scanf("%d", &ret);
	return ret;
#else
	return SIZE;
#endif
}

vector<int> ask(vector<int> &vt)
{
	printf("%d\n", (int)vt.size());
	for (int t : vt) printf("%d ", t + 1);
	printf("\n");
	fflush(stdout);

#ifdef ONLINE_JUDGE
	vector<int> ret(n);
	for (int i = 0; i < n; i++) scanf("%d", &ret[i]);
	return ret;
#else
	vector<int> ret(n);
	for (int i = 0; i < n; i++)
	{
		ret[i] = 2e9;
		for (int t : vt) ret[i] = min(ret[i], matrix[i][t]);
	}
	return ret;
#endif
}

vector<pair<set<int>, vector<int>>> anses;

int main()
{
	n = dim();

	for (int i = 1; i < n; i <<= 1)
	{
		vector<int> quest;
		set<int> inc;
		for (int j = 0; j < n; j++)
		{
			if (j & i)
			{
				quest.push_back(j);
				inc.insert(j);
			}
		}

		anses.emplace_back(move(inc), ask(quest));
	}

	for (int i = 1; i < n; i <<= 1)
	{
		vector<int> quest;
		set<int> inc;

		for (int j = 0; j < n; j++)
		{
			if (!(j & i))
			{
				quest.push_back(j);
				inc.insert(j);
			}
		}

		anses.emplace_back(move(inc), ask(quest));
	}

	printf("-1\n");
	for (int i = 0; i < n; i++)
	{
		int z = 2e9;
		for (auto &&t : anses)
		{
			if (t.first.count(i)) continue;
			z = min(z, t.second[i]);
		}

		printf("%d ", z);
	}
	printf("\n");
	fflush(stdout);
}