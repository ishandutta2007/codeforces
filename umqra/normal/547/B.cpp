#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cmath>
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

const int N = (int)1e6 + 10;
int st[N];
int a[N], l[N], r[N];
int value[N];

int topSt = 0;

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	topSt = 0;
	for (int i = 0; i < n; i++)
	{
		while (topSt > 0 && a[st[topSt - 1]] >= a[i])
			topSt--;
		l[i] = (topSt > 0 ? st[topSt - 1] + 1 : 0);
		st[topSt++] = i;
	}
	topSt = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		while (topSt > 0 && a[st[topSt - 1]] >= a[i])
			topSt--;
		r[i] = (topSt > 0 ? st[topSt - 1] - 1 : n - 1);
		st[topSt++] = i;
	}

	for (int i = 0; i < n; i++)
	{
		int len = r[i] - l[i] + 1;
		value[len] = max(value[len], a[i]);
	}

	for (int i = n; i >= 0; i--)
		value[i] = max(value[i], value[i + 1]);

	for (int i = 1; i <= n; i++)
		printf("%d ", value[i]);
	
	return 0;
}