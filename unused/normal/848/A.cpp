#include <bits/stdc++.h>
using namespace std;

int main()
{
	int k;
	scanf("%d", &k);

	if (k == 0)
	{
		printf("z\n");
		return 0;
	}

	char last = 'a';

	for (int i = 100000; k;)
	{
		if (i * 1ll * (i - 1) / 2 <= k)
		{
			printf("%s", string(i, last++).c_str());
			k -= i * (i - 1) / 2;
		}
		else --i;
	}
	printf("\n");
}