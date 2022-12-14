#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1010;

struct Portal
{
	int x, y, p, q;
	Portal(int _x, int _y, int _p, int _q): x(_x), y(_y), p(_p), q(_q) {}
};
vector<Portal> ans;
int n, a[N], b[N], c[N], d[N], ra[N], rb[N], rc[N], rd[N];

int main()
{
	int i;
	
	scanf("%d", &n);
	
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", b + i);
		rb[b[i]] = i;
	}
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", a + i);
		ra[a[i]] = i;
	}
	for (i = 1; i <= n; ++i) c[i] = d[i] = rc[i] = rd[i] = i;
	
	for (i = 1; i < n; ++i)
	{
		if (c[i] == ra[i] && d[i] == rb[i]) continue;
		ans.push_back(Portal(i, rc[ra[i]], rd[rb[i]], i));
		int t1 = c[i];
		int t2 = d[i];
		swap(c[i], c[rc[ra[i]]]);
		swap(d[i], d[rd[rb[i]]]);
		swap(rc[ra[i]], rc[t1]);
		swap(rd[rb[i]], rd[t2]);
	}
	
	printf("%d\n", ans.size());
	for (auto k : ans) printf("%d %d %d %d\n", k.x, k.y, k.p, k.q);
	return 0;
}