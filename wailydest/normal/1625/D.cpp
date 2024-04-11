#include <cstdio>
#include <vector>

const int N = 300005;
const int LG = 30;
int n, k, to[N * LG][2], size = 1, end[N * LG], down[N * LG];
std::vector<int> ans;

void add(int x, int ind) 
{
	int cur = 0;
	for (int i = LG - 1; i >= 0; --i) {
		if (!to[cur][x >> i & 1]) to[cur][x >> i & 1] = size++;
		cur = to[cur][x >> i & 1];
		down[cur] = ind;
	}
	end[cur] = ind;
}

bool less(std::vector<int> a, std::vector<int> b) 
{
	return a.size() < b.size();
}

std::vector<int> run(int u, int v, int lvl) 
{
	std::vector<int> res;
	if (!u || !v || !lvl) {
		if (u) res.push_back(down[u]);
		if (v) res.push_back(down[v]);
	} else {
		--lvl;
		if (k >> lvl & 1) {
			std::vector<int> v1 = run(to[u][0], to[v][1], lvl), v2 = run(to[u][1], to[v][0], lvl);
			if (less(v1, v2)) std::swap(v1, v2);
			res = v1;
		} else {
			if (to[u][0] && to[v][1]) {
				res.push_back(down[to[u][0]]);
				res.push_back(down[to[v][1]]);
			} else if (to[u][1] && to[v][0]) {
				res.push_back(down[to[u][1]]);
				res.push_back(down[to[v][0]]);
			} else {
				std::vector<int> v1 = run(to[u][0], to[v][0], lvl), v2 = run(to[u][1], to[v][1], lvl);
				if (less(v1, v2)) std::swap(v1, v2);
				res = v1;
			}
		}
	}
	return res;
}

void run(int v, int lvl) 
{
	if (!lvl) {
		ans.push_back(end[v]);
		return;
	}
	--lvl;
	if (k >> lvl & 1) {
		std::vector<int> vec = run(to[v][0], to[v][1], lvl);
		ans.insert(ans.end(), vec.begin(), vec.end());
	} else {
		if (to[v][0]) run(to[v][0], lvl);
		if (to[v][1]) run(to[v][1], lvl);
	}
}

int main() 
{
	scanf("%d%d", &n, &k);
	if (!k) {
		printf("%d\n", n);
		for (int i = 0; i < n; ++i) printf("%d ", i + 1);
		printf("\n");
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		add(x, i);
	}
	run(0, LG);
	if (ans.size() == 1) printf("-1\n");
	else {
		printf("%d\n", (int)ans.size());
		for (int i = 0; i < (int)ans.size(); ++i) printf("%d ", ans[i] + 1);
		printf("\n");
	}
	return 0;
}