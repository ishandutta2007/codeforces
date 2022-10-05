#include<bits/stdc++.h>
const int N = 100010;

int n, l[N], r[N];

int main()
{
	scanf("%d", &n);
	int L = 0, R = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &l[i], &r[i]);
		L += l[i];
		R += r[i];
	}
	int sit = 0, max = abs(L - R);
	for (int i = 0; i < n; i++)
	{
		L = L - l[i] + r[i];
		R = R - r[i] + l[i];
		if (abs(L - R) > max)
		{
			max = abs(L - R);
			sit = i + 1;
		}
		L = L - r[i] + l[i];
		R = R - l[i] + r[i];
	}
	printf("%d\n", sit);
	return 0;
}