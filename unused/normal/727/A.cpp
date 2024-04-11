#include "bits/stdc++.h"
using namespace std;

unordered_map<int, int> visit;

int main()
{
	int a, b;
	scanf("%d%d",&a,&b);

	queue<int> que;
	visit[a] = -1;
	que.push(a);
	while (que.empty() == false)
	{
		int t = que.front();
		que.pop();

		if (t == b)
		{
			printf("YES\n");
			vector<int> path;
			while (b != -1)
			{
				path.push_back(b);
				b = visit[b];
			}

			printf("%d\n", (int)path.size());
			for (int i = path.size() - 1; i >= 0; i--) printf("%d ", path[i]);
			return 0;
		}

		if ((long long)t * 10 + 1 <= b)
		{
			if (visit.emplace(t * 10 + 1, t).second) que.push(t * 10 + 1);
		}
		if ((long long)t*2 <= b)
		{
			if (visit.emplace(t * 2, t).second) que.push(t * 2);
		}
	}
	printf("NO");
}