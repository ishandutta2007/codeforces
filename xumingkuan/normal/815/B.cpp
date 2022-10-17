#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

namespace Input
{
	const int BUF = 65536;
	char buf[BUF + 1];
	char *head = buf, *tail = buf;
}
inline char inputchar()
{
	using namespace Input;
	if(head == tail)
		*(tail = (head = buf) + fread(buf, 1, BUF, stdin)) = 0;
	return *head++;
}
inline void inputnum(int &ret)
{
	char ch = inputchar();
	while(ch < '0' || ch > '9')
		ch = inputchar();
	ret = ch - '0';
	ch = inputchar();
	while(ch >= '0' && ch <= '9')
	{
		ret = ret * 10 + ch - '0';
		ch = inputchar();
	}
}
const int MOD = 1000000007, MAXN = 202020;
int n, a[MAXN];
int fac[MAXN], facrev[MAXN];
long long quickmul(int a, int b)
{
	long long ret = 1;
	for(; b; b >>= 1, a = (long long)a * a % MOD)
		if(b & 1)
			ret = ret * a % MOD;
	return ret;
}
bool tp = true;
void work()
{
	for(int i = 0; i < n - 1; i++, tp = !tp)
	{
		a[i] = (tp ? (a[i] + a[i + 1]) % MOD : (a[i] - a[i + 1] + MOD) % MOD);
	}
	n--;
}
int main()
{
	inputnum(n);
	for(int i = 0; i < n; i++)
		inputnum(a[i]);
	fac[0] = 1;
	for(int i = 1; i <= n; i++)
		fac[i] = (long long)fac[i - 1] * i % MOD;
	facrev[n] = quickmul(fac[n], MOD - 2);
	for(int i = n; i >= 1; i--)
		facrev[i - 1] = (long long)facrev[i] * i % MOD;
	while(n % 4 != 1)
		work();
	int n2 = n / 2;
	int ans = 0;
	for(int i = 0; i < n; i += 2)
		ans = (ans + (long long)a[i] * fac[n2] % MOD * facrev[i / 2] % MOD * facrev[n2 - i / 2]) % MOD;
	printf("%d\n", ans);
	return 0;
}