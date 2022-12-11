#include <bits/stdc++.h>
using namespace std;

using matrix = array<bitset<500>, 500>;

matrix operator*(const matrix &m1, const matrix &m2)
{
	matrix ret;
	for (int j = 0; j < 500; j++)
	{
		bitset<500> col;
		for (int k = 0; k < 500; k++)
		{
			col[k] = m2[k][j];
		}
		for (int i = 0; i < 500; i++)
		{
			ret[i][j] = (m1[i] & col).any();
		}
	}
	return ret;
}

vector<matrix> m1, m2;

bool any(const matrix &m)
{
	for (int i = 0; i < 500; i++) if (m[i].any()) return true;
	return false;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	m1.resize(1); m2.resize(1);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		--a; --b;
		if (c == 0)
		{
			m1[0][a][b] = true;
		}
		else
		{
			m2[0][a][b] = true;
		}
	}

	for (int i = 1; i <= 59; i++)
	{
		m1.push_back(m1[i - 1] * m2[i - 1]);
		m2.push_back(m2[i - 1] * m1[i - 1]);
	}

	long long ans = 0;
	matrix mm;
	mm[0][0] = true;
	//for (int i = 0; i < 500; i++) mm[i][i] = true;

	int pos = 0;
	for (int flag = 59; flag >= 0; flag--)
	{
		matrix mm2 = mm * (pos ? m2 : m1)[flag];
		if (any(mm2))
		{
			ans += (1ll << flag);
			mm = move(mm2);
			pos ^= 1;
		}
	}

	if (ans > (long long)1e18) printf("-1\n");
	else printf("%lld\n", ans);
}