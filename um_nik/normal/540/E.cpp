#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

const int N = (int)2e5 + 200;
int n;
int m;
int s[N][2];
int a[N];
int b[N];
ll ans;
map<int, int> mapchik;
int t[N];

void add(int p, int v)
{
	for (; p < m; p |= (p + 1))
		t[p] += v;
	return;
}
int getSum(int r)
{
	int res = 0;
	for(; r >= 0; r = (r & (r + 1)) - 1)
		res += t[r];
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &s[i][0], &s[i][1]);
		a[2 * i] = s[i][0];
		a[2 * i + 1] = s[i][1];
	}
	sort(a, a + 2 * n);
	m = unique(a, a + 2 * n) - a;
	for (int i = 0; i < m; i++)
	{
		mapchik[a[i]] = i;
		b[i] = a[i];
	}
	for (int i = 0; i < n; i++)
	{
		int x = mapchik[s[i][0]];
		int y = mapchik[s[i][1]];
		swap(a[x], a[y]);
	}
	ans = 0;
	for (int i = 0; i < m; i++)
	{
		int x = a[i];
		int pos = mapchik[x];
		ans += abs(b[i] - x) - abs(pos - i);
	}
	for (int i = 0; i < m; i++)
		a[i] = mapchik[a[i]];
	for (int i = m - 1; i >= 0; i--)
	{
		ans += getSum(a[i]);
		add(a[i], 1);
	}
	cout << ans << endl;

	return 0;
}