#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100100;
const int K = 41;

typedef pair<int, int> pii;
#define mp make_pair
vector<pii> _a[N];
int m;
int len[N];
pii b[N];
int c[N];
int d[2][2];

void read()
{
	int n;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &len[i]);
		for (int j = 0; j < len[i]; j++)
		{
			int x;
			scanf("%d", &x);
			_a[x - 1].push_back(mp(i, j));
		}
	}
	return;
}

int solve(int n)
{
	for (int i = 0; i < n; i++)
		c[i] = n;
	for (int x = 1; x < K; x++)
	{
		d[0][0] = d[1][0] = -1;
		d[0][1] = d[1][1] = n;
		for (int i = n - 1; i >= 0; i--)
		{
			if (b[i].second % x != 0) continue;
			int y = b[i].first % x;
			if (d[0][0] != y)
				c[i] = min(c[i], d[0][1]);
			else
				c[i] = min(c[i], d[1][1]);
			if (d[0][0] != y)
			{
				d[1][0] = d[0][0];
				d[1][1] = d[0][1];
			}
			d[0][0] = y;
			d[0][1] = i;
		}
	}
	int ans = 0;
	int r = n;
	for (int i = n - 1; i >= 0; i--)
	{
		r = min(r, c[i]);
		ans = max(ans, r - i);
	}
	return ans;
}

int solve(vector<pii> a)
{
	int ans = 0;
	int l = 0;
	while(l < (int)a.size())
	{
		int r = l + 1;
		while(r < (int)a.size() && a[r].first == a[r - 1].first + 1) r++;
		int k = 0;
		while(l < r)
		{
			b[k++] = mp(a[l].second, len[a[l].first]);
			l++;
		}
		ans = max(ans, solve(k));
	}
	return ans;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	for (int x = 0; x < m; x++)
		printf("%d\n", solve(_a[x]));

	return 0;
}