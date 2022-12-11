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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)1e5 + 10;
bool used[N];
int p[N];
int sz[N];
int cntC = 0;

void getCycle(int v)
{
	int curSz = 0;
	while (!used[v])
	{
		curSz++;
		used[v] = 1;
		v = p[v];
	}
	sz[cntC++] = curSz;
}

void connectCycle(int a, int b, int v)
{
	while (!used[v])
	{
		printf("%d %d\n", a + 1, v + 1);
		swap(a, b);
		used[v] = 1;
		v = p[v];
	}
}

void fail()
{
	puts("NO");
	exit(0);
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &p[i]);
		p[i]--;
	}
	for (int i = 0; i < n; i++)
	{
		if (!used[i])
			getCycle(i);
	}
	sort(sz, sz + cntC);
	if (sz[0] == 1)
	{
		int v = 0;
		while (p[v] != v)
			v++;
		puts("YES");
		for (int i = 0; i < n; i++)
		{
			if (i == v) continue;
			printf("%d %d\n", i + 1, v + 1);
		}
		return 0;
	}
	else if (sz[0] == 2)
	{
		for (int i = 1; i < cntC; i++)
		{
			if (sz[i] % 2 != 0)
				fail();
		}
		int a = 0, b = 0;
		for (int i = 0; i < n; i++)
		{
			if (p[p[i]] == i)
				a = i, b = p[i];
		}
		puts("YES");
		printf("%d %d\n", a + 1, b + 1);
		memset(used, 0, sizeof(used));
		used[a] = used[b] = 1;
		for (int i = 0; i < n; i++)
		{
			if (!used[i])
				connectCycle(a, b, i);
		}
	}
	else
		fail();
	return 0;
}