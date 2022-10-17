#include <stdio.h>
#include <string.h>
#include <iostream>
int n;
char s[101010];
unsigned f[2][202020];
int main()
{
	scanf("%d\n", &n);
	fread(s + 1, n, 1, stdin);
	memset(f, 0, sizeof(f));
	unsigned *f1 = f[0] + 101010;
	unsigned *f2 = f[1] + 101010;
	f2[0] = 1;
	int l = 0;
	s[n + 1] = '?';
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		while(s[i] != '?')
			f2--, l++, i++;
		if(i > n)
			break;
		if(l > 0)
			l--;
		f1[l - 1] = 0;
		f1[l] = f2[l + 1];
		int r = (i < n - i ? i : n - i);
		for(int j = l + 1; j <= r; j++)
			f1[j] = f2[j - 1] + f2[j + 1];
		std::swap(f1, f2);
		cnt++;
	}
	for(int i = 1; i <= cnt - n / 2; i++)
		f2[0] *= 25;
	printf("%u\n", f2[0]);
	return 0;
}