#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 1000005
#define ll long long
int n, m, s, w, A[N], B[N];
template<typename tmp>void Read(tmp &p)
{
	p = 0;
	int f = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar())f |= (c == '-');
	for (; c >= '0' && c <= '9'; c = getchar())p = p * 10 + c - '0';
	if (f)p =- p;
}
int main()
{
	Read(n), Read(m);
	for (int i = 1; i <= m; i++)
	{
		Read(A[i]), Read(B[i]);
		w = (w + (ll)(A[i] - 1) * B[i]) % n;
		s += B[i];
		if (s > n)
		{
			puts("-1");
			return 0;
		}
	}
	if (s < n)
	{
		puts("1");
		return 0;
	}
	s = (ll)(n - 1) * n / 2 % n;
	if (s == w)
		puts("1");
	else
		puts("-1");
}