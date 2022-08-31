#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

const int N = 1500;
int n;
int a[N][2];
int st[N][2];
int sz;
int idx;
string ans;

void badEnd()
{
	cout << "IMPOSSIBLE" << endl;
	exit(0);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i][0], &a[i][1]);
	ans.resize(2 * n);
	sz = 0;
	for (int i = 0; i < 2 * n; i++)
	{
		if (sz == 0)
		{
			ans[i] = '(';
			st[sz][0] = idx++;
			st[sz][1] = i;
			sz++;
		}
		else
		{
			int v = st[sz - 1][0];
			int x = st[sz - 1][1];
			int l = x + a[v][0];
			int r = x + a[v][1];
			if (r < i)
				badEnd();
			if (l <= i)
			{
				ans[i] = ')';
				sz--;
			}
			else
			{
				ans[i] = '(';
				st[sz][0] = idx++;
				st[sz][1] = i;
				sz++;
			}
		}
	}
	if (sz > 0)
		badEnd();
	cout << ans << endl;

	return 0;
}