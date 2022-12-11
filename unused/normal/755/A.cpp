#include <bits/stdc++.h>
using namespace std;

bool isprime(int n)
{
	if (n == 1) return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return false;
	return true;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= 1000; i++)
	{
		if (isprime(i * n + 1)) continue;
		printf("%d", i); 
		return 0;
	}
}