#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
int q, node_ct, rt[2][31];
vector <string> V[2][31];
bool used[2][31];
struct Node
{
	int fail, trans[26];
	long long cnt;
} node[18 * Maxn];
queue <int> Qu;
void build(int root, vector <string> & Ve)
{
	for (auto s : Ve)
	{
		int now = root;
		for (int i = 0; i < (int) s.size(); i++)
		{
			if (!node[now].trans[s[i] - 'a']) node[now].trans[s[i] - 'a'] = ++node_ct;
			now = node[now].trans[s[i] - 'a'];
		}
		node[now].cnt++;
	}
	for (int i = 0; i < 26; i++)
		if (node[root].trans[i]) node[node[root].trans[i]].fail = root, Qu.push(node[root].trans[i]);
		else node[root].trans[i] = root;
	while (!Qu.empty())
	{
		int u = Qu.front();
		Qu.pop();
		node[u].cnt += node[node[u].fail].cnt;
		for (int i = 0; i < 26; i++)
			if (node[u].trans[i])
				node[node[u].trans[i]].fail = node[node[u].fail].trans[i], Qu.push(node[u].trans[i]);
			else node[u].trans[i] = node[node[u].fail].trans[i];
	}
}
void insert(string x, int type)
{
	vector <string> now;
	now.push_back(x);
	for (int i = 0; i <= 30; i++)
	{
		if (used[type][i])
		{
			for (auto s : V[type][i])
				now.push_back(s);
			used[type][i] = false;
		}
		else
		{
			used[type][i] = true;
			build(rt[type][i] = ++node_ct, now);
			V[type][i] = now;
			break;
		}
	}
}
long long ask(int now, string S)
{
	long long result = 0;
	for (int i = 0; i < (int) S.size(); i++)
	{
		now = node[now].trans[S[i] - 'a'];
		result += node[now].cnt;
	}
	return result;
}
int main()
{
	scanf("%d", &q);
	while (q--)
	{
		int opt;
		string str;
		cin >> opt >> str;
		if (opt <= 2) insert(str, opt - 1);
		else
		{
			long long ans = 0;
			for (int i = 0; i <= 30; i++)
			{
				if (used[0][i]) ans += ask(rt[0][i], str);
				if (used[1][i]) ans -= ask(rt[1][i], str);
			}
			printf("%lld\n", ans);
			fflush(stdout);
		}
	}
	return 0;
}