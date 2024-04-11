#include <bits/stdc++.h>
using namespace std;

int n, a[100005], maxi, pos, cnt[40], tmp;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= 30; j++)
			if (a[i] & (1 << j)) cnt[j]++;
	for (int i = 0; i <= 30; i++)
		if (cnt[i] == 1) tmp |= (1 << i);
	for (int i = 1; i <= n; i++)
		if ((a[i] & tmp) > maxi) maxi = a[i] & tmp, pos = i;
	if (pos) printf("%d ", a[pos]);
	for (int i = 1; i <= n; i++)
		if (i != pos) printf("%d ", a[i]);
	return 0;
}