#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;
int d, p, id[Maxn], tmp[Maxn];
long long A[Maxn][Maxn], C[Maxn][Maxn];
long long fast_pow(long long x, long long y)
{
	long long ans = 1, now = x;
	while (y)
	{
		if (y & 1) ans = ans * now % p;
		now = now * now % p;
		y >>= 1;
	}
	return ans;
}
void gauss(void)
{
	for (int i = 0; i <= d; i++)
	{
		for (int j = i; j <= d; j++)
			if (A[j][i])
			{
				swap(A[i], A[j]);
				break;
			}
		long long inv = fast_pow(A[i][i], p - 2);
		for (int j = d + 1; j >= i; j--)
			(A[i][j] *= inv) %= p;
		for (int j = 0; j <= d; j++)
			if (i != j)
				for (int k = d + 1; k >= i; k--)
					(A[j][k] += p - A[j][i] * A[i][k] % p) %= p;
	}
}
void init(void)
{
	C[0][0] = 1;
	for (int i = 1; i <= d; i++)
	{
		C[i][0] = 1;
		for (int j = 1; j <= d; j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p;
	}
	for (int i = 0; i <= d; i++)
		for (int j = 0; j <= d; j++)
			A[d - j][i] = C[d][j] * fast_pow(i, j) % p;
	for (int i = 0; i <= d; i++)
		A[i][d + 1] = i == 2;
	gauss();
}
void fast_pow(int pos, int y, int res)
{
	printf("^ 3 %d\n", res);
	while (y)
	{
		if (y & 1) printf("+ %d %d %d\n", res, pos, res);
		printf("+ %d %d %d\n", pos, pos, pos);
		y >>= 1;
	}
}
void square(int pos, int res)
{
	printf("^ 3 %d\n", res);
	for (int i = 0; i <= d; i++)
	{
		printf("+ %d %d %d\n", pos, id[i], tmp[i]);
		printf("^ %d %d\n", tmp[i], tmp[i + d + 1]);
		fast_pow(tmp[i + d + 1], A[i][d + 1], tmp[i + 2 * d + 2]);
		printf("+ %d %d %d\n", res, tmp[i + 2 * d + 2], res);
	}
}
void dec(int x, int y)
{
	printf("+ %d 3 %d\n", y, tmp[0]);
	fast_pow(tmp[0], p - 1, tmp[1]);
	printf("+ %d %d %d\n", x, tmp[1], x);
}
int main()
{
	scanf("%d%d", &d, &p);
	init();
	id[0] = 3, fast_pow(5000, p - 1, 3);
	for (int i = 1; i <= d; i++)
		id[i] = i + 3, printf("+ %d %d %d\n", id[i - 1], id[i], id[i]);
	for (int i = 200; i <= 300; i++)
		tmp[i - 200] = i;
	square(1, 1000), square(2, 1001);
	puts("+ 1 2 1002");
	square(1002, 1003);
	dec(1003, 1000);
	dec(1003, 1001);
	fast_pow(1003, (p + 1) / 2, 1004);
	puts("f 1004");
	return 0;
}