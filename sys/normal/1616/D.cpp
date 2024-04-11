#include <bits/stdc++.h>
using namespace std;

const int Maxn = 50005;
int T, n, a[Maxn], maxi[Maxn], f[Maxn];
long long shift;
priority_queue <pair <long long, int>, vector <pair <long long, int> >, greater <pair <long long, int> > > Pr;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		int x, ans = 0;
		shift = 0;
		while (!Pr.empty()) Pr.pop();
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		scanf("%d", &x);
		for (int i = 1; i <= n; i++) a[i] -= x;
		int pnt = 1;
		Pr.push(make_pair(a[1], 1));
		for (int i = 1; i <= n; i++)
		{
			while (!Pr.empty() && Pr.top().second < i) Pr.pop();
			while (pnt == i - 1 || (pnt < n && Pr.top().first + shift + a[pnt + 1] >= 0))
			{
				pnt++;
				Pr.push(make_pair(-shift, pnt));
				shift += a[pnt];
			}
			maxi[i] = pnt;
		}
		memset(f, 0, sizeof(int[n + 3]));
		for (int i = 1; i <= n; i++)
		{
			f[i] = max(f[i], f[i - 1]);
			f[maxi[i] + 2] = max(f[maxi[i] + 2], f[i] + maxi[i] - i + 1);
		}
		for (int i = 1; i <= n + 2; i++) ans = max(ans, f[i]);
		printf("%d\n", ans);
	}
	return 0;
}