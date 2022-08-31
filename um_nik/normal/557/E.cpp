#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 5050;
const int A = 2;
int n;
char s[N];
int k;
int r[N][2][2];
int SA[N];
int tSA[N];
int tt[A];
int a[N][N];
char ans[N];

bool isP(int L, int R)
{
	int len = R - L;
	int c = (L + R) / 2;
	if (len & 1)
	{
		len--;
		len /= 2;
		return len <= r[c][0][len & 1];
	}
	else
	{
		len /= 2;
		return len <= r[c][1][len & 1];
	}
	throw;
}

void calcR()
{
	for (int p = 0; p < n; p++)
	{
		r[p][0][0] = 0;
		r[p][0][1] = -1;
		for (int i = 0; i < 2; i++)
			while(p - r[p][0][i] - 2 >= 0 && p + r[p][0][i] + 2 < n && s[p - r[p][0][i] - 2] == s[p + r[p][0][i] + 2])
				r[p][0][i] += 2;
	}
	for (int p = 1; p < n; p++)
	{
		r[p][1][0] = 0;
		r[p][1][1] = -1;
		for (int i = 0; i < 2; i++)
			while(p - r[p][1][i] - 2 >= 0 && p + r[p][1][i] + 1 < n && s[p - r[p][1][i] - 2] == s[p + r[p][1][i] + 1])
				r[p][1][i] += 2;
	}
	for (int p = 0; p < n; p++)
	{
		for (int i = n - p; i > 0; i--)
		{
			a[p][i] = a[p][i + 1];
			if (isP(p, p + i))
				a[p][i]++;
		}
		a[p][0] = a[p][1];
	}
	return;
}

void buildSuffArray()
{
	for (int i = 0; i < n; i++)
		SA[i] = i;
	for (int q = n - 1; q >= 0; q--)
	{
		for (int i = 0; i < A; i++)
			tt[i] = 0;
		for (int i = 0; i < n; i++)
		{
			int x = SA[i];
			int y = (x + q) % n;
			if (s[y] == 'a')
				tt[1]++;
		}
		for (int i = 0; i < n; i++)
		{
			int x = SA[i];
			int y = (x + q) % n;
			if (s[y] == 'a')
				tSA[tt[0]++] = x;
			else
				tSA[tt[1]++] = x;
		}
		for (int i = 0; i < n; i++)
			SA[i] = tSA[i];
	}
	return;
}

void printAns(int pos)
{
	ans[pos] = (char)0;
	printf("%s\n", ans);
	return;
}

void solve(int pos, int L, int R)
{
	for (int i = L; i < R; i++)
	{
		int p = SA[i];
		k -= a[p][pos] - a[p][pos + 1];
	}
	if (k <= 0)
	{
		printAns(pos);
		return;
	}
	int cnt = 0;
	int X = L;
	while(X < R && s[(SA[X] + pos) % n] == 'a') X++;
	for (int i = L; i < X; i++)
	{
		int p = SA[i];
		cnt += a[p][pos + 1];
	}
	if (cnt >= k)
	{
		ans[pos] = 'a';
		solve(pos + 1, L, X);
	}
	else
	{
		ans[pos] = 'b';
		k -= cnt;
		solve(pos + 1, X, R);
	}
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%s", s);
	n = strlen(s);
	scanf("%d", &k);

	calcR();
	buildSuffArray();
	solve(0, 0, n);

	return 0;
}