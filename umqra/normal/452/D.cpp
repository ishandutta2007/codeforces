#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int SZ = (int)3e7 + 10;
int cnt[SZ];
int n[3], t[3], sum[3];

int main()
{
	int k;
	cin >> k;
	for (int i = 0; i < 3; i++)
		cin >> n[i];
	for (int i = 0; i < 3; i++)
		cin >> t[i];
	for (int i = 0; i < 3; i++)
		sum[i] = 0;
	
	for (int tme = 0;; tme++)
	{
		int mn = k;
		for (int s = 0; s < 3; s++)
		{
			mn = min(mn, n[s] - sum[s]);
		}
		cnt[tme] = mn;
		k -= mn;
		if (k == 0)
		{
			printf("%d", tme + t[0] + t[1] + t[2]);
			return 0;
		}
		for (int s = 0; s < 3; s++)
		{
			sum[s] += mn;
			if (tme - t[s] + 1 >= 0)
				sum[s] -= cnt[tme - t[s] + 1];
		}
	}
	
	return 0;
}