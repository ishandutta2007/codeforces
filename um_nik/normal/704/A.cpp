#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

const int N = 300300;
int l[N], r[N];
bool used[N];
vector<int> a[N];
int n, q, m, ans;
int st = -1, fin = -1;

void del(int v)
{
	if (used[v]) throw;
	used[v] = 1;
	if (st == v && fin == v)
	{
		st = fin = -1;
		return;
	}
	int R = r[v], L = l[v];
	if (R != -1)
		l[R] = L;
	if (L != -1)
		r[L] = R;
	if (st == v)
		st = R;
	if (fin == v)
		fin = L;
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &q);
	m = ans = 0;
	while(q--)
	{
		int t, x;
		scanf("%d%d", &t, &x);
		if (t == 1)
		{
			int v = m++;
			a[x].push_back(v);
			if (st == -1)
			{
				l[v] = r[v] = -1;
				st = fin = v;
			}
			else
			{
				r[fin] = v;
				l[v] = fin;
				r[v] = -1;
				fin = v;
			}
			ans++;
		}
		else if (t == 2)
		{
			while(!a[x].empty())
			{
				int v = a[x].back();
				a[x].pop_back();
				if (used[v]) continue;
				del(v);
				ans--;
			}
		}
		else
		{
			while(st != -1)
			{
				if (st >= x) break;
				ans--;
				del(st);
			}
			if (st == -1)
				fin = -1;
		}
		printf("%d\n", ans);
	}

	return 0;
}