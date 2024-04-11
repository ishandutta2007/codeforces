#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, q, ct, a[Maxn], root[Maxn], bel[Maxn];
vector <int> Ve[Maxn];
vector <vector <int> > rt[Maxn];
pair <int, int> ans[Maxn * 220];
vector <vector <int> > divide(vector <int> V, int lt, int rt)
{
	vector <int> tmp_V1, tmp_V2;
	vector <vector <int> > result;
	if (!V.size()) return result;
	result.resize(V.size());
	for (int i = 0; i < (int) V.size(); i++)
		result[i].resize(V.size());
	if (V.size() == 1)
	{
		result[0][0] = V[0];
		return result;
	}
	int mid = (lt + rt) >> 1;
	for (int i = 0; i < (int) V.size(); i++)
		if (a[V[i]] <= mid) tmp_V1.push_back(V[i]);
		else tmp_V2.push_back(V[i]);
	vector <vector <int> > L = divide(tmp_V1, lt, mid), R = divide(tmp_V2, mid + 1, rt);
	for (int i = 0; i < (int) V.size(); i++)
		for (int j = i; j < (int) V.size(); j++)
		{
			int a1 = lower_bound(tmp_V1.begin(), tmp_V1.end(), V[i]) - tmp_V1.begin(), b1 = upper_bound(tmp_V1.begin(), tmp_V1.end(), V[j]) - tmp_V1.begin() - 1;
			int a2 = lower_bound(tmp_V2.begin(), tmp_V2.end(), V[i]) - tmp_V2.begin(), b2 = upper_bound(tmp_V2.begin(), tmp_V2.end(), V[j]) - tmp_V2.begin() - 1;
			if (a1 > b1) result[i][j] = R[a2][b2];
			else if (a2 > b2) result[i][j] = L[a1][b1];
			else ans[++ct] = make_pair(L[a1][b1], R[a2][b2]), result[i][j] = ct;
		}
	return result;
}
int main()
{
	scanf("%d%d", &n, &q), ct = n;
	int B = max(1.0, n / sqrt(q)), per = (n + B - 1) / B + 1;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), bel[i] = (i - 1) / per + 1;
	for (int i = 1; i <= n; i++)
		Ve[bel[a[i]]].push_back(i);
	for (int i = 1; i <= B; i++)
		rt[i] = divide(Ve[i], (i - 1) * per + 1, min(n, i * per));
	for (int Cases = 1; Cases <= q; Cases++)
	{
		int l, r, las = 0;
		scanf("%d%d", &l, &r);
		for (int i = 1; i <= B; i++)
		{
			int x = lower_bound(Ve[i].begin(), Ve[i].end(), l) - Ve[i].begin(), y = upper_bound(Ve[i].begin(), Ve[i].end(), r) - Ve[i].begin() - 1;
			if (x > y) continue;
			if (las) ans[++ct] = make_pair(las, rt[i][x][y]), las = ct;
			else las = rt[i][x][y];
		}
		root[Cases] = las;
	}
	printf("%d\n", ct);
	for (int i = n + 1; i <= ct; i++)
		printf("%d %d\n", ans[i].first, ans[i].second);
	for (int i = 1; i <= q; i++)
		printf("%d ", root[i]);
	return 0;
}