#include<bits/stdc++.h>
using namespace std;
const int N = 200010;

priority_queue <pair<long long, int> > q;
long long n, k, x, a[N];

int main()
{
	scanf("%I64d%I64d%I64d", &n, &k, &x);
	int pos = 0, neg = 0, zero = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%I64d", &a[i]);
		if (a[i] > 0)
			pos++;
		else if (!a[i])
			zero++;
		else
			neg++;
	}
	bool flag = false;
	if (zero)
	{
		for (int i = 0; i < n; i++)
		{
			if (!a[i] && k)
			{
				k--;
				zero--;
				if (!flag)
				{
					flag =true;
					if (!(neg & 1))
						a[i] -= x;
					else
						a[i] += x;
				}
				else
					a[i] += x;
			}
		}
	}
	else if (! (neg & 1))
	{
		int sit, min = 1000000010;
		for (int i = 0; i < n; i++)
			if (abs(a[i]) < min)
			{
				min= abs(a[i]);
				sit = i;
			}
		if (a[sit] > 0)
		{
			while (k && a[sit] >= 0)
			{
				k--;
				a[sit] -= x;
			}
		}
		else
		{
			while (k && a[sit] <= 0)
			{
				k--;
				a[sit] += x;
			}
		}
	}
	for (int i = 0; i < n; i++)
		q.push({-abs(a[i]), i});
	while (k)
	{
		k--;
		int sit = q.top().second;
		if (a[sit] > 0)
			a[sit] += x;
		else
			a[sit] -= x;
		q.pop();
		q.push({-abs(a[sit]), sit});
	}
	for (int i = 0; i < n; i++)
		printf("%I64d ", a[i]);
	return 0;
}