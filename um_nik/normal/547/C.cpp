#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int K = 500200;
const int N = 200200;
int n;
int q;
ll ans;
int a[N];
vector<int> d[N];
int p[K];
ll c[K];
bool used[N];

void init()
{
	p[1] = 1;
	for (int x = 1; x < K; x++)
		for (int y = 2 * x; y < K; y += x)
			p[y] -= p[x];
	return;
}

int main()
{
	init();
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		int x = a[i];
		for (int j = 1; j * j <= x; j++)
		{
			if (x % j != 0) continue;
			d[i].push_back(j);
			int y = x / j;
			if (y != j)
				d[i].push_back(y);
		}
	}
	ans = 0;
	while(q--)
	{
		int pos;
		scanf("%d", &pos);
		pos--;
		for (int i = 0; i < (int)d[pos].size(); i++)
		{
			int x = d[pos][i];
			ans -= (c[x] * (c[x] - 1) / 2) * p[x];
			if (used[pos])
				c[x]--;
			else
				c[x]++;
			ans += (c[x] * (c[x] - 1) / 2) * p[x];
		}
		used[pos] ^= true;
		printf("%I64d\n", ans);
	}

	return 0;
}