#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 200200;
int n, q;
int k;
int a[N];
int b[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &k, &q);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < k; i++)
		b[i] = -1;
	while(q--)
	{
		int t, id;
		scanf("%d%d", &t, &id);
		id--;
		if (t == 1)
		{
			int p = 0;
			while(p < k && (b[p] != -1 && a[b[p]] > a[id])) p++;
			if (p == k) continue;
			for (int i = k - 1; i > p; i--)
				b[i] = b[i - 1];
			b[p] = id;
		}
		else
		{
			bool ok = false;
			for (int i = 0; i < k; i++)
				ok |= b[i] == id;
			if (ok)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}

	return 0;
}