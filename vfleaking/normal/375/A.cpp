#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MaxN = 1000000;

int main()
{
	int n;
	static char sa[MaxN + 1];

	scanf("%s", sa);
	n = strlen(sa);

	for (int i = find(sa, sa + n, '1') - sa; i + 1 < n; i++)
		sa[i] = sa[i + 1];
	n--;
	for (int i = find(sa, sa + n, '6') - sa; i + 1 < n; i++)
		sa[i] = sa[i + 1];
	n--;
	for (int i = find(sa, sa + n, '8') - sa; i + 1 < n; i++)
		sa[i] = sa[i + 1];
	n--;
	for (int i = find(sa, sa + n, '9') - sa; i + 1 < n; i++)
		sa[i] = sa[i + 1];
	n--;
	sa[n] = '\0';

	int inh = 0;
	for (int i = 0; i < n; i++)
		inh = (inh * 10 + sa[i] - '0') % 7;
	
	int s = 1;
	for (int i = 0; i < n; i++)
		s = s * 10 % 7;

	int a_n = 4;
	int a[] = {1, 6, 8, 9};
	do
	{
		int t = 0;
		for (int i = 0; i < a_n; i++)
			t = t * 10 + a[i];
		if ((t * s + inh) % 7 == 0)
		{
			cout << t;
			cout << sa;
			cout << endl;
			return 0;
		}
	}
	while (next_permutation(a, a + a_n));

	return 0;
}