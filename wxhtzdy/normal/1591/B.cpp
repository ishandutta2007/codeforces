#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
int T, n;
int a[maxn];

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}	
	int x = a[n - 1], ans = 0;
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] > x) {
			x = a[i];
			ans++;
		}
	}
	printf("%d\n", ans);
}

int main()
{
	scanf("%d", &T);
	while (T--) 
	{
		solve();
	}
}