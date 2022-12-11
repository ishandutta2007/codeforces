#include "bits/stdc++.h"
using namespace std;

int dat[200005];

int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&dat[i]);
	}

	for (int i = 0; i < n; i++)
	{
		dat[i] %= 2;
		if (dat[i])
		{
			if (dat[i+1]==0)
			{
				printf("NO");
				return 0;
			}
			dat[i+1]--;
		}
	}

	printf("YES");
}