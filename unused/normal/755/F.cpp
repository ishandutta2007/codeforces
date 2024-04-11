#include <bits/stdc++.h>
using namespace std;

int dat[1000005];
int parent[1000005];
int rnk[1000005];
int cnt[1000005];
int cnt2[1000005];
bitset<1000001> bt;

int getparent(int t)
{
	return t == parent[t] ? t : (parent[t] = getparent(parent[t]));
}

void merge(int a, int b)
{
	a = getparent(a);
	b = getparent(b);
	if (rnk[a] < rnk[b]) swap(a, b);
	if (rnk[a] == rnk[b]) rnk[a]++;
	parent[b] = a;
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++)
	{
		int t;
		scanf("%d", &t);
		merge(i, t);
	}

	for (int i = 1; i <= n; i++)
	{
		cnt[getparent(i)]++;
	}

	vector<int> cnts;
	cnts.reserve(n / 2);

	for (int i = 1; i <= n; i++)
	{
		if (cnt[i])
		{
			cnts.push_back(cnt[i]);
			cnt2[cnt[i]]++;
		}
	}
	vector<int> vt;
	for (int i = 1; i <= n; i++)
	{
		if (cnt2[i])
		{
			for (int j = 0; (1 << j) <= cnt2[i]; j++)
			{
				cnt2[i] -= 1 << j;
				vt.push_back((1 << j) * i);
			}
			if (cnt2[i]) vt.push_back(cnt2[i] * i);
		}
	}

	bt[0] = 1;
	for (int t : vt) bt |= bt << t;
	if (bt[k]) printf("%d ", k);
	else printf("%d ", k + 1);

	int ans2 = 0;
	int remain = k;
	for (int t : cnts)
	{
		if (remain == 0) break;
		int sub = min(remain, t / 2);
		remain -= sub;
		ans2 += sub * 2;
	}
	for (int t : cnts)
	{
		if (remain == 0) break;
		if (!(t & 1)) continue;
		remain--;
		ans2++;
	}

	printf("%d", ans2);
}