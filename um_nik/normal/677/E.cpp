#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MOD = (ll)1e9 + 7;

const int DX[] = {0, 1, 1, 1};
const int DY[] = {1, 0, -1, 1};

struct Num
{
	int a[4];

	Num()
	{
		for (int i = 0; i < 4; i++)
			a[i] = 0;
	}
	Num(int x)
	{
		if (x < 0 || x > 3) throw;
		for (int i = 0; i < 4; i++)
			a[i] = 0;
		a[x]++;
	}

	Num operator + (const Num &A) const
	{
		Num R = Num();
		for (int i = 0; i < 4; i++)
			R.a[i] = a[i] + A.a[i];
		return R;
	}
	Num operator - (const Num &A) const
	{
		Num R = Num();
		for (int i = 0; i < 4; i++)
			R.a[i] = a[i] - A.a[i];
		return R;
	}

	bool operator < (const Num &A) const
	{
		if (A.a[0] > 0) return false;
		if (a[0] > 0)
			return true;
		return a[2] * log(2) + a[3] * log(3) < A.a[2] * log(2) + A.a[3] * log(3);
	}

	void print()
	{
		if (a[0] > 0)
		{
			printf("0\n");
			return;
		}
		ll x = 1;
		for (int y = 2; y < 4; y++)
			for (int i = 0; i < a[y]; i++)
				x = (x * y) % MOD;
		printf("%lld\n", x);
	}
};

const int N = 1010;
int n;
int a[N][N];
char s[N];
Num b[4][N][N];
Num ans = Num(0);

bool checkCell(int x, int y)
{
	return min(x, y) >= 0 && max(x, y) < n;
}

void precalc()
{
	for (int d = 0; d < 4; d++)
		for (int x = 0; x < n; x++)
			for (int y = 0; y < n; y++)
			{
				int xx = x - DX[d], yy = y - DY[d];
				b[d][x][y] = (checkCell(xx, yy) ? b[d][xx][yy] : Num()) + Num(a[x][y]);
			}
	return;
}

Num getDir(int x, int y, int dir, int L)
{
	int xx = x + DX[dir] * L, yy = y + DY[dir] * L;
	int xxx = x - DX[dir] * (L + 1), yyy = y - DY[dir] * (L + 1);
	return b[dir][xx][yy] - (checkCell(xxx, yyy) ? b[dir][xxx][yyy] : Num());
}

Num get1(int x, int y, int d)
{
	Num res = Num() - Num(a[x][y]);
	res = res + getDir(x, y, 0, d);
	res = res + getDir(x, y, 1, d);
	return res;
}
Num get2(int x, int y, int d)
{
	Num res = Num() - Num(a[x][y]);
	res = res + getDir(x, y, 2, d);
	res = res + getDir(x, y, 3, d);
	return res;
}

void solve(int x, int y)
{
	int B = min(1 + min(x, y), n - max(x, y));
	int l = 0, r = B;
	while(r - l > 1)
	{
		int m = (l + r) / 2;
		Num R = get1(x, y, m);
		if (R.a[0] > 0)
			r = m;
		else
			l = m;
	}
	Num res = get1(x, y, l);
	if (ans < res)
		ans = res;
	l = 0, r = B;
	while(r - l > 1)
	{
		int m = (l + r) / 2;
		Num R = get2(x, y, m);
		if (R.a[0] > 0)
			r = m;
		else
			l = m;
	}
	res = get2(x, y, l);
	if (ans < res)
		ans = res;
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf(" %s ", s);
		for (int j = 0; j < n; j++)
			a[i][j] = (int)(s[j] - '0');
	}
	precalc();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] != 0)
				solve(i, j);
	ans.print();

	return 0;
}