#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 15000;
int k, cnt[N], a[N], t[N], a_c;
char s[N];

inline void mt ()
{
	for (int i = 1; s[i]; i ++)
		cnt[s[i] - 'a' + 1] ++;
	for (int i = 1; i <= 26; i ++)
		if (cnt[i] % k != 0)
			{puts ("-1"); return ; }
		else if (cnt[i])
			a[++ a_c] = i, t[i] = cnt[i] / k;
	for (int i = 1; i <= k; i ++)
		for (int j = 1; j <= a_c; j ++)
			for (int k = 1; k <= t[a[j]]; k ++)
				putchar (a[j] + 'a' - 1);
}

int main ()
{
	scanf ("%d", &k);
	scanf ("%s", s + 1);
	mt ();
	return 0;
}