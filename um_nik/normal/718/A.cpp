#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 200200;
int n, k;
char s[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	scanf(" %s ", s);
	int p = 0;
	while(p < n && s[p] != '.') p++;
	int dot = p;
	p++;
	while(p < n && s[p] < '5') p++;
	if (p == n)
	{
		printf("%s\n", s);
		return 0;
	}
	while(k > 0)
	{
		k--;
		p--;
		while(s[p] == '9') p--;
		if (s[p] == '.')
		{
			p--;
			while(p >= 0 && s[p] == '9')
			{
				s[p] = '0';
				p--;
			}
			if (p >= 0)
			{
				s[p]++;
				for (int i = 0; i < dot; i++)
					printf("%c", s[i]);
				printf("\n");
				return 0;
			}
			printf("1");
			for (int i = 0; i < dot; i++)
				printf("%c", s[i]);
			printf("\n");
			return 0;
		}
		s[p]++;
		if (s[p] < '5') break;
	}
	for (int i = 0; i <= p; i++)
		printf("%c", s[i]);
	printf("\n");

	return 0;
}