#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

const int N = 100100;
int n;
char s[N], t[N];

int main()
{
	scanf("%s %s", s, t);
	n = strlen(s);
	int m = 0;
	for (int i = 0; i < n; i++)
		m += (int)(s[i] != t[i]);
	if (m % 2 == 1)
	{
		printf("impossible\n");
		return 0;
	}
	m /= 2;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == t[i])
		{
			printf("%c", s[i]);
			continue;
		}
		if (m > 0)
			printf("%c", s[i]);
		else
			printf("%c", t[i]);
		m--;
	}
	printf("\n");

	return 0;
}