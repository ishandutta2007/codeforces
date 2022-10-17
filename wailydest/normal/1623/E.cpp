#include <cstdio>

const int N = 200000;
int n, k, l[N], r[N], in[N];
char s[N + 1], res[N];
bool dup[N], need[N + 1];

void dfs(int v) 
{
	static int dt = 0;
	if (l[v] != -1) dfs(l[v]);
	res[dt] = s[v];
	in[v] = dt++;
	if (r[v] != -1) dfs(r[v]);
}

bool dfs1(int v, bool put = 1, int dep = 1) 
{
	bool any = 0;
	if (l[v] != -1 && dfs1(l[v], put, dep + 1)) any = 1;
	if (any || dep <= k && put && need[in[v]]) {
		if (!any) k -= dep;
		any = 1;
		dup[in[v]] = 1;
	}
	if (!any) put = 0;
	if (r[v] != -1 && dfs1(r[v], put, any ? 1 : 0)) any = 1;
	return any;
}

int main() 
{
	scanf("%d%d%s", &n, &k, s);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", l + i, r + i);
		--l[i];
		--r[i];
	}
	dfs(0);
	for (int i = n - 2; i >= 0; --i) {
		if (res[i] == res[i + 1]) need[i] = need[i + 1];
		else need[i] = res[i] < res[i + 1];
	}
	dfs1(0);
	for (int i = 0; i < n; ++i) for (int j = 0; j <= dup[i]; ++j) printf("%c", res[i]);
	printf("\n");
	return 0;
}