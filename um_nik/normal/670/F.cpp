#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

const int N = (int)1e6 + 100;
const int A = 10;
char s[N];
int n, m;
int a[A];
char ans[N];
char w[N];

int getLen(int x)
{
	int p = 0;
	while(x > 0)
	{
		p++;
		x /= 10;
	}
	return p;
}

void relaxAns()
{
	int L = 0;
	while(L < n && ans[L] == w[L]) L++;
	if (L == n) return;
	if (ans[L] < w[L]) return;
	for (int i = 0; i < n; i++)
		ans[i] = w[i];
	return;
}

void front()
{
	if (s[0] == '0') return;
	for (int i = 0; i < m; i++)
		w[i] = s[i];
	int L = m;
	for (int i = 0; i < A; i++)
		for (int j = 0; j < a[i]; j++)
			w[L++] = (char)('0' + i);
	relaxAns();
	return;
}

void solve(int x)
{
	int p = 1;
	while(p < A && a[p] == 0) p++;
	if (p == A) return;
	int L = 0;
	w[L++] = (char)('0' + p);
	a[p]--;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < a[i]; j++)
			w[L++] = (char)('0' + i);
	for (int i = 0; i < m; i++)
		w[L++] = s[i];
	for (int i = x; i < A; i++)
		for (int j = 0; j < a[i]; j++)
			w[L++] = (char)('0' + i);
	a[p]++;
	relaxAns();
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf(" %s ", s);
	n = strlen(s);
	for (int i = 0; i < n; i++)
		a[(int)(s[i] - '0')]++;
	for (int k = max(1, n - 10); k < n; k++)
	{
		int x = k + getLen(k);
		if (x > n) throw;
		if (x < n) continue;
		n = k;
		break;
	}
//	printf("%d\n", n);
	int k = n;
	while(k > 0)
	{
		a[k % 10]--;
		k /= 10;
	}
	scanf(" %s ", s);
	m = strlen(s);
	for (int i = 0; i < m; i++)
		a[(int)(s[i] - '0')]--;
	for (int i = 0; i < A; i++)
		if (a[i] < 0)
			throw;
	if (n == m)
	{
		printf("%s\n", s);
		return 0;
	}
	for (int i = 0; i < n; i++)
		ans[i] = 'A';
	ans[n] = (char)0;
	front();
	solve((int)(s[0] - '0'));
	solve((int)(s[0] - '0') + 1);
	if (ans[0] == 'A') throw;
	printf("%s\n", ans);

	return 0;
}