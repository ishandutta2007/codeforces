#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, top, sta[Maxn];
long long t, now;
double maxi, las;
struct Matrix
{
	double val[3][3];
	Matrix ()
	{
		memset(val, 0, sizeof(val));
	}
	Matrix operator * (const Matrix &A) const
	{
		Matrix ans;
		for (int i = 0; i <= 2; i++)
			for (int j = 0; j <= 2; j++)
				for (int k = 0; k <= 2; k++)
					ans.val[i][j] += val[i][k] * A.val[k][j];
		return ans;
	}
} res, M[41];
struct game
{
	int a, b;
	double p;
	bool operator < (const game &tmp) const
	{
		if (abs(p - tmp.p) <= 1e-14) return a * p < tmp.a * tmp.p;
		return p < tmp.p;
	}
} G[Maxn];
double slope(int x, int y)
{
	return (G[y].p * G[y].a - G[x].p * G[x].a) / (G[y].p - G[x].p);
}
int main()
{
	scanf("%d%lld", &n, &t);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%lf", &G[i].a, &G[i].b, &G[i].p), maxi = max(maxi, G[i].b * G[i].p);
	sort(G + 1, G + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		while (top > 1 && (G[sta[top]].p * G[sta[top]].a - G[sta[top - 1]].p * G[sta[top - 1]].a) * (G[i].p - G[sta[top]].p) <= (G[i].p * G[i].a - G[sta[top]].p * G[sta[top]].a) * (G[sta[top]].p - G[sta[top - 1]].p)) top--;
		sta[++top] = i;
	}
	res.val[0][2] = 1;
	M[0].val[1][1] = M[0].val[2][1] = M[0].val[2][2] = 1;
	for (int i = 1; i <= top; i++)
	{
		if (i != top && G[sta[i + 1]].p * las + G[sta[i + 1]].p * G[sta[i + 1]].a > G[sta[i]].p * las + G[sta[i]].p * G[sta[i]].a)
			continue;
		M[0].val[0][0] = 1 - G[sta[i]].p, M[0].val[1][0] = G[sta[i]].p * maxi, M[0].val[2][0] = G[sta[i]].p * G[sta[i]].a;
		for (int j = 1; j <= 40; j++)
			M[j] = M[j - 1] * M[j - 1];
		for (int j = 40; j >= 0; j--)
			if (now + (1LL << j) < t)
			{
				Matrix tmp = res * M[j];
				double S = maxi * tmp.val[0][1] - tmp.val[0][0];
				if (i == top || G[sta[i]].p * S + G[sta[i]].p * G[sta[i]].a > G[sta[i + 1]].p * S + G[sta[i + 1]].p * G[sta[i + 1]].a)
					now += 1LL << j, res = tmp;
			}
		res = res * M[0];
		now++;
		las = maxi * res.val[0][1] - res.val[0][0];
		if (now == t) break;
	}
	printf("%.10lf", res.val[0][0]);
	return 0;
}