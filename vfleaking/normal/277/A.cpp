#include <iostream>
#include <cstdio>
using namespace std;

// type
typedef unsigned u32;
typedef unsigned long long u64;
typedef int s32;
typedef long long s64;

// adjust
template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool tension(T &a, const T &b)
{
	if (b < a)
	{
		a = b;
		return true;
	}
	return false;
}

const int MaxN = 100;
const int MaxM = 100;

int ufs_f[1 + MaxN + MaxM];

inline void ufs_init(const int &nV)
{
	for (int i = 1; i <= nV; i++)
		ufs_f[i] = i;
}
inline int ufs_find(const int &v)
{
	if (ufs_f[v] != v)
		ufs_f[v] = ufs_find(ufs_f[v]);
	return ufs_f[v];
}
inline void ufs_union(const int &v, const int &u)
{
	ufs_f[ufs_find(v)] = ufs_find(u);
}

int main()
{
	int n, m;
	bool isAllZero = true;
	cin >> n >> m;

	ufs_init(n + m);
	for (int i = 1; i <= n; i++)
	{
		int k;
		scanf("%d", &k);
		if (k != 0)
			isAllZero = false;
		for (int j = 0; j < k; j++)
		{
			int a;
			scanf("%d", &a);
			ufs_union(i, n + a);
		}
	}

	if (isAllZero)
	{
		cout << n << endl;
		return 0;
	}

	int t = ufs_find(1);
	int res = 0;
	for (int i = 1; i <= n; i++)
		if (ufs_find(i) != t)
		{
			res++;
			ufs_union(i, t);
		}

	cout << res << endl;

	return 0;
}