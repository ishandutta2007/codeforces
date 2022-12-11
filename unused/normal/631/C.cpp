#include <stdio.h>
#include <deque>
#include <functional>
#include <algorithm>
using namespace std;

int dat[200005];
pair<int, int> order[200005];
int ans[200005];
int op;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &dat[i]);
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);

		while (op >= 1 && order[op - 1].second <= b)
			op--;

		if (op == 0 || order[op - 1].first != a)
		{
			order[op++] = { a, b };
			continue;
		}
	}

	reverse(order, order + op);

	int deqp = n - 1;

	while (deqp >= order[op - 1].second)
	{
		ans[deqp] = dat[deqp];
		deqp--;
	}

	if (order[op - 1].first == 1) sort(dat, dat + order[op - 1].second);
	else sort(dat, dat + order[op - 1].second, greater<int>());

	int front = 0, rear = order[op - 1].second - 1;
	bool back = true;

	while (op >= 1)
	{
		auto element = order[--op];
		int diff = (op == 0 ? element.second : element.second - order[op - 1].second);
		if (back)
		{
			for (int i = 0; i < diff; i++)
			{
				ans[deqp--] = dat[rear - i];
			}
			rear -= diff;
		}
		else
		{
			for (int i = 0; i < diff; i++)
			{
				ans[deqp--] = dat[front + i];
			}
			front += diff;
		}
		back = !back;
	}

	for (int i = 0; i < n; i++) printf("%d ", ans[i]);
}