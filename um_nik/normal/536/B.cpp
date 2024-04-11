#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
typedef long long ll;

const ll MOD = (ll)(1e9 + 7);
const ll A = 26;
ll ans;

const int N = (int)1e6 + 100;
int z[N];
char s[N];
int n, m;
int p;
int b[N];
int c[N];

void calcZ()
{
	int l = 0, r = 0;
	for (int i = 1; i < p; i++)
	{
		if (i < r)
			z[i] = min(r - i, z[i - l]);
		while(i + z[i] < p && s[z[i]] == s[i + z[i]]) z[i]++;
		if (i + z[i] > r)
		{
			l = i;
			r = i + z[i];
		}
	}
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);

	scanf("%d%d", &n, &m);
	scanf(" %s ", s);
	p = strlen(s);
	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);
	calcZ();

	bool ok = true;
	for (int i = 0; i < m - 1; i++)
	{
		int d = b[i + 1] - b[i];
		if (d >= p) continue;
		if (d + z[d] != p)
			ok = false;
	}
	if (!ok)
	{
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < m; i++)
	{
		b[i]--;
		c[b[i]]++;
		c[b[i] + p]--;
	}
	
	ans = 1;
	int bal = 0;
	for (int i = 0; i < n; i++)
	{
		bal += c[i];
		if (bal == 0)
			ans = (ans * A) % MOD;
	}
	printf("%d\n", (int)ans);

	return 0;
}