#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
#define mp make_pair
#define X first
#define Y second

const int N = 200200;
int n;
pii a[N];
int ans[N];
int t[N];

void add(int r, int v)
{
	for(; r <= n; r = r | (r + 1))
		t[r] += v;
	return;
}

int getSum(int r)
{
	int res = 0;
	for(; r >= 0; r = (r & (r + 1)) - 1)
		res += t[r];
	return res;
}
int getSum(int l, int r)
{
	if (l == 0) return getSum(r);
	return getSum(r) - getSum(l - 1);
}

void read()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		a[i - 1] = mp(x, i);
	}
	sort(a, a + n);
	return;
}

void solve()
{
	for (int i = 0; i < n; i++)
	{
		cerr << i << endl;
		int p = a[i].Y;
		for (int k = 1; k < n && k * (p - 1) + 2 <= n; k++)
		{
			int l = k * (p - 1) + 2;
			int r = min(n, k * p + 1);
			ans[k] += getSum(l, r);
		}
		add(p, 1);
	}
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	solve();
	for (int i = 1; i < n; i++)
		printf("%d ", ans[i]);

	return 0;
}