#include <stdio.h>

char str[200005];

int main()
{
	int a, b;
	scanf("%d%d%s", &a, &b, str);

	int pts = 0;
	while (str[pts] != '.') pts++;
	int i;
	for (i = pts + 1; str[i] && str[i] < '5'; i++);
	if (str[i] == 0) i--;
	if (str[i] < '5')
	{
		printf("%s", str);
		return 0;
	}

	while (b--)
	{
		i--;
		if (i == pts) goto roundup;
		str[i]++;
		if (str[i] < '5') break;
	}
	str[i + 1] = 0;
	printf("%s", str);
	return 0;

roundup:
	str[pts] = 0;
	str[--pts]++;
	for (int i = pts; i >= 1; i--)
	{
		if (str[i] > '9')
		{
			str[i] = '0';
			str[i - 1]++;
		}
		else break;
	}

	if (str[0] > '9')
	{
		printf("10%s", str + 1);
	}
	else printf("%s", str);
	return 0;
}