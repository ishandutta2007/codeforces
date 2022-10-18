#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long s64;

const int MaxNPoss = 2944730;

template <class T>
inline void tension(T &a, const T &b)
{
	if (b < a)
		a = b;
}

int l, r, p;

int nP = 0;
int prime[25];

inline bool isPrime(const int &num)
{
	for (int i = 0; i < nP && prime[i] * prime[i] <= num; i++)
		if (num % prime[i] == 0)
			return false;
	return true;
}

int nPoss = 0;
int poss[MaxNPoss];
inline void dfs(int num, int v)
{
	if (v == nP)
	{
		poss[nPoss++] = num;
		return;
	}

	dfs(num, v + 1);
	while ((s64)num * prime[v] <= r)
	{
		num *= prime[v];
		dfs(num, v + 1);
	}
}

int main()
{
	cin >> l >> r >> p;

	for (int i = 2; i <= p; i++)
		if (isPrime(i))
			prime[nP++] = i;

	dfs(1ll, 0);

	sort(poss, poss + nPoss);
	
	static bool ok[MaxNPoss];
	static int f[MaxNPoss];
	fill(f, f + nPoss, INT_MAX);
	f[0] = 0, ok[0] = true;
	for (int b = 2; b <= p; b++)
	{
		for (int i = 0, j = 0; i < nPoss; i++)
		{
			if (f[i] == INT_MAX)
				continue;
			if (f[i] + b <= p)
				ok[i] = true;

			while (j < nPoss && poss[j] < (s64)poss[i] * b)
				j++;
			if (j == nPoss)
				continue;
			if (poss[j] == (s64)poss[i] * b)
				tension(f[j], f[i] + 1);
		}
	}

	int res = 0;
	for (int i = 0; i < nPoss; i++)
		if (l <= poss[i] && poss[i] <= r && ok[i])
			res++;
	cout << res << endl;

	return 0;
}