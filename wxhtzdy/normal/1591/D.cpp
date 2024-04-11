#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 5;
int T, n, k;
int a[maxn], f[2 * maxn], cnt[maxn];

void addF(int x)
{ 	
	for (; x <= 2 * n; x += x & -x)
		f[x]++;
}

int getF(int x) 
{
	int r = 0;
	for (; x > 0; x -= x & -x)
		r += f[x];
	return r;
}

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n; i++)
		f[i] = cnt[i] = 0;
	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	int ans = 0;
	bool ok = 0;
	for (int i = 1; i <= n; i++)
	{
		if (cnt[i] > 1)
		{
			ok = true;
		}
	}
	for (int i = n - 1; i >= 0; i--) 
	{
		ans = (ans + getF(a[i] - 1)) % 2;
		addF(a[i]);
	}
	if (ans == 0 || ok)
		printf("YES\n");
	else 
		printf("NO\n");
}

int main()
{
	scanf("%d", &T);
	while (T--) 
	{
		solve();
	}
}