#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n, k, a, b;
	scanf("%lld%lld%lld%lld", &n, &k, &a, &b);
	char aa = 'G', bb = 'B';
	if (a < b)
	{
		swap(a, b);
		swap(aa, bb);
	}
	if (a > b)
	{
		if (a > (b + 1) * k) {
			printf("NO"); return 0;
		}
		vector<int> cnt(b + 1);
		for (int i = 0; i < a; i++)
			cnt[i % (b + 1)]++;

		for (int i = 0; i <= b; i++)
		{
			if (i) putchar(bb);
			printf("%s", string(cnt[i], aa).c_str());
		}
	}
	else
	{
		while (a)
		{
			printf("BG");
			a--;
		}
	}
}