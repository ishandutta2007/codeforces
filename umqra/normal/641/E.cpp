#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <sstream>
#include <fstream>
#include <functional>
#include <cassert>
#include <complex>
#include <valarray>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

const int M = (int)2e8 + 10;
char buf[M];
int mpos = 0;

inline void * operator new(size_t sz)
{
	mpos += sz;
	return buf + mpos - sz;
}

inline void operator delete(void*) {}

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int SZ = (int)1e6 + 10;

struct Node
{
	int x, y;
	int l, r;
	int sz;
	Node () : x(), y(), l(), r(), sz() {}
	Node (int _x)
	{
		x = _x;
		y = rand();
		l = r = -1;
		sz = 1;
	}
};

struct Fenv
{
	vector <int> f;
	int sz;
	Fenv ()
	{
		f = vector <int>();
		sz = 0;
	}
	Fenv (int _sz)
	{
		f = vector <int>(_sz);
		sz = _sz;
		for (int i = 0; i < sz; i++)
			f[i] = 0;
	}
	int getSum(int pos)
	{
		int sum = 0;
		for (int i = pos; i >= 0; i = (i & (i + 1)) - 1)
			sum += f[i];
		return sum;
	}
	int getSum(int a, int b)
	{
		return getSum(b) - getSum(a - 1);
	}

	void addVal(int pos, int val)
	{
		for (int i = pos; i < sz; i |= (i + 1))
			f[i] += val;
	}
};

Fenv fv[SZ];

vector <int> tme[SZ];
int allX[SZ];
int cntX = 0;

void add(int t, int x)
{
	int id = lower_bound(tme[x].begin(), tme[x].end(), t) - tme[x].begin();
	fv[x].addVal(id, 1);
}

void del(int t, int x)
{
	int id = lower_bound(tme[x].begin(), tme[x].end(), t) - tme[x].begin();
	fv[x].addVal(id, -1);
}

int getCnt(int t, int x)
{
	int id = upper_bound(tme[x].begin(), tme[x].end(), t) - tme[x].begin() - 1;
	return fv[x].getSum(id);
}

int A[SZ], T[SZ], X[SZ];
int cap[SZ];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &A[i], &T[i], &X[i]);
		allX[i] = X[i];
	}
	sort(allX, allX + n);
	cntX = unique(allX, allX + n) - allX;
	for (int i = 0; i < n; i++)
	{
		X[i] = lower_bound(allX, allX + cntX, X[i]) - allX;
		if (A[i] <= 2)
			cap[X[i]]++;
	}
	for (int i = 0; i < cntX; i++)
		tme[i].reserve(cap[i]);

	for (int i = 0; i < n; i++)
	{
		if (A[i] <= 2)
			tme[X[i]].push_back(T[i]);
	}
	for (int i = 0; i < cntX; i++)
	{
		sort(tme[i].begin(), tme[i].end());
		fv[i] = Fenv((int)tme[i].size());
	}
	
	for (int i = 0; i < n; i++)
	{
		if (A[i] == 1)
			add(T[i], X[i]);
		else if (A[i] == 2)
			del(T[i], X[i]);
		else
			printf("%d\n", getCnt(T[i], X[i]));
	}
	return 0;
}