#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MOD = 1000000007;
int x;
long long n;
int p[100], pn = 0;
long long quickmul(int a, int b)
{
	long long ret = 1;
	for(; b; b >>= 1, a = (long long)a * a % MOD)
		if(b & 1)
			ret = ret * a % MOD;
	return ret;
}
int main()
{
	cin >> x >> n;
	for(int i = 2; i * i <= x; i++)
		if(x % i == 0)
		{
			p[++pn] = i;
			while(x % i == 0)
				x /= i;
		}
	if(x > 1)
		p[++pn] = x;
	int ans = 1;
	for(int i = 1; i <= pn; i++)
	{
		long long now = n;
		long long cnt = 0;
		while(now > 0)
		{
			now /= p[i];
			cnt += now;
		}
		cnt %= MOD - 1;
		ans = ans * quickmul(p[i], cnt) % MOD;
	}
	cout << ans << endl;
	return 0;
}