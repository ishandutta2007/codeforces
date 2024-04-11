#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 500005
#define lc (q << 1)
#define rc (q << 1 | 1)
int n, A[N], f[N];
int pre[N];//
int S[N << 2];
vector<int>V[N];
void Build(int q, int l, int r)
{
	S[q] = 0;
	if (l == r)
		return;
	int mid = (l + r) >> 1;
	Build(lc, l, mid);
	Build(rc, mid + 1, r);
}
int Getval(int q, int l, int r, int L, int R)
{
	if (L <= l && R >= r)
		return S[q];
	int ret = 0, mid = (l + r) >> 1;
	if (L <= mid)
		ret = max(ret, Getval(lc, l, mid, L, R));
	if (R > mid)
		ret = max(ret, Getval(rc, mid + 1, r, L, R));
	return ret;
}
void Update(int q, int l, int r, int k, int v)
{
	S[q] = max(S[q], v);
	if (l == r)
		return;
	int mid = (l + r) >> 1;
	if (k <= mid)
		Update(lc, l, mid, k, v);
	else
		Update(rc, mid + 1, r, k, v);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &A[i]);
			V[i].clear();
			pre[i] = i - 1;
			while (pre[i] && A[pre[i]] <= A[i])
				pre[i] = pre[pre[i]];
			if (pre[i])
				V[pre[i]].push_back(i);
			f[i] = 0;
		}
		int ans = 0;
		Build(1, 1, n);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < (int)V[i].size(); j++)
				f[V[i][j]] = max(f[V[i][j]], Getval(1, 1, n, 1, A[V[i][j]]) + 2);
			f[i] = max(f[i], Getval(1, 1, n, 1, A[i]) + 1);
			ans = max(ans, f[i]);
			Update(1, 1, n, A[i], f[i]);
		}
		printf("%d\n", ans);
	}
}