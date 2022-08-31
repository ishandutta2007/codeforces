#include <iostream>
using namespace std;

int n;
bool used[100100];
bool pr[100100];
int sz;
int a[100100];
int ans_sz;
int ans[100100][2];

int main()
{
	scanf("%d", &n);

	for (int i = 2; i <= n; i++)
		pr[i] = 1;
	for (int i = 4; i <= n; i+= 2)
		pr[i] = 0;
	for (int i = 3; i <= n / 2; i++)
	{
		if (!pr[i])
			continue;
		sz = 1;
		a[0] = i;
		for (int j = 2 * i; j <= n; j += i)
		{
			if (pr[j])
			{
				a[sz++] = j;
				pr[j] = 0;
			}
		}
		if (sz & 1)
			a[sz++] = 2 * i;
		for (int i = 0; i < sz; i += 2)
		{
			ans[ans_sz][0] = a[i];
			ans[ans_sz][1] = a[i + 1];
			used[a[i]] = used[a[i + 1]] = 1;
			ans_sz++;
		}
	}
	sz = 0;
	for (int i = 2; i <= n; i += 2)
		if (!used[i])
			a[sz++] = i;
	for (int i = 0; i < sz - 1; i += 2)
	{
		ans[ans_sz][0] = a[i];
		ans[ans_sz][1] = a[i + 1];
		used[a[i]] = used[a[i + 1]] = 1;
		ans_sz++;
	}
	printf("%d\n", ans_sz);
	for (int i = 0; i < ans_sz; i++)
		printf("%d %d\n", ans[i][0], ans[i][1]);

	return 0;
}