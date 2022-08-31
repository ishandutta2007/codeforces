#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

char s[50];
char a[2][20];
int d[30];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%s", s);
	for (int i = 0; i < 27; i++)
		d[(int)(s[i] - 'A')]++;
	for (int i = 0; i < 26; i++)
		if (s[i] == s[i + 1])
		{
			printf("Impossible\n");
			return 0;
		}
	int x = 0;
	while(d[x] == 1) x++;
	char c = (char)('A' + x);
	int p1 = -1, p2 = -1;
	for (int i = 0; i < 27; i++)
	{
		if (s[i] != c) continue;
		if (p1 == -1)
			p1 = i;
		else
			p2 = i;
	}
	if (p2 - p1 == 1) throw;
	int len = p2 - p1 - 1;
	if (len & 1)
	{
		a[0][len / 2] = c;
		int pos = p1 + 1;
		for (int i = len / 2 - 1; i >= 0; i--)
			a[0][i] = s[pos++];
		for (int i = 0; i <= len / 2; i++)
			a[1][i] = s[pos++];
		pos = p1 - 1;
		for (int i = len / 2 + 1; i < 13; i++)
		{
			if (pos == -1) pos = 26;
			a[0][i] = s[pos--];
		}
		for (int i = 12; i > len / 2; i--)
		{
			if (pos == -1) pos = 26;
			a[1][i] = s[pos--];
		}
	}
	else
	{
		a[0][len / 2] = c;
		int pos = p1 + 1;
		for (int i = len / 2 - 1; i >= 0; i--)
			a[0][i] = s[pos++];
		for (int i = 0; i < len / 2; i++)
			a[1][i] = s[pos++];
		pos = p1 - 1;
		for (int i = len / 2 + 1; i < 13; i++)
		{
			if (pos == -1) pos = 26;
			a[0][i] = s[pos--];
		}
		for (int i = 12; i >= len / 2; i--)
		{
			if (pos == -1) pos = 26;
			a[1][i] = s[pos--];
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 13; j++)
			printf("%c", a[i][j]);
		printf("\n");
	}

	return 0;
}