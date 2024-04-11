#include <bits/stdc++.h>
using namespace std;

int T, k, m;
long long fib[1005];
priority_queue <pair <int, int> > Pr;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		m = 0;
		long long sum = 0;
		while (!Pr.empty()) Pr.pop();
		scanf("%d", &k);
		for (int i = 1, x; i <= k; i++)
			scanf("%d", &x), sum += x, Pr.push(make_pair(x, 0x3f3f3f3f));
		fib[0] = fib[1] = 1;
		for (m = 2; ; m++)
		{
			fib[m] = fib[m - 1] + fib[m - 2];
			if (fib[m] >= sum + 1) break;
		}
		int pt = m - 2;
		if (fib[m] != sum + 1)
		{
			puts("NO");
			goto END;
		}
		while (!Pr.empty())
		{
			pair <int, int> u = Pr.top();
			Pr.pop();
			if (u.second == pt + 1)
			{
				puts("NO");
				goto END;
			}
			else if (u.first >= fib[pt]) u.first -= fib[pt];
			else
			{
				puts("NO");
				goto END;
			}
			u.second = pt;
			if (u.first) Pr.push(u);
			pt--;
		}
		puts("YES");
		END:;
	}
	return 0;
}
/*
1 1 2 3 5 8 13 21 34 55

1 2 5 13 = 21

55 55 21 12*/