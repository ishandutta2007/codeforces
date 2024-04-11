#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int N = 100100;
int n;
char s[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf(" %s ", s);
	n = strlen(s);
	int l = 0;
	while(l < n && s[l] == 'a') l++;
	if (l == n)
	{
		s[n - 1] = 'z';
		printf("%s\n", s);
		return 0;
	}
	for (int i = l; i < n; i++)
	{
		if (s[i] == 'a') break;
		s[i]--;
	}
	printf("%s\n", s);

	return 0;
}