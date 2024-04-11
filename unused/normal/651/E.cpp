#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int dat[1000005];
int group[1000005];
int degree[1000005];
int ans[1000005];

vector<int> graph[1000005];

int getparent(int n)
{
	if (group[n] == n) return n;
	return group[n] = getparent(group[n]);
}

void merge(int a, int b)
{
	group[getparent(a)] = group[getparent(b)];
}

set<int> st;
map<int, int> mp;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	for (int i = 0; i < a * b; i++)
	{
		scanf("%d", &dat[i]);
	}

	for (int i = 0; i < a * b; i++)
	{
		group[i] = i;
	}

	for (int i = 0; i < a * b; i += b)
	{
		mp.clear();
		for (int j = 0; j < b; j++)
		{
			auto itr = mp.emplace(dat[i + j], i + j);
			if (itr.second == false) merge(itr.first->second, i + j);
		}
	}

	for (int i = 0; i < b; i++)
	{
		mp.clear();
		for (int j = 0; j < a; j++)
		{
			auto itr = mp.emplace(dat[i + j * b], i + j * b);
			if (itr.second == false) merge(itr.first->second, i + j * b);
		}
	}

	for (int i = 0; i < a * b; i += b)
	{
		mp.clear();
		for (int j = 0; j < b; j++)
		{
			mp.emplace(dat[i + j], i + j);
		}
		for (auto itr = mp.begin(); next(itr) != mp.end(); itr++)
		{
			auto l = getparent(itr->second);
			auto r = getparent(next(itr)->second);
			degree[r]++;
			graph[l].push_back(r);
		}
	}

	for (int i = 0; i < b; i++)
	{
		mp.clear();
		for (int j = 0; j < a; j++)
		{
			mp.emplace(dat[i + j * b], i + j * b);
		}
		for (auto itr = mp.begin(); next(itr) != mp.end(); itr++)
		{
			auto l = getparent(itr->second);
			auto r = getparent(next(itr)->second);
			degree[r]++;
			graph[l].push_back(r);
		}
	}

	queue<int> que;

	for (int i = 0; i < a * b; i++)
	{
		if (degree[i] == 0 && getparent(i) == i)
		{
			ans[i] = 1;
			que.emplace(i);
		}
	}

	while (que.empty() == false)
	{
		auto t = que.front();
		que.pop();

		for (int next : graph[t])
		{
			if (--degree[next] == 0)
			{
				ans[next] = ans[t] + 1;
				que.emplace(next);
			}
		}
	}

	for (int i = 0; i < a * b; i++)
	{
		printf("%d ", ans[getparent(i)]);
		if (i % b == b - 1) printf("\n");
	}
}