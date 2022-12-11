#include <bits/stdc++.h>
using namespace std;

int parent[10005];
int getp(int t)
{
	return t != parent[t] ? parent[t] = getp(parent[t]) : t;
}
bool merge(int a, int b)
{
	int pa = getp(a);
	int pb = getp(b);
	if (pa == pb) return false;
	parent[pa] = pb;
	return true;
}

int main()
{
	int n;
	scanf("%d", &n);
	int ans = n;
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 1; i <= n; i++)
	{
		int b;
		scanf("%d", &b);
		ans -= merge(i, b);
	}
	printf("%d", ans);
}