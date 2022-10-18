#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MaxN = 100000;

int main()
{
	int n;
	char s[MaxN + 1];

	scanf("%s", s);
	n = strlen(s);

	int pos = 0;
	for (int i = 1; i < n; i++)
		if (s[i] == '0')
		{
			pos = i;
			break;
		}

	for (int i = pos; i + 1 < n; i++)
		s[i] = s[i + 1];
	s[n - 1] = '\0';
	puts(s);

	return 0;
}