#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MaxN = 100000;

int main()
{
	int n, m, h, t;
	static vector<int> adj[MaxN + 1];

	cin >> n >> m >> h >> t;
	for (int i = 0; i < m; i++)
	{
		int v, u;
		scanf("%d %d", &v, &u);
		adj[v].push_back(u);
		adj[u].push_back(v);
	}

	static bool hasV[MaxN + 1];
	static bool isNotSure[MaxN + 1];
	
	vector<int> head;
	vector<int> tail;
	vector<int> notSure;
	for (int v = 1; v <= n; v++)
	{
		if (adj[v].size() < h + 1)
			continue;

		for (vector<int>::iterator i = adj[v].begin(); i != adj[v].end(); i++)
			hasV[*i] = true;

		for (vector<int>::iterator i = adj[v].begin(); i != adj[v].end(); i++)
		{
			int u = *i;
			if (adj[u].size() < t + 1)
				continue;
			for (vector<int>::iterator j = adj[u].begin(); j != adj[u].end(); j++)
			{
				if (*j == v)
					continue;
				if (!hasV[*j])
					tail.push_back(*j);
				else
				{
					notSure.push_back(*j);
					isNotSure[*j] = true;
				}
				if (tail.size() == t)
					break;
				if (tail.size() + notSure.size() == h + t)
					break;
			}
			if ((adj[v].size() - 1) - (t - tail.size()) < h)
			{
				tail.clear();
				for (vector<int>::iterator j = notSure.begin(); j != notSure.end(); j++)
					isNotSure[*j] = false;
				notSure.clear();
				continue;
			}
			while (tail.size() < t)
			{
				tail.push_back(notSure.back());
				notSure.pop_back();
			}
			while (!notSure.empty())
			{
				head.push_back(notSure.back());
				notSure.pop_back();
			}
			for (vector<int>::iterator j = adj[v].begin(); j != adj[v].end(); j++)
			{
				if (*j == u)
					continue;
				if (!isNotSure[*j])
					head.push_back(*j);
				if (head.size() >= h)
					break;
			}
			head.resize(h);

			cout << "YES" << endl;
			cout << v << ' ' << u << endl;
			for (vector<int>::iterator j = head.begin(); j != head.end(); j++)
				printf("%d ", *j);
			cout << endl;
			for (vector<int>::iterator j = tail.begin(); j != tail.end(); j++)
				printf("%d ", *j);
			cout << endl;
			return 0;
		}

		for (vector<int>::iterator i = adj[v].begin(); i != adj[v].end(); i++)
			hasV[*i] = false;
	}

	cout << "NO" << endl;

	return 0;
}