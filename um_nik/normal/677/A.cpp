#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n, m;
int ans;

int main()
{
	scanf("%d%d", &n, &m);
	ans = n;
	while(n--)
	{
		int x;
		scanf("%d", &x);
		ans += (int)(x > m);
	}
	printf("%d\n", ans);

	return 0;
}