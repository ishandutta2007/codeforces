#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 100100;
int n;
int m;
int ans;
int a[N];

int main()
{
	scanf("%d%d", &ans, &m);
	ans--;
	while(m--)
	{
		scanf("%d", &n);
		ans += n - 1;
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		if (a[0] != 1) continue;
		int t = 1;
		while(t < n && a[t] == t + 1)
		{
			t++;
			ans -= 2;
		}
	}
	printf("%d\n", ans);

	return 0;
}