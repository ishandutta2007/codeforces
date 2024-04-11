#include <stdio.h>

int m[18], r[18];
bool foo[720721];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &m[i]);
	for (int i = 0; i < n; i++) scanf("%d", &r[i]);

	for (int i = 0; i < n; i++)
	{
		for (int j = r[i]; j <= 720720; j += m[i])
			foo[j] = true;
	}

	int cnt = 0;
	for (int i = 1; i <= 720720; i++) cnt += foo[i];

	printf("%.9f\n", cnt / 720720.0);
}