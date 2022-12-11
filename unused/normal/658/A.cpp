#include <stdio.h>
#include <algorithm>
using namespace std;

int p[10005];
int t[10005];

int main()
{
	int n, c;
	scanf("%d%d", &n, &c);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &p[i]);
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t[i]);
	}

	int asum = 0, bsum = 0;

	int tsum = 0;
	for (int i = 0; i < n; i++)
	{
		tsum += t[i];
		asum += max(0, p[i] - c * tsum);
	}

	tsum = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		tsum += t[i];
		bsum += max(0, p[i] - c * tsum);
	}

	if (asum > bsum) printf("Limak\n");
	else if (asum < bsum) printf("Radewoosh\n");
	else printf("Tie\n");
}