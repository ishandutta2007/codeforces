#include <bits/stdc++.h>
using namespace std;

char s1[100005], s2[100005];

int main()
{
	scanf("%s%s", s1, s2);

	int c1 = 0, c2 = 0, diff = 0;
	for (int i = 0; s1[i]; i++)
	{
		if (s1[i] == '4') c1++;
		if (s2[i] == '4') c2++;
		if (s1[i] != s2[i]) diff++;
	}
	printf("%d\n", abs(c1 - c2) + (diff - abs(c1 - c2)) / 2);
}