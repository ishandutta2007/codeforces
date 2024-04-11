#include "bits/stdc++.h"
using namespace std;

int dat[5005];
int cnt[5005];
int ans[5005];

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
		memset(cnt, 0, sizeof(cnt));
		int idx = 0;
		for (int j = i; j < n ;j++)
		{
			int z = dat[j];
			++cnt[z];
			if (cnt[z] > cnt[idx] || (cnt[z] == cnt[idx] && z < idx))
			{
				idx = z;
			}
			ans[idx]++;
		}
	}

	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	printf("\n");
}