#include <bits/stdc++.h>
using namespace std;
// 0123456789ABCDEF

int hole[] =
{
	1,0,0,0,1,0,1,0,2,1,1,2,0,1,0,0
};

int main()
{
	int n;
	scanf("%d", &n);
	int ans = 0;
	do
	{
		ans += hole[n % 16];
		n /= 16;
	} while (n);
	printf("%d\n", ans);
}