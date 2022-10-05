#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
set <int> s;

int main()
{
	int n, a[N], max;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		s.insert(a[i]);
	}
	bool flag = true;
	while (flag)
	{
		flag = false;
		set<int>::iterator it;
		it = --s.end();
		max = *it;
		while (max > 1)
		{
			max /= 2;
			if (!s.count(max))
			{
				flag = true;
				s.erase(*it);
				s.insert(max);
				break;
			}
		}
	}
	set<int>::iterator it;
	for (it = s.begin(); it != s.end(); ++it)
		printf("%d ", *it);
	return 0;
}