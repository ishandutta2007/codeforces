#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;
int T, n, ct, ans, a[Maxn], b[Maxn], lpos[Maxn], rpos[Maxn];
vector <int> Ve[Maxn];
priority_queue <int, vector <int>, greater <int> > Pr;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ct = ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			if (!a[i]) b[++ct] = i;
		}
		if (ct <= 1)
		{
			puts("0");
			continue;
		}
		int pos = b[ct / 2];
		for (int i = 1; i <= n; i++)
			rpos[i] = 0, lpos[i] = n + 1, Ve[i].clear();
		for (int i = n; i > pos; i--)
			if (a[i]) lpos[a[i]] = i;
		for (int i = 1; i <= pos; i++)
			if (a[i]) rpos[a[i]] = i;
		for (int i = 1; i <= n; i++)
		{
			lpos[i] -= pos;
			rpos[i] += n - pos;
			Ve[lpos[i]].push_back(rpos[i]);
		}
		while (!Pr.empty()) Pr.pop();
		for (int i = 1; i <= n; i++)
		{
			for (auto now : Ve[i]) Pr.push(now);
			while (!Pr.empty() && Pr.top() < i) Pr.pop();
			if (!a[(i + pos - 1) % n + 1] && !Pr.empty()) ans++, Pr.pop();
		}
		printf("%d\n", min(ans, ct / 2));
	}
	return 0;
}