#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 1010;
int n;
int a[N][3];
int deg[N][2];
int m;
int l[N], r[N];
vector<pii> ans;

void read()
{
	scanf("%d", &n);
	m = n - 3;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < 2; j++)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < 2; j++)
		{
			int x;
			scanf("%d", &x);
			deg[x][0]++;
		}

	for (int i = 1; i <= n; i++)
	{
		r[i] = i % n + 1;
		l[r[i]] = i;
	}
	return;
}

bool check(int x, int y, int z)
{
	if (x < z)
	{
		return (x < y && y < z);
	}
	return (y > x || y < z);
}

void inverseEdge(int idx)
{
	int v = a[idx][0], u = a[idx][1];
	if (v > u) swap(v, u);
	ans.push_back( mp(v, u) );
	int L = l[v], R = r[v];
	for (int i = 0; i < m; i++)
	{
		if (a[i][2] == -1) continue;
		if (i == idx) continue;
		int x = a[i][0], y = a[i][1];
		if (y == v)
			swap(x, y);
		if (x != v) continue;
		if (check(u, y, L))
			L = y;
		if (check(R, y, u))
			R = y;
	}
	a[idx][0] = L;
	a[idx][1] = R;
//	printf("new = %d %d\n", L, R);
	return;
}

void makeMagic(int v)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i][2] == -1) continue;
		if (a[i][0] == v || a[i][1] == v)
			inverseEdge(i);
	}
	return;
}

void deleteFromB(int v)
{
	int L = l[v];
	int R = r[v];
	l[R] = L;
	r[L] = R;
	deg[L][0]--;
	deg[R][0]--;
	for (int i = 0; i < m; i++)
	{
		if ((a[i][0] == L && a[i][1] == R) || (a[i][0] == R && a[i][1] == L))
			a[i][2] = -1;
	}
	deg[v][1] = -1;
	return;
}

void iter()
{
	int v = 1;
	while (v <= n && (deg[v][0] > 0 || deg[v][1] == -1)) v++;
	if (v == n + 1) throw;
	makeMagic(v);
	deleteFromB(v);
	return;
}

void printAns()
{
	int sz = (int)ans.size();
	if (sz > 20000) throw;
	printf("%d\n", sz);
	for (int i = 0; i < sz; i++)
		printf("%d %d\n", ans[i].first, ans[i].second);
	return;
}

int main()
{
	read();
	for (int i = 0; i < n - 3; i++)
		iter();
	printAns();

	return 0;
}