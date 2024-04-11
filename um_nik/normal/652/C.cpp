#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;

const int N = 300300;
int b[N];
int c[N];
int bad[N];
ll ans;
int n, m;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		c[x] = i;
		b[i] = n;
	}
	while(m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x = c[x];
		y = c[y];
		if (x > y) swap(x, y);
		b[x] = min(b[x], y);
	}
	int r = 0;
	for (int l = 0; l < n; l++)
	{
		while(r < n && bad[r] == 0)
		{
			bad[b[r]]++;
			r++;
		}
		ans += r - l;
		bad[b[l]]--;
	}
	printf("%lld\n", ans);

	return 0;
}