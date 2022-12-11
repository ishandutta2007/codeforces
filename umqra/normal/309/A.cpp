#include <iostream>
#include <cstdio>
using namespace std;

int a[(int)1e6 + 10];

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
	
	int n, len, t;
	scanf("%d%d%d", &n, &len, &t);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	double globCnt = 0;
	int gT = t * 2;
	for (int i = 0; i < n; i++)
	{
		int locCnt = 0;
		t = gT;
		if (t >= (len - a[i]))
		{
			locCnt += n - i - 1;
			t -= (len - a[i]);
			locCnt += (t / len) * (n - 1);
			t %= len;
			int l = -1, r = n;
			while (r - l > 1)
			{
				int m = (l + r) / 2;
				if (a[m] <= t)
					l = m;
				else
					r = m;
			}
			if (l >= i)
				locCnt += l;
			else
				locCnt += l + 1;
		}
		else
		{
			int l = i, r = n;
			while (r - l > 1)
			{
				int m = (l + r) / 2;
				if (a[m] - a[i] <= t)
					l = m;
				else
					r = m;
			}
			locCnt += (l - i);
		}
		globCnt += (double)locCnt;
	}
	
	
	printf("%.7lf", globCnt / 4.);
	
	return 0;
}