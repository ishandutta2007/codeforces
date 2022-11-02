#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 200005
#define lc (q << 1)
#define rc (q << 1 | 1)
#define ld long double
const ld eps = 1e-10;
int n, m, ans[N];
ld A[N];
pair<ld, int>S[N];
vector<int>V[N << 2];
ld Cross(int x, int y, int z){return (y - x) * (A[z] - A[x]) - (z - x) * (A[y] - A[x]);}
void Build(int q, int l, int r)
{
	if (l == r)
	{
		V[q].push_back(l);
		return;
	}
	int mid = (l + r) >> 1;
	Build(lc, l, mid);
	Build(rc, mid + 1, r);
	V[q] = V[lc];
	for (int i = 0; i < (int)V[rc].size(); i++)
	{
		while (V[q].size() > 1 && Cross(V[q][V[q].size() - 2], V[q][V[q].size() - 1], V[rc][i]) <= 0)
			V[q].pop_back();
		V[q].push_back(V[rc][i]);
	}
}
int Getmin(int q, int l, int r, int L, int R, int k)
{
	if (L <= l && R >= r)
	{
		int x = V[q][0];
		int s = 1, t = V[q].size() - 1;
		while (s <= t)
		{
			int mid = (s + t) >> 1;
			int u = V[q][mid - 1], v = V[q][mid];
			if ((A[u] - A[k]) * (x - k) < (A[x] - A[k]) * (u - k))x = u;
			if ((A[v] - A[k]) * (x - k) < (A[x] - A[k]) * (v - k))x = v;
			if ((A[u] - A[k]) * (v - k) < (A[v] - A[k]) * (u - k))
				t = mid - 1;
			else
				s = mid + 1;
			//p - 1q
		}
		return x;
	}
	int mid = (l + r) >> 1;
	if (R <= mid)
		return Getmin(lc, l, mid, L, R, k);
	if (L > mid)
		return Getmin(rc, mid + 1, r, L, R, k);
	int a = Getmin(lc, l, mid, L, R, k), b = Getmin(rc, mid + 1, r, L, R, k);
	if ((A[a] - A[k]) * (b - k) < (A[b] - A[k]) * (a - k))
		return a;
	return b;
}
void Solve(int l, int r, int d)
{
	if (l == r)
		return;
	int x = Getmin(1, 1, n, l + 1, r, l);
	S[x] = make_pair((A[x] - A[l]) / (x - l) - eps, r - l - 1 + d);
	Solve(l, x - 1, 1), Solve(x, r, d);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		double x;
		scanf("%lf", &x);
		A[i] = A[i - 1] + x;
	}
	Build(1, 1, n);
	Solve(0, n, 0);
	sort(S + 1, S + n + 1);
	for (int i = n; i >= 1; i--)
	{
		ans[i] = S[i].second;
		ans[i] = max(ans[i], ans[i + 1]);
	}
	for (int i = 1; i <= m; i++)
	{
		ld k;
		double x;
		scanf("%lf", &x);
		k = x;
		int p = upper_bound(S + 1, S + n + 1, make_pair(k, 0)) - S;
		printf("%d%c", ans[p], i == m ? 10 : 32);
	}
}