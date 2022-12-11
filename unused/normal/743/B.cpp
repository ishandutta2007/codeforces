#include <bits/stdc++.h>
using namespace std;

void recur(int a, long long b)
{
	if (b == (1ll << (a - 1))) printf("%d", a);
	else recur(a - 1, b % (1ll << (a - 1)));
}

int main()
{
	int n; long long k;
	scanf("%d%lld", &n, &k);
	recur(n, k);
}