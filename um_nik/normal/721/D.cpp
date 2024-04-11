#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
#define mp make_pair

const int N = 200200;
int n, k;
ll a[N];
int zeroes = 0;
int sgn = 1;
ll m;
set<pli> setik;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%lld", &n, &k, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
		if (a[i] == 0) zeroes++;
		if (a[i] < 0) sgn *= -1;
	}
	if (zeroes > k)
	{
		for (int i = 0; i < n; i++)
			printf("%lld ", a[i]);
		printf("\n");
		return 0;
	}
	if (zeroes > 0)
	{
		k -= zeroes;
		for (int i = 0; i < n; i++)
		{
			if (a[i] != 0) continue;
			zeroes--;
			if (zeroes > 0)
			{
				a[i] = m;
				continue;
			}
			a[i] = -m * sgn;
			sgn = -1;
		}
	}
	if (sgn == 1)
	{
		int pos = -1;
		for (int i = 0; i < n; i++)
			if (pos == -1 || abs(a[i]) < abs(a[pos]))
				pos = i;
		if (a[pos] > 0)
		{
			while(k > 0 && a[pos] >= 0)
			{
				k--;
				a[pos] -= m;
			}
		}
		else
		{
			while(k > 0 && a[pos] <= 0)
			{
				k--;
				a[pos] += m;
			}
		}
	}
	
	for (int i = 0; i < n; i++)
		setik.insert(mp(abs(a[i]), i));
	while(k--)
	{
		int p = setik.begin()->second;
		setik.erase(setik.begin());
		if (a[p] > 0)
			a[p] += m;
		else
			a[p] -= m;
		setik.insert(mp(abs(a[p]), p));
	}
	for (int i = 0; i < n; i++)
		printf("%lld ", a[i]);
	printf("\n");

	return 0;
}