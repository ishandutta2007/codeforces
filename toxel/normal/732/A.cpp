#include<bits/stdc++.h>
int main()
{
	int k, r;
	scanf("%d%d", &k, &r);
	int i;
	for (i = 1; i <= 10; i++)
		if (k * i % 10 == 0 || k * i % 10 == r)
			break;
	printf("%d\n", i);
	return 0;
}