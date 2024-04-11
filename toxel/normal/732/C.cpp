#include<bits/stdc++.h>
int main()
{
	long long b, d, s, cnt = 0;
	scanf("%I64d%I64d%I64d", &b, &d, &s);
	long long max = b;
	if (d > b)
		max = d;
	if (s > max)
		max = s;
	if (d == b && d == s)
		return printf("0"), 0;
	if (b == max)
		cnt++;
	if (d == max)
		cnt++;
	if (s == max)
		cnt++;
	if (cnt == 2)
		return printf("%I64d", max * 3 - b - d - s - 1), 0;
	return printf("%I64d", max * 3 - b - d - s - 2), 0;
}