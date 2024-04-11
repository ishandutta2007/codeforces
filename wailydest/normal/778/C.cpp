#include <cstdio>

const int N = 300000;
const int A = 26;
int n, size[N], amt, to[N << 1][A], it[N << 1][A], d[N], dec[N], cur_it;

void add(int v, int from) 
{
	for (int i = 0; i < A; ++i) if (to[from][i] && !it[from][i]) {
		if (!to[v][i] || it[v][i] && it[v][i] != cur_it) {
			it[v][i] = cur_it;
			to[v][i] = amt++;
		}
		add(to[v][i], to[from][i]);
	}
}

void dfs(int v) 
{
	size[v] = 1;
	int id = -1;
	for (int i = 0; i < A; ++i) if (to[v][i]) {
		d[to[v][i]] = d[v] + 1;
		dfs(to[v][i]);
		size[v] += size[to[v][i]];
		if (id == -1 || size[to[v][id]] < size[to[v][i]]) id = i;
	}
	if (size[v] > 1) {
		amt = n;
		cur_it = v + 1;
		for (int i = 0; i < A; ++i) if (to[v][i] && i != id) add(to[v][id], to[v][i]);
		dec[d[v]] += size[v] - size[to[v][id]] - amt + n;
	}
}

int main() 
{
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int a, b;
		char c;
		scanf("%d%d %c", &a, &b, &c);
		to[a - 1][c - 'a'] = b - 1;
	}
	dfs(0);
	int opt = 0;
	for (int i = 0; i < n; ++i) if (dec[i] > dec[opt]) opt = i;
	printf("%d\n%d\n", n - dec[opt], opt + 1);
	return 0;
}