#include <bits/stdc++.h>
using namespace std;


int T, n;
priority_queue <long long> Pr1, Pr2;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		long long sum = 0;
		scanf("%d", &n);
		while (!Pr1.empty()) Pr1.pop();
		while (!Pr2.empty()) Pr2.pop();
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			Pr1.push(x);
			sum += x;
		}
		Pr2.push(sum);
		for (int i = 1; i <= n; i++)
		{
			long long x = Pr1.top();
			Pr1.pop();
			while (Pr2.top() > x)
			{
				long long u = Pr2.top();
				Pr2.pop();
				Pr2.push(u / 2), Pr2.push(u - u / 2);
			}
			if (Pr2.top() == x) Pr2.pop();
			else
			{
				puts("NO");
				goto END;
			}
		}
		puts("YES");
		END:;
	}
	return 0;
}