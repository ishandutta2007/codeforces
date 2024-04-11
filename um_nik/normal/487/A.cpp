#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int ourHP, monHP, at, def;
int costHP, costAt, costDef;
int ans = (int)1e9;
int tmp;

int main()
{
	scanf("%d%d%d", &ourHP, &at, &def);
	scanf("%d", &monHP);
	scanf("%d", &tmp);
	def -= tmp;
	scanf("%d", &tmp);
	at -= tmp;

	scanf("%d%d%d", &costHP, &costAt, &costDef);

	for (int dAt = 0; dAt <= 200; dAt++)
		for (int dDef = 0; dDef <= 200; dDef++)
		{
			int nAt = at + dAt;
			int nDef = def + dDef;
			int tCost = dAt * costAt + dDef * costDef;
			if (nAt <= 0) continue;
			if (nDef >= 0)
			{
				ans = min(ans, tCost);
				continue;
			}
			int mv = (monHP + nAt - 1) / nAt;
			int d = max(0, mv * abs(nDef) - ourHP + 1);
			ans = min(ans, tCost + d * costHP);
		}
	printf("%d\n", ans);

	return 0;
}