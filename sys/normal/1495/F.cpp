#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, q, top, h[Maxn], a[Maxn], b[Maxn], sta[Maxn];
long long ans[Maxn], sum[Maxn];
vector <int> Ve[Maxn];
set <int> Se;
int lowbit(int x)
{
	return x & -x;
}
void add(int x, long long y)
{
	x = n + 1 - x;
	for (int i = x; i <= n; i += lowbit(i))
		sum[i] += y;
}
long long ask(int x)
{
	long long result = 0;
	x = n + 1 - x;
	for (int i = x; i; i -= lowbit(i))
		result += sum[i];
	return result;
}
struct quest
{
	int pos, id, val;
};
vector <quest> Q[Maxn];
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &h[i]);
	h[n + 1] = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	Se.insert(1), Se.insert(n + 1);
	Q[n + 1].push_back((quest){1, 1, 1});
	for (int i = 1; i <= q; i++)
	{
		int x;
		scanf("%d", &x);
		if (x == 1) continue;
		if (Se.find(x) == Se.end())
		{
			set <int> :: iterator it = Se.lower_bound(x);
			int s, t = *it;
			it--, s = *it;
			Q[t].push_back((quest){s, i, -1});
			Q[x].push_back((quest){s, i, 1});
			Q[t].push_back((quest){x, i, 1});
			Se.insert(x);
		}
		else
		{
			Se.erase(x);
			set <int> :: iterator it = Se.lower_bound(x);
			int s, t = *it;
			it--, s = *it;
			Q[t].push_back((quest){s, i, 1});
			Q[x].push_back((quest){s, i, -1});
			Q[t].push_back((quest){x, i, -1});
		}
	}
	for (int i = n + 1; i >= 1; i--)
	{
		while (top && h[sta[top]] <= h[i]) top--;
		if (top) Ve[sta[top]].push_back(i);
		sta[++top] = i;
	}
	for (int i = 2; i <= n + 1; i++)
	{
		add(i - 1, a[i - 1]);
		for (auto now : Ve[i])
		{
			long long d = ask(now);
			add(now, min(0LL, b[now] - d));
		}
		for (auto now : Q[i])
			ans[now.id] += now.val * ask(now.pos);
	}
	for (int i = 1; i <= q; i++)
	{
		ans[i] += ans[i - 1];
		printf("%lld\n", ans[i]);
	}
	return 0;
}