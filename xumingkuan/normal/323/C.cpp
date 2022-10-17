#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define BLOCKSIZE_DIV2 108
#define BLOCKSIZE 216
int n, m, a, b, c, d, a2, b2, c2, d2, p[1010101], q[1010101], p2[1010101], q2[1010101], f[4700][4700];
char input[25252525];
char *zz;
inline void inputnum(int &x)
{
	x = 0;
	while(*zz < '0' || *zz > '9')
		zz++;
	while(*zz >= '0' && *zz <= '9')
		x = x * 10 + *zz++ - '0';
}
int ans;
int main()
{
	fread(input, 1, 25252500, stdin);
	zz = input;
	inputnum(n);
	for(int i = 0; i < n; i++)
	{
		inputnum(p[i]);
		p2[--p[i]] = i;
	}
	for(int i = 0; i < n; i++)
	{
		inputnum(q[i]);
		q2[--q[i]] = i;
	}
	ans = n - 1;
	memset(f, 0, sizeof(f));
	for(int i = 0; i < n; i++)
		f[(i / BLOCKSIZE) + 1][((p[i] = q2[p[i]]) / BLOCKSIZE) + 1]++;
	for(int i = 1; i <= (n / BLOCKSIZE) + 2; i++)
		for(int j = 1; j <= (n / BLOCKSIZE) + 2; j++)
			f[i][j] += f[i][j - 1] + f[i - 1][j] - f[i - 1][j - 1];
	for(int i = 0; i < n; i++)
		q[p[i]] = i;
	for(int i = n; i <= n + 333; i++)
		p[i] = q[i] = -1;
	inputnum(m);
	for(int i = 1; i <= m; i++)
	{
		inputnum(a);
		inputnum(b);
		inputnum(c);
		inputnum(d);
		a = (a + ans) % n;
		b = (b + ans) % n;
		c = (c + ans) % n;
		d = (d + ans) % n;
		if(a > b)
			swap(a, b);
		if(c > d)
			swap(c, d);
		a2 = (a + BLOCKSIZE_DIV2) / BLOCKSIZE;
		b2 = (b + BLOCKSIZE_DIV2) / BLOCKSIZE;
		c2 = (c + BLOCKSIZE_DIV2) / BLOCKSIZE;
		d2 = (d + BLOCKSIZE_DIV2) / BLOCKSIZE;
		ans = f[b2][d2] - f[b2][c2] - f[a2][d2] + f[a2][c2];
		a2 *= BLOCKSIZE;
		b2 *= BLOCKSIZE;
		c2 *= BLOCKSIZE;
		d2 *= BLOCKSIZE;
		if(a2 < a)
		{
			for(int j = a2; j < a; j++)
				if(p[j] >= c && p[j] <= d)
					ans--;
		}
		else
		{
			for(int j = a; j < a2; j++)
				if(p[j] >= c && p[j] <= d)
					ans++;
		}
		if(b < b2)
		{
			for(int j = b + 1; j < b2; j++)
				if(p[j] >= c && p[j] <= d)
					ans--;
		}
		else
		{
			for(int j = b2; j <= b; j++)
				if(p[j] >= c && p[j] <= d)
					ans++;
		}
		if(c2 < c)
		{
			for(int j = c2; j < c; j++)
				if(q[j] >= a2 && q[j] < b2)
					ans--;
		}
		else
		{
			for(int j = c; j < c2; j++)
				if(q[j] >= a2 && q[j] < b2)
					ans++;
		}
		if(d < d2)
		{
			for(int j = d + 1; j < d2; j++)
				if(q[j] >= a2 && q[j] < b2)
					ans--;
		}
		else
		{
			for(int j = d2; j <= d; j++)
				if(q[j] >= a2 && q[j] < b2)
					ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}