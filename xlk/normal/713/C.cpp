#include <bits/stdc++.h>
using namespace std;
int n, x;
priority_queue<int> q;
long long z;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		x -= i;
		q.push(x);
		q.push(x);
		z += q.top() - x;
		q.pop();
	}
	printf("%lld\n", z);
	return 0;
}