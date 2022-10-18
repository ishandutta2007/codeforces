#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 1 << 16;

int main()
{
	int n;
	static int deg[MaxN], s[MaxN];
	int q_n = 0;
	static int q[MaxN];

	cin >> n;
	for (int v = 0; v < n; v++)
		scanf("%d %d", &deg[v], &s[v]);

	int m = 0;
	for (int v = 0; v < n; v++)
	{
		m += deg[v];
		if (deg[v] == 1)
			q[q_n++] = v;
	}
	cout << m / 2 << endl;

	for (int i = 0; i < q_n; i++)
	{
		int v = q[i];
		if (deg[v] == 0)
			continue;
		printf("%d %d\n", v, s[v]);
		s[s[v]] ^= v;
		if (--deg[s[v]] == 1)
			q[q_n++] = s[v];
	}

	return 0;
}