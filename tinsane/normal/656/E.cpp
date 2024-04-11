#include <iostream>

using namespace std;

const int N = 10;
int n, i, j, k, c, res = 0;
int dists[N][N];

int read_next()
{
	cin >> dists[i][j];
	++j == n ? 1 : read_next();
	return 1;
}

int read()
{
	j = 0;
	read_next();
	++i == n ? 1 : read();
	return 1;
}

int calc_next2()
{
	dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
	++j == n ? 1 : calc_next2();
	return 1;
}

int calc_next1()
{
	j = 0;
	calc_next2();
	++i == n ? 1 : calc_next1();
	return 1;
}

int calc()
{
	i = 0;
	calc_next1();
	++k == n ? 1 : calc();
	return 1;
}

int relax1()
{
	res = max(res, dists[i][j]);
	++j == n ? 1 : relax1();
	return 1;
}

int relax()
{
	j = 0;
	relax1();
	++i == n ? 1 : relax();
	return 1;
}

void solve()
{
	cin >> n;
	i = 0;
	read();

	k = 0;
	calc();

	i = 0;
	relax();

	cout << res;
}

int main()
{
	solve();
	return 0;
}