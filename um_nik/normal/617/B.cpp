#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

const int N = 111;
int n;
int a[N];
ll ans = 1;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	bool ok = false;
	for (int i = 0; i < n; i++)
		ok |= (a[i] == 1);
	if (!ok)
	{
		printf("0\n");
		return 0;
	}
	int lst = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0) continue;
		if (lst != -1)
			ans *= i - lst;
		lst = i;
	}
	printf("%lld\n", ans);

	return 0;
}