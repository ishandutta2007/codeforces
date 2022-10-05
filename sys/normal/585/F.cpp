#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 250005, p = 1e9 + 7;
int node_ct;
bool endpos[Maxn];
long long f[Maxn][2], tmp[Maxn][2];
string s, t, S, tmps;
struct Node
{
	int son[10], fail;
}node[Maxn];
void init(string str, int id)
{
	int now = 1, siz = str.size();
	for (int i = 0; i < siz; i++)
	{
		if (!node[now].son[str[i] - '0']) node[now].son[str[i] - '0'] = ++node_ct;
		now = node[now].son[str[i] - '0'];
	}
	endpos[now] = true;
}
queue <int> Qu;
void get_fail(void)
{
	for (int i = 0; i <= 9; i++)
		if (node[1].son[i]) node[node[1].son[i]].fail = 1, Qu.push(node[1].son[i]);
		else node[1].son[i] = 1;
	while (!Qu.empty())
	{
		int u = Qu.front();
		Qu.pop();
		for (int i = 0; i <= 9; i++)
		{
			if (node[u].son[i]) node[node[u].son[i]].fail = node[node[u].fail].son[i], Qu.push(node[u].son[i]);
			else node[u].son[i] = node[node[u].fail].son[i];
		}
	}
}
long long work(string str)
{
	long long tot = 0;
	memset(f, 0, sizeof(f));
	f[1][1] = 1;
	int len = str.size();
	for (int i = 0; i < len; i++)
	{
		memset(tmp, 0, sizeof(tmp));
		for (int j = 1; j <= node_ct; j++)
			if (!endpos[j])
				for (int k = 0; k <= 9; k++)
					if (!endpos[node[j].son[k]])
						(tmp[node[j].son[k]][0] += f[j][0]) %= p;
		for (int j = 1; j <= node_ct; j++)
			if (!endpos[j])
			{
				for (int k = 0; k < str[i] - '0'; k++)
					if (!endpos[node[j].son[k]])
						(tmp[node[j].son[k]][0] += f[j][1]) %= p;
				if (!endpos[node[j].son[str[i] - '0']]) (tmp[node[j].son[str[i] - '0']][1] += f[j][1]) %= p;
			}
		memcpy(f, tmp, sizeof(f));
	}
	for (int i = 1; i <= node_ct; i++)
		(tot += f[i][0] + f[i][1]) %= p;
	long long Tmp = 0;
	for (int i = 0; i < len; i++)
		(Tmp *= 10) %= p, (Tmp += str[i] - '0') %= p;
	return (Tmp - tot + p) % p;
}
int main()
{
	node_ct = 1;
	cin >> S >> s >> t;
	int siz = s.size(), Siz = S.size();
	for (int i = 0; i < Siz - siz / 2 + 1; i++)
	{
		tmps = "";
		for (int j = i; j < i + siz / 2; j++)
			tmps += S[j];
		init(tmps, i);
	}
	tmps = "";
	get_fail();
	int len = s.size(), pos;
	for (int i = len - 1; i >= 0; i--)
		if (s[i] != '0')
		{
			pos = i;
			break;
		}
	for (int i = 0; i < pos; i++)
		tmps += s[i];
	tmps += s[pos] - 1;
	for (int i = pos + 1; i < len; i++)
		tmps += '9';
	printf("%lld\n", (work(t) - work(tmps) + p) % p);
	return 0;
}