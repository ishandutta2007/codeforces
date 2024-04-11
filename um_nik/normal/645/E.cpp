#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

const int MOD = (int)1e9 + 7;
int add(int x, int y)
{
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
int sub(int x, int y)
{
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}

const int N = (int)2e6 + 10;
char s[N];
int a[N];
int b[100];
int n, m, k;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &m, &k);
	scanf(" %s", s);
	n = strlen(s);
	m += n;
	a[0] = 1;
	for (int i = 0; i < k; i++)
		b[i] = -1;
	for (int i = 0; i < n; i++)
	{
		int x = (int)(s[i] - 'a');
		int p = b[x];
		if (p == -1)
			a[i + 1] = add(a[i], a[i]);
		else
			a[i + 1] = add(a[i], sub(a[i], a[p]));
		b[x] = i;
	}
	multiset<int> setik;
	for (int i = 0; i < k; i++)
		setik.insert(b[i]);
	for (int i = n; i < m; i++)
	{
		int p = *setik.begin();
		setik.erase(setik.begin());
		setik.insert(i);
		if (p == -1)
			a[i + 1] = add(a[i], a[i]);
		else
			a[i + 1] = add(a[i], sub(a[i], a[p]));
	}
	printf("%d\n", a[m]);

	return 0;
}