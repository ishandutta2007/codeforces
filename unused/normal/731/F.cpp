#include "bits/stdc++.h"
using namespace std;

int dat[200005];

int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++) scanf("%d",&dat[i]);

	long long ans = 0;
	sort(dat, dat + n);
	for (int i = 0, j = 0; i < n; i = j)
	{
		long long sum = 0;
		// process first.
		int ptr = i;
		for (int k = dat[i]; k <= dat[n-1]; k += dat[i])
		{
			int upp = lower_bound(dat + ptr, dat + n, k + dat[i]) - dat;
			sum += (long long)k * (upp - ptr);
			ptr = upp;
		}
	
		ans = max(ans, sum);
		while (j < n && dat[i] == dat[j]) j++;
	}

	printf("%lld", ans);
}