#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

vector<pair<int, char>> graph[100005];

bool visited[100005];
bool flip[100005];
int n, m;
char tc;

pair<vector<int>, bool> bfs(int node)
{
	queue<int> que;
	vector<int> fliped, nofliped;
	flip[node] = true;
	fliped.push_back(node);
	visited[node] = true;
	que.push(node);

	while (que.empty() == false)
	{
		int t = que.front();
		que.pop();

		for (auto &&e : graph[t])
		{
			if (visited[e.first])
			{
				if ((e.second == tc) == (flip[t] ^ flip[e.first]))
					return {};
				continue;
			}
			if ((tc == e.second) ^ flip[t])
			{
				flip[e.first] = false;
				nofliped.push_back(e.first);
			}
			else
			{
				flip[e.first] = true;
				fliped.push_back(e.first);
			}
			visited[e.first] = true;
			que.push(e.first);
		}
	}

	if (fliped.size() > nofliped.size()) swap(fliped, nofliped);
	return{ move(fliped), true };
}

pair<vector<int>, bool> process()
{
	vector<int> answer;

	memset(visited, 0, sizeof(visited));
	memset(flip, 0, sizeof(flip));
	for (int i = 1; i <= n; i++)
	{
		if (visited[i]) continue;
		auto ret = bfs(i);
		if (ret.second == false) return{};
		answer.insert(answer.end(), ret.first.begin(), ret.first.end());
	}

	return{ move(answer), true };
}

int main()
{
	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int a, b; char ch;
		scanf("%d%d %c", &a, &b, &ch);
		graph[a].emplace_back(b, ch);
		graph[b].emplace_back(a, ch);
	}

	// try blue first
	tc = 'B';
	auto ret = process();
	tc = 'R';
	auto ret2 = process();

	if (ret.second == false && ret2.second == false)
	{
		printf("-1\n");
		return 0;
	}

	vector<int> ans;
	if (ret.second == false) ans = move(ret2.first);
	else if (ret2.second == false) ans = move(ret.first);
	else
	{
		if (ret.first.size() > ret2.first.size()) ans = move(ret2.first);
		else ans = move(ret.first);
	}

	printf("%d\n", (int)ans.size());
	for (int i : ans)
	{
		printf("%d ", i);
	}
	printf("\n");
}