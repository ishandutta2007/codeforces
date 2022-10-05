#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, m, ans, per, len_s, len_t, bel[Maxn], buc[Maxn], ord[Maxn], fail[Maxn];
char t[Maxn], str[Maxn], s[Maxn];
struct Node
{
	int trans[26], len, cnt, link;
};
struct SAM
{
	vector <Node> node;
	int las, ct, len;
	void clear(int _len)
	{
		len = _len;
		node.resize(len * 2 + 2);
		for (int i = 0; i < len * 2 + 2; i++)
		{
			memset(node[i].trans, 0, sizeof(node[i].trans));
			node[i].link = node[i].len = node[i].cnt = 0;
		}
		las = ct = 1;
	}
	void insert(int x)
	{
		int cur = ++ct, tmp = las;
		las = cur;
		node[cur].len = node[tmp].len + 1;
		node[cur].cnt = 1;
		for (; tmp && !node[tmp].trans[x]; tmp = node[tmp].link)
			node[tmp].trans[x] = cur;
		if (!tmp)
			node[cur].link = 1;
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
				node[clone].cnt = 0;
				for (; tmp && node[tmp].trans[x] == q; tmp = node[tmp].link)
					node[tmp].trans[x] = clone;
				node[cur].link = node[q].link = clone;
			}
		}
	}
	void work(void)
	{
		for (int i = 1; i <= len; i++)
			buc[i] = 0;
		for (int i = 1; i <= ct; i++)
			buc[node[i].len]++;
		for (int i = 1; i <= len; i++)
			buc[i] += buc[i - 1];
		for (int i = ct; i >= 1; i--)
			ord[buc[node[i].len]--] = i;
		for (int i = ct; i >= 2; i--)
			node[node[ord[i]].link].cnt += node[ord[i]].cnt;
	}
	int ask()
	{
		int now = 1;
		for (int i = 1; i <= len_t; i++)
			now = node[now].trans[t[i] - 'a'];
		return node[now].cnt;
	}
} All, S[1005];
void rebuild(int x)
{
	int lt = (x - 1) * per + 1, rt = min(x * per, n);
	if (lt > rt) return ;
	S[x].clear(rt - lt + 1);
	for (int i = lt; i <= rt; i++)
		S[x].insert(str[i] - 'a');
	S[x].work();
}
int work1(int lt, int rt)
{
	All.clear(rt - lt + 1);
	for (int i = lt; i <= rt; i++)
		All.insert(str[i] - 'a');
	All.work();
	return All.ask();
}
int kmp(void)
{
	int result = 0, now = 0;
	for (int i = 1; i <= len_s; i++)
	{
		while (now && s[i] != t[now + 1]) now = fail[now];
		if (s[i] == t[now + 1]) now++;
		if (now == len_t) result++;
	}
	return result;
}
int work2(int lt, int rt)
{
	int result = 0;
	SAM tmp;
	len_s = 0;
	for (int i = lt; i <= bel[lt] * per; i++)
		s[++len_s] = str[i];
	result += kmp();
	len_s = 0;
	for (int i = (bel[rt] - 1) * per + 1; i <= rt; i++)
		s[++len_s] = str[i];
	result += kmp();
	for (int i = bel[lt] + 1; i <= bel[rt] - 1; i++)
		result += S[i].ask();
	for (int i = bel[lt]; i < bel[rt]; i++)
	{
		len_s = 0;
		int l = max(lt, i * per - len_t + 2), r = min(rt, i * per + len_t - 1);
		for (int j = l; j <= r; j++)
			s[++len_s] = str[j];
		result += kmp();
	}
	return result;
}
int main()
{
	scanf("%s", str + 1);
	n = strlen(str + 1);
	int bloc = sqrt(n);
	per = (n + bloc - 1) / bloc;
	for (int i = 1; i <= n; i++)
		bel[i] = (i - 1) / per + 1;
	for (int i = 1; i <= bloc; i++)
		rebuild(i);
	scanf("%d", &m);
	while (m--)
	{
		int opt;
		scanf("%d", &opt);
		if (opt == 1)
		{
			int x;
			scanf("%d", &x);
			char ch = getchar();
			while (!isalpha(ch)) ch = getchar();
			str[x] = ch;
			rebuild(bel[x]);
		}
		else
		{
			int l, r;
			scanf("%d%d%s", &l, &r, t + 1);
			len_t = strlen(t + 1);
			for (int i = 2; i <= len_t; i++)
			{
				int tmp = fail[i - 1];
				while (tmp && t[i] != t[tmp + 1]) tmp = fail[tmp];
				fail[i] = (t[i] == t[tmp + 1]) ? tmp + 1 : 0;
			}
			if (len_t > per || bel[l] == bel[r])
			{
				len_s = 0;
				for (int i = l; i <= r; i++)
					s[++len_s] = str[i];
				printf("%d\n", kmp());
			}
			else printf("%d\n", work2(l, r));
		}
	}
	return 0;
}