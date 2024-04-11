#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <complex>
#include <algorithm>
using namespace std;
typedef complex<double> cd;

const double PI = 4. * atan(1.);

const int POW = 19;
const int L = 1 << POW;
int n, m, k;
bool ans[L];
char s[L], t[L];
char chrs[] = "ACGT";
cd A[L], B[L], C[L];

cd w[L];
int rev[L];

void read()
{
	scanf("%d%d%d", &n, &m, &k);
	scanf(" %s %s", s, t);
	reverse(t, t + m);
	for (int i = 0; i + m <= n; i++)
		ans[i] = 1;
	return;
}

cd a[POW + 1][L];

void FFT(cd* A)
{
	for (int i = 0; i < L; i++)
		a[0][rev[i]] = A[i];

	for (int lvl = 0; lvl < POW; lvl++)
	{
		int len = 1 << lvl;
		for (int st = 0; st < L; st += len << 1)
		{
			for (int i = 0; i < len; i++)
			{
				cd add = w[i << (POW - lvl - 1)] * a[lvl][st + len + i];
				a[lvl + 1][st + i] = a[lvl][st + i] + add;
				a[lvl + 1][st + len + i] = a[lvl][st + i] - add;
			}
		}
	}

	for (int i = 0; i < L; i++)
		A[i] = a[POW][i];
	return;
}

void doMagic()
{
	FFT(A);
	FFT(B);
	for (int i = 0; i < L; i++)
		C[i] = A[i] * B[i];
	FFT(C);
	reverse(C + 1, C + L);
	return;
}

void solve(char c)
{
	for (int i = 0; i < L; i++)
		A[i] = B[i] = cd(0, 0);
	int lst = -k - 1;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == c)
			lst = i;
		if (i - lst <= k)
			A[i] = cd(1, 0);
	}
	lst = n + k + 1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (s[i] == c)
			lst = i;
		if (lst - i <= k)
			A[i] = cd(1, 0);
	}
	int count = 0;
	for (int i = 0; i < m; i++)
		if (t[i] == c)
		{
			count++;
			B[i] = cd(1, 0);
		}
	doMagic();
	for (int i = 0; i < n; i++)
	{
		int x = (int)(C[i + m - 1].real() / L + 0.4);
		if (x != count)
			ans[i] = 0;
	}
	return;
}

void init()
{
	for (int mask = 1; mask < L; mask++)
	{
		int p = 0;
		while((mask & (1 << p)) == 0)
			p++;
		rev[mask] = rev[mask ^ (1 << p)] ^ (1 << (POW - 1 - p));
	}

	for (int i = 0; i < L; i++)
	{
		double alp = 2 * PI * i / L;
		w[i] = cd(cos(alp), sin(alp));
	}

	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);

	init();

	read();
	for (int i = 0; i < 4; i++)
		solve(chrs[i]);
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += (int)ans[i];
	printf("%d\n", cnt);

	return 0;
}