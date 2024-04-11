#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;
int n, ans, len[6], a[Maxn], b[Maxn], pos[Maxn];
vector <int> Ve[Maxn];
void work(int ct)
{
	ans++;
	int rea[6], real_ct = 0;
	for (int i = 1; i <= ct; i++)
		if (len[i]) rea[++real_ct] = len[i];
	Ve[ans].push_back(real_ct);
	for (int i = 1; i <= real_ct; i++)
		Ve[ans].push_back(rea[i]);
	int now = 1, bac = n;
	for (int i = 1; i <= real_ct; i++)
	{
		for (int j = now; j <= now + rea[i] - 1; j++)
			b[bac + j - now - rea[i] + 1] = a[j];
		now += rea[i], bac -= rea[i];
	}
	for (int i = 1; i <= n; i++)
		a[i] = b[i], pos[a[i]] = i;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), pos[a[i]] = i;
	bool tag = false;
	for (int i = 2; i <= n; i++)
	{
		if (pos[i] > pos[1])
		{
			if (tag)
				len[1] = pos[1] - 2, len[2] = 1, len[3] = i - 2, len[4] = pos[i] - pos[1] - i + 3, len[5] = n - pos[i], work(5);
			else len[1] = pos[1] - 1, len[2] = i - 1, len[3] = pos[i] - pos[1] - i + 2, len[4] = n - pos[i], work(4);
			tag = true;
		}
		else
		{
			if (tag)
				len[1] = pos[i] - 1, len[2] = pos[1] - 1 - pos[i], len[3] = 1, len[4] = i - 2, len[5] = n - pos[1] - i + 3, work(5);
			else len[1] = pos[i] - 1, len[2] = pos[1] - pos[i], len[3] = i - 1, len[4] = n - pos[1] - i + 2, work(4);
			tag = false;
		}
	}
	if (tag)
		len[1] = 1, len[2] = n - 1, work(2);
	printf("%d\n", ans);
	for (int i = 1; i <= ans; i++)
	{
		for (vector <int> :: iterator it = Ve[i].begin(); it != Ve[i].end(); it++)
			printf("%d ", *it);
		puts("");
	}
	return 0;
}