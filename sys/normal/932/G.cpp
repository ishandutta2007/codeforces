#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005, p = 1e9 + 7;
int n, ct, las, slink[Maxn], d[Maxn];
long long f[Maxn], g[Maxn];
string str, tmp;
struct Node
{
	int fail, len, trans[26];
} node[2 * Maxn];
void insert(int x, int id)
{
	int cur = las;
	while (str[id - node[cur].len - 1] - 'a' != x) cur = node[cur].fail;
	if (!node[cur].trans[x])
	{
		node[cur].trans[x] = ++ct;
		int now = ct, tmp = node[cur].fail;
		node[now].len = node[cur].len + 2;
		while (str[id - node[tmp].len - 1] - 'a' != x) tmp = node[tmp].fail;
		node[now].fail = node[tmp].trans[x];
		if (!node[now].fail || now == node[now].fail) node[now].fail = 1;
		d[now] = node[now].len - node[node[now].fail].len;
		if (d[now] == d[node[now].fail]) 
			slink[now] = slink[node[now].fail];
		else slink[now] = node[now].fail;
	}
	las = node[cur].trans[x];
}
int main()
{
	ct = 2, node[1].fail = 2, node[2].fail = 1, node[2].len = -1, las = 1;
	cin >> tmp;
	n = tmp.size();
	if (n & 1)
	{
		puts("0");
		return 0;
	}
	str += '#';
	for (int i = 0; i < n; i++)
		str += tmp[i], str += tmp[n - i - 1];
	f[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		insert(str[i] - 'a', i);
		for (int u = las; u != 1; u = slink[u])
		{
			g[u] = f[i - d[u] - node[slink[u]].len];
			if (d[u] == d[node[u].fail]) (g[u] += g[node[u].fail]) %= p;
			if (i % 2 == 0) (f[i] += g[u]) %= p;
		}
	}
	printf("%lld", f[n]);
	return 0;
}