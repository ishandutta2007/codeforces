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

typedef long double ld;
typedef long long ll;
#define X first
#define Y second
#define mp make_pair

int p[100];

int calcInv(int n)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int s = 0; s < i; s++)
		{
			if (p[s] > p[i])
				cnt++;
		}
	}
	return cnt;
}

ld solve(int n, int k)
{
	if (k == 0)
		return calcInv(n);
	ld res = 0;
	ld pr = 1. / ((n * (n + 1)) / 2);
	for (int i = 0; i < n; i++)
	{
		for (int s = i; s < n; s++)
		{
			reverse(p + i, p + s + 1);
			res += pr * solve(n, k - 1);
			reverse(p + i, p + s + 1);
		}
	}
	return res;
}

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> p[i];

	printf("%.11lf", (double)solve(n, k));
	return 0;
}