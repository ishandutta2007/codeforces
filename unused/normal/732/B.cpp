#include "bits/stdc++.h"
using namespace std;

int dat[505];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for (int i = 0; i < a; i++)
	{
		scanf("%d",&dat[i]);
	}

	if (a == 1)
	{
		printf("0\n%d\n", dat[0]);
		return 0;
	}

	int ans = 0;
	for (int i = 1; i < a; i++)
	{
		if (dat[i] + dat[i-1] < b)
		{
			ans += b - dat[i] - dat[i-1];
			dat[i] = b - dat[i-1];
		}
	}

	printf("%d\n", ans);
	for (int i = 0; i < a; i++) printf("%d ", dat[i]);
}