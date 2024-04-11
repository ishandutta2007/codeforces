#include <bits/stdc++.h>
using namespace std;

const int Maxn = 305, p = 10007;
int n, ans, node_ct, A[Maxn], B[Maxn], goal[Maxn], f[Maxn][Maxn][Maxn];
string str;
struct Matrix
{
	int val[Maxn][Maxn];
	Matrix()
	{
		memset(val, 0, sizeof(val));
	}
	Matrix operator * (const Matrix &A) const
	{
		Matrix ans;
		for (int i = 1; i <= node_ct; i++)
			for (int j = i; j <= node_ct; j++)
				for (int k = j; k <= node_ct; k++)
					(ans.val[i][k] += val[i][j] * A.val[j][k]) %= p;
		return ans;
	}
} G;
Matrix fast_pow(Matrix x, long long y)
{
	Matrix ans, now = x;
	for (int i = 1; i <= node_ct; i++) ans.val[i][i] = 1;
	while (y)
	{
		if (y & 1) ans = ans * now;
		now = now * now;
		y >>= 1;
	}
	return ans;
}
void get_trans(bool type = false)
{
	int siz = str.size();
	memset(goal, 0, sizeof(goal));
	memset(f, 0, sizeof(f));
	node_ct = 0;
	f[0][siz - 1][0] = 1;
	for (int Gap = siz - 1; Gap >= 0; Gap--)
	for (int i = 0; i + Gap < siz; i++)
		for (int j = 0; j < siz; j++)
			if (str[i] == str[i + Gap])
			{
				if (Gap <= 1) (goal[j] += f[i][i + Gap][j]) %= p;
				else (f[i + 1][i + Gap - 1][j] += f[i][i + Gap][j]) %= p;
			}
			else
			{
				if (!Gap) (goal[j + 1] += f[i][i + Gap][j]) %= p;
				else
				{
					(f[i + 1][i + Gap][j + 1] += f[i][i + Gap][j]) %= p;
					(f[i][i + Gap - 1][j + 1] += f[i][i + Gap][j]) %= p;
				}
			}
	for (int i = 0; i < siz; i++)
	{
		A[i] = ++node_ct;
		if (i) G.val[A[i]][A[i]] = 24;
	}
	for (int i = (siz + 1) / 2; i >= 0; i--)
	{
		B[i] = ++node_ct;
		if (i) G.val[B[i]][B[i]] = 25;
		else G.val[B[i]][B[i]] = 26;
	}
	for (int i = 0; i < siz - 1; i++)
		G.val[A[i]][A[i + 1]] = 1;
	for (int i = (siz + 1) / 2; i > 0; i--)
		G.val[B[i]][B[i - 1]] = 1;
	for (int i = 0; i < siz; i++)
	{
		if (!((siz - i) & 1) && type) G.val[A[i]][B[(siz - i + 1) / 2]] = 0;
		else G.val[A[i]][B[(siz - i + 1) / 2]] = goal[i];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> str >> n;
	get_trans();
	ans = fast_pow(G, (n + str.size()) / 2 + 1).val[1][B[0]];
	if ((n + str.size()) & 1)
	{
		get_trans(true);
		(ans = ans * 26 + fast_pow(G, (n + str.size()) / 2 + 1).val[1][B[1]]) %= p;
	}
	cout << ans;
	return 0;
}