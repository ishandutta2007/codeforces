#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>

const int N = 200000;
bool u[N], path[N];
int t, n, p[N], from[N];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(from, 0, n << 2);
		memset(u, 0, n);
		memset(path, 0, n);
		int ans = 0, to = -1;
		for (int i = 0; i < n; ++i) {
			scanf("%d", p + i);
			--p[i];
			if (u[p[i]]) {
				to = p[i];
				p[i] = -1;
				++ans;
			}
			else u[p[i]] = true;
		}
		for (int i = 0; i < n; ++i) if (p[i] != -1) from[p[i]] = i + 1;
		std::vector<std::pair<int, int> > snake;
		for (int i = 0; i < n; ++i) if (p[i] == -1) {
			int cur = i;
			while (from[cur]) {
				path[cur] = true;
				cur = from[cur] - 1;
			}
			snake.push_back(std::make_pair(cur, i));
		}
		if (snake.size() == 1) {
			if (snake.back().first == snake.back().second) {
				p[from[to] - 1] = snake.back().first;
				p[snake.back().second] = to;
			}
			else p[snake.back().second] = snake.back().first;
		}
		else for (int j = 0; j < (int)snake.size(); ++j) p[snake[j].second] = snake[j == (int)snake.size() - 1 ? 0 : j + 1].first;
		printf("%d\n", n - ans);
		for (int i = 0; i < n; ++i) printf("%d ", p[i] + 1);
		printf("\n");
	}
	return 0;
}