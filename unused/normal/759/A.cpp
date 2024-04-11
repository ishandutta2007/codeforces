#include <bits/stdc++.h>
using namespace std;

int d1[200005], d2[200005];
int parent[200005];
int getparent(int t)
{
	return t == parent[t] ? t : parent[t] = getparent(parent[t]);
}
void merge(int a, int b)
{
	a = getparent(a);
	b = getparent(b);
	parent[a] = b;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) parent[i] = i;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &d1[i]);
		d1[i]--;
		merge(i, d1[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &d2[i]);
	}

	int c2 = 0;
	for (int i = 0; i < n; i++) c2 += d2[i];
	int ans = !(c2 & 1);
	int c1 = 0;
	for (int i = 0; i < n; i++)
	{
		if (getparent(i) == i) c1++;
	}

	if (c1 == 1) printf("%d", ans);
	else printf("%d", ans + c1);
}