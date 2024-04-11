#include <stdio.h>
int main()
{
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int zero = -1, one = -1;
	{
		int lo = 0, hi = 1000000;
		while (lo <= hi)
		{
			int mid = (lo + hi) / 2;
			long long t = (long long)mid * (mid + 1) / 2;
			if (t == a)
			{
				zero = mid + 1;
				break;
			}
			else if (t < a) lo = mid + 1;
			else hi = mid - 1;
		}

		lo = 0, hi = 1000000;
		while (lo <= hi)
		{
			int mid = (lo + hi) / 2;
			long long t = (long long)mid * (mid + 1) / 2;
			if (t == d)
			{
				one = mid + 1;
				break;
			}
			else if (t < d) lo = mid + 1;
			else hi = mid - 1;
		}
	}

	if (zero == -1 || one == -1)
	{
		printf("Impossible");
		return 0;
	}

	if (b + c == 0)
	{
		if (zero <= 1) zero = 0;
		else if (one <= 1) one = 0;
		else {
			printf("Impossible");
			return 0;
		}
		while (zero--) printf("0");
		while (one--) printf("1");
		return 0;
	}

	if (b + c != (long long)zero*one)
	{
		printf("Impossible");
		return 0;
	}

	while (zero && one)
	{
		if ((long long)one * (zero - 1) >= c)
		{
			printf("0");
			zero--;
		}
		else 
		{
			printf("1");
			one--;
			c -= zero;
		}
	}

	while (zero--) printf("0");
	while (one--) printf("1");
}