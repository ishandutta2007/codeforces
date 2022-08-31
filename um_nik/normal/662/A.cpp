#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int N = 500200;
const int M = 60;
ll a[N];
ll A;
int n;
int b[M];

void gauss()
{
	for (int i = 0; i < M; i++)
		b[i] = -1;
	int it = 0;
	for (int i = 0; i < M; i++)
	{
		int v = -1;
		for (int j = it; j < n; j++)
		{
			if ((a[j] >> i) & 1LL)
			{
				v = j;
				break;
			}
		}
		if (v == -1) continue;
		swap(a[v], a[it]);
		b[i] = it;
		it++;
		for (int j = it; j < n; j++)
		{
			if ((a[j] >> i) & 1LL)
				a[j] ^= a[it - 1];
		}
	}
	return;
}

bool check(ll x)
{
	for (int i = 0; i < M; i++)
	{
		if (((x >> i) & 1LL) == 0LL) continue;
		if (b[i] == -1) return false;
		x ^= a[b[i]];
	}
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	A = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
		ll x;
		scanf("%lld", &x);
		a[i] ^= x;
		A ^= x;
	}
	gauss();
	/*
	for (int i = 0; i < n; i++)
		printf("%lld\n", a[i]);
	for (int i = 0; i < 5; i++)
		printf("%d ", b[i]);
	printf("\n");
	printf("%lld\n", A);
	*/
	if (!check(A))
	{
		printf("1/1\n");
		return 0;
	}
	ll res = 1;
	for (int i = 0; i < M; i++)
		if (b[i] != -1)
			res <<= 1;
	printf("%lld/%lld\n", res - 1, res);

	return 0;
}