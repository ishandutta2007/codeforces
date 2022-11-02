#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
const int inf = 1000000007;

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	long long res = 1;
	for(int i = 1; i <= n - k; i++)
	{
		res = (res * (n - k)) % inf;
	}
	for(int i = 1; i <= k - 1; i++)
	{
		res = (res * k) % inf;
	}
	printf("%I64d", res);
	return 0;
}