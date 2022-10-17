#include <bits/stdc++.h>
using namespace std;
int n, m, l, z;
int a[200020];
queue<int> q;
int main()
{
	scanf("%d%d%d", &n, &m, &l);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		while (q.size() && a[i] - q.front() >= m)
		{
			q.pop();
		}
		if (q.size() == l - 1)
		{
			z++;
		}
		else
		{
			q.push(a[i]);
		}
	}
	printf("%d\n", z);
	return 0;
}