#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
int n, m, s[Maxn], rk[Maxn], bel[Maxn], ans[Maxn], pos[Maxn];
long long t, c;
int main()
{
	scanf("%d%d%lld", &n, &m, &t);
	for (int i = 0; i < n; i++)
	{
		long long tmp;
		scanf("%d", &s[i]);
		char ch = getchar();
		while (ch != 'L' && ch != 'R') ch = getchar();
		if (ch == 'L') tmp = s[i] - 1 - t;
		else tmp = s[i] - 1 + t;
		(c += tmp / m) %= n;
		if (tmp % m < 0) (c += n - 1) %= n; 
		pos[i] = (tmp % m + m) % m;
		rk[i] = i;
	}
	sort(pos, pos + n);
	sort(rk, rk + n, [](int x, int y){return s[x] < s[y];});
	(c += n) %= n;
	for (int i = c; i < n; i++)
		ans[rk[i - c]] = pos[i] + 1;
	for (int i = 0; i < c; i++)
		ans[rk[i + n - c]] = pos[i] + 1;
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	return 0;
}