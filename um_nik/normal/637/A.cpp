#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int ans = 0;
const int N = (int)1e6 + 100;
int a[N];

int main()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int x;
		scanf("%d", &x);
		a[x]++;
		if (a[x] > a[ans])
			ans = x;
	}
	printf("%d\n", ans);

	return 0;
}