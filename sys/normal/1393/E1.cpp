#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 242005, p = 1e9 + 7;
int n, ct, las, cnt, dfn_cnt, lg[Maxn], start[Maxn], dep[Maxn], head[Maxn], f[Maxn], sum[Maxn], mini[4 * Maxn][21];
string S, str[Maxn];
vector <int> ord[Maxn], pos[Maxn];
struct Node
{
	map <int, int> trans;
	int link, len;
} node[Maxn];
void insert(int x)
{
	int cur = ++ct, tmp = las;
	las = cur;
	node[cur].len = node[tmp].len + 1;
	for (; tmp && !node[tmp].trans[x]; tmp = node[tmp].link)
		node[tmp].trans[x] = cur;
	if (!tmp) node[cur].link = 1;
	else
	{
		int q = node[tmp].trans[x];
		if (node[tmp].len + 1 == node[q].len)
			node[cur].link = q;
		else
		{
			int clone = ++ct;
			node[clone] = node[q];
			node[clone].len = node[tmp].len + 1;
			for (; tmp && node[tmp].trans[x] == q; tmp = node[tmp].link)
				node[tmp].trans[x] = clone;
			node[q].link = node[cur].link = clone;
		}
	}
}
struct edg
{
	int nxt, to;
} edge[Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void dfs(int u)
{
	mini[start[u] = ++dfn_cnt][0] = u;
	for (int i = head[u]; i; i = edge[i].nxt)
		dep[edge[i].to] = dep[u] + 1, dfs(edge[i].to), mini[++dfn_cnt][0] = u;
}
void init(void)
{
	for (int i = 2; i <= ct; i++)
		add(node[i].link, i);
	dfs(1);
	for (int i = 2; i <= dfn_cnt; i++)
		lg[i] = lg[i >> 1] + 1;
	for (int j = 1; (1 << j) <= dfn_cnt; j++)
		for (int i = 1; i <= dfn_cnt; i++)
			mini[i][j] = min(mini[i][j - 1], mini[i + (1 << (j - 1))][j - 1], [](int a, int b){return dep[a] < dep[b];});
}
int get_mini(int x, int y)
{
	if (x > y) swap(x, y);
	int Range = lg[y - x + 1];
	return min(mini[x][Range], mini[y - (1 << Range) + 1][Range], [](int a, int b){return dep[a] < dep[b];});
}
int lcp(int x, int y)
{
	return node[get_mini(start[x], start[y])].len;
}
void work(string s, vector <int> & V)
{
	int tmp_ct = 0;
	vector <int> equ, front, back;
	for (int i = 0; i < (int) s.size() - 1; i++)
	{
		if (s[i] == s[i + 1]) equ.push_back(i);
		else if (s[i] < s[i + 1])
		{
			for (auto now : equ) back.push_back(now);
			equ.clear();
			back.push_back(i);
		}
		else
		{
			for (auto now : equ) front.push_back(now);
			equ.clear();
			front.push_back(i);
		}
	}
	for (auto now : front) V[++tmp_ct] = now;
	V[++tmp_ct] = s.size() - 1;
	reverse(back.begin(), back.end());
	for (auto now : back) V[++tmp_ct] = now;
}
bool leq(pair <int, int> x, pair <int, int> y)
{
	int p1 = min(x.second, y.second), p2 = max(x.second, y.second);
	int l = lcp(pos[x.first][0], pos[y.first][0]);
	if (l < p1) return str[x.first][l] < str[y.first][l];
	if (p1 != p2)
	{
		int sx = p1 + (x.second == p1), sy = p1 + (y.second == p1);
		if (sx == (int) str[x.first].size()) return true;
		if (sy == (int) str[y.first].size()) return false;
		l = lcp(pos[x.first][sx], pos[y.first][sy]);
		if (l < p2 - p1)
		{
			if (sx + l == (int) str[x.first].size()) return true;
			if (sy + l == (int) str[y.first].size()) return false;
			return str[x.first][sx + l] < str[y.first][sy + l];
		}
	}
	if (p2 + 1 == (int) min(str[x.first].size(), str[y.first].size()))
		return p2 + 1 == (int) str[x.first].size() || str[x.first][p2 + 1] == '`';
	l = min((int) min(str[x.first].size(), str[y.first].size()) - 1 - p2, lcp(pos[x.first][p2 + 1], pos[y.first][p2 + 1]));
	if (p2 + 1 + l == (int) min(str[x.first].size(), str[y.first].size()))
		return p2 + 1 + l == (int) str[x.first].size();
	return str[x.first][p2 + 1 + l] < str[y.first][p2 + 1 + l];
}
int main()
{
	dep[0] = 0x3f3f3f3f;
	ct = las = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		cin >> str[i];
		str[i] += 'a' - 1;
		ord[i].resize(str[i].size() + 1);
		pos[i].resize(str[i].size());
		work(str[i], ord[i]);
		S += str[i];
	}
	for (int i = S.size() - 1; i >= 0; i--)
		insert(S[i] - 'a' + 1); 
	init();
	for (int i = 1; i <= n; i++)
	{
		int now = 1;
		for (int j = str[i].size() - 1; j >= 0; j--)
			now = node[now].trans[str[i][j] - 'a' + 1], pos[i][j] = now;
	}
	for (int i = 1; i <= (int) str[1].size(); i++)
		sum[i] = i;
	for (int i = 2; i <= n; i++)
	{
		int pnt = 0;
		for (int j = 1; j <= (int) str[i].size(); j++)
		{
			while (pnt != (int) str[i - 1].size() && leq(make_pair(i - 1, ord[i - 1][pnt + 1]), make_pair(i, ord[i][j])))
				pnt++;
			f[j] = pnt >= 0 ? sum[pnt] : 0;
		}
		for (int j = 1; j <= (int) str[i].size(); j++)
			sum[j] = (sum[j - 1] + f[j]) % p;
	}
	printf("%d", sum[str[n].size()]);
	return 0;
}