#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
using namespace std;

typedef long long ll;
#define X first
#define Y second
#define mp make_pair

const int N = (int)1e5 + 100;

int mod;
int answer[N];
bool used[N];


int add(int a, int b)
{
	a += b;
	if (a >= mod)
		return a - mod;
	return a;
}

int mult(int a, int b)
{
	ll c = (ll)a * b;
	return c % mod;
}

int myPow(int a, int k)
{
	if (k == 0)
		return 1;
	if (k & 1)
		return mult(a, myPow(a, k - 1));
	int x = myPow(a, k / 2);
	return mult(x, x);
}

int main()
{
	int n;
	scanf("%d", &n);
	mod = n;

	if (n == 1)
	{
		puts("YES\n1");
		return 0;
	}
	if (n == 4)
	{
		puts("YES\n1\n3\n2\n4");
		return 0;
	}

	bool prime = true;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			prime = false;
	}

	if (!prime)
	{
		puts("NO");
		return 0;
	}

	int curM = 1;
	for (int i = 1; i < n; i++)
		curM = mult(curM, i);

	answer[n - 1] = n;
	answer[0] = 1;
	for (int i = n - 1; i > 1; i--)
	{
		int value = mult(i, myPow(i - 1, mod - 2));
		answer[i - 1] = value;
	}
	curM = 1;
	for (int i = 0; i < n; i++)
	{
		if (used[answer[i]])
			throw;
		used[answer[i]] = 1;
		curM = mult(curM, answer[i]);
		if (curM != (i + 1) % n)
			throw;
	}
	
	puts("YES");
	for (int i = 0; i < n; i++)
		printf("%d\n", answer[i]);

	return 0;
}