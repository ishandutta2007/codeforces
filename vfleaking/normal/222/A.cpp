#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 100000;
const int MaxNum = 100000;

int main()
{
	static int q[MaxN * 2];
	static int bucket[MaxNum + 1];
	int top, bottom;

	top = bottom = 0;

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		q[bottom++] = a;
		bucket[a]++;
	}

	int res = -1;
	while (top < n)
	{
		if (bucket[q[top]] == n)
		{
			res = top;
			break;
		}

		q[bottom++] = q[top + k - 1];
		bucket[q[top + k - 1]]++;
		bucket[q[top]]--;
		top++;
	}

	cout << res << endl;

	return 0;
}