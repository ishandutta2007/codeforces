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

const int M = (1 << 20);
int n;
int d[1000];
int usedMasks[M];
int cc = 1;

bool check(int mask)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (mask & (1 << i))
			d[cnt++] = i + 1;
	}
	cc++;
	for (int i = 1; i <= n; i++)
	{
		int curMask = 0;
		for (int s = 0; s < cnt; s++)
		{
			if (i % d[s] == 0)
				curMask |= (1 << s);
		}
		if (usedMasks[curMask] == cc)
			return false;
		usedMasks[curMask] = cc;
	}
	return true;
}

void printBit(int mask)
{
	for (int i = 0; i < n; i++)
	{
		if (mask & (1 << i))
			cout << i + 1 << ' ';
	}
	cout << endl;
}

int ans[1000000];

int main()
{
	scanf("%d", &n);
	if (n == 1)
	{
		puts("0");
		return 0;
	}

	int cnt = 0;
	ans[cnt++] = 2;
	for (int i = 3; i <= n; i++)
	{
		for (int p = 1; p < i; p++)
		{
			bool eq = true;
			for (int s = 0; s < cnt && eq; s++)
			{
				bool a = (i % ans[s] == 0);
				bool b = (p % ans[s] == 0);
				if (a != b)
					eq = false;
			}
			if (eq)
			{
				ans[cnt++] = i;
				break;
			}
		}
	}
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++)
		printf("%d ", ans[i]);
	return 0;
}