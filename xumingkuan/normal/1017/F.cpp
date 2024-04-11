#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <bitset>
const int MAXPR = 20000;
const int MAXP = 3000;//2262
const int BLOCK = 100000;
std::bitset<BLOCK> mp;
int prime[MAXP], primenum;
int n;
unsigned A, B, C, D, ans;
void init()
{
	mp.reset();
	primenum = 0;
	for(int i = 2; i < BLOCK; i++)
	{
		if(!mp[i] && i <= MAXPR)
			prime[++primenum] = i;
		for(int j = 1; i * prime[j] < BLOCK; j++)
		{
			mp[i * prime[j]] = 1;
			if(i % prime[j] == 0)
				break;
		}
	}
	ans = 0;
}
inline unsigned calc(unsigned x)
{
	return ((A * x + B) * x + C) * x + D;
}
void getans(int x)
{
	unsigned cnt = 0;
	int tmp = n;
	while(tmp)
		cnt += (tmp /= x);
	ans += cnt * calc(x);
}
void sieve(int st)
{
	mp.reset();
	for(int i = 1; i <= primenum; i++)
		for(int j = (prime[i] - st % prime[i]) % prime[i]; j < BLOCK; j += prime[i])
			mp[j] = 1;
	for(int i = 0; i < BLOCK && st + i <= n; i++)
		if(!mp[i])
			getans(st + i);
}
int main()
{
	scanf("%d%u%u%u%u", &n, &A, &B, &C, &D);
	init();
	for(int i = 1; i <= primenum && prime[i] <= n; i++)
		getans(prime[i]);
	for(int i = 2; i <= n; i += BLOCK)
		sieve(i);
	printf("%u\n", ans);
	return 0;
}